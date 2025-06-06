/***************************************************************************
 *   Copyright (C) 2007 Ryan Schultz, PCSX-df Team, PCSX team              *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA 02111-1307 USA.           *
 ***************************************************************************/

/*
* Handles PSX DMA functions.
*/

#include "psxdma.h"
#include "gpu.h"

// Dma0/1 in Mdec.c
// Dma3   in CdRom.c

void spuInterrupt() {
	if (HW_DMA4_CHCR & SWAP32(0x01000000))
	{
		HW_DMA4_CHCR &= SWAP32(~0x01000000);
		DMA_INTERRUPT(4);
	}
}

void psxDma4(u32 madr, u32 bcr, u32 chcr) { // SPU
	u16 *ptr;
	u32 words;

	switch (chcr) {
		case 0x01000201: //cpu to spu transfer
#ifdef PSXDMA_LOG
			PSXDMA_LOG("*** DMA4 SPU - mem2spu *** %x addr = %x size = %x\n", chcr, madr, bcr);
#endif
			ptr = (u16 *)PSXM(madr);
			if (ptr == INVALID_PTR) {
#ifdef CPU_LOG
				CPU_LOG("*** DMA4 SPU - mem2spu *** NULL Pointer!!!\n");
#endif
				break;
			}
			words = (bcr >> 16) * (bcr & 0xffff);
			SPU_writeDMAMem(ptr, words * 2, psxRegs.cycle);
			HW_DMA4_MADR = SWAPu32(madr + words * 4);
			SPUDMA_INT(words * 4);
			return;

		case 0x01000200: //spu to cpu transfer
#ifdef PSXDMA_LOG
			PSXDMA_LOG("*** DMA4 SPU - spu2mem *** %x addr = %x size = %x\n", chcr, madr, bcr);
#endif
			ptr = (u16 *)PSXM(madr);
			if (ptr == INVALID_PTR) {
#ifdef CPU_LOG
				CPU_LOG("*** DMA4 SPU - spu2mem *** NULL Pointer!!!\n");
#endif
				break;
			}
			words = (bcr >> 16) * (bcr & 0xffff);
			SPU_readDMAMem(ptr, words * 2, psxRegs.cycle);
			psxCpu->Clear(madr, words);

			HW_DMA4_MADR = SWAPu32(madr + words * 4);
			SPUDMA_INT(words * 4);
			return;

		default:
			log_unhandled("*** DMA4 SPU - unknown *** %x addr = %x size = %x\n", chcr, madr, bcr);
			break;
	}

	HW_DMA4_CHCR &= SWAP32(~0x01000000);
	DMA_INTERRUPT(4);
}

// Taken from PEOPS SOFTGPU
static inline boolean CheckForEndlessLoop(u32 laddr, u32 *lUsedAddr) {
	if (laddr == lUsedAddr[1]) return TRUE;
	if (laddr == lUsedAddr[2]) return TRUE;

	if (laddr < lUsedAddr[0]) lUsedAddr[1] = laddr;
	else lUsedAddr[2] = laddr;

	lUsedAddr[0] = laddr;

	return FALSE;
}

static u32 gpuDmaChainSize(u32 addr) {
	u32 size;
	u32 DMACommandCounter = 0;
	u32 lUsedAddr[3];

	lUsedAddr[0] = lUsedAddr[1] = lUsedAddr[2] = 0xffffff;

	// initial linked list ptr (word)
	size = 1;

	do {
		addr &= 0x1ffffc;

		if (DMACommandCounter++ > 2000000) break;
		if (CheckForEndlessLoop(addr, lUsedAddr)) break;

		// # 32-bit blocks to transfer
		size += psxMu8( addr + 3 );

		// next 32-bit pointer
		addr = psxMu32( addr & ~0x3 ) & 0xffffff;
		size += 1;
	} while (!(addr & 0x800000)); // contrary to some documentation, the end-of-linked-list marker is not actually 0xFF'FFFF
                                  // any pointer with bit 23 set will do.

	return size;
}

void psxDma2(u32 madr, u32 bcr, u32 chcr) { // GPU
	u32 *ptr, madr_next, *madr_next_p;
	int do_walking;
	u32 words;
	u32 size;

	switch (chcr) {
		case 0x01000200: // vram2mem
#ifdef PSXDMA_LOG
			PSXDMA_LOG("*** DMA2 GPU - vram2mem *** %lx addr = %lx size = %lx\n", chcr, madr, bcr);
#endif
			ptr = (u32 *)PSXM(madr);
			if (ptr == INVALID_PTR) {
#ifdef CPU_LOG
				CPU_LOG("*** DMA2 GPU - vram2mem *** NULL Pointer!!!\n");
#endif
				break;
			}
			// BA blocks * BS words (word = 32-bits)
			words = (bcr >> 16) * (bcr & 0xffff);
			GPU_readDataMem(ptr, words);
			psxCpu->Clear(madr, words);

			HW_DMA2_MADR = SWAPu32(madr + words * 4);

			// already 32-bit word size ((size * 4) / 4)
			GPUDMA_INT(words / 4);
			return;

		case 0x01000201: // mem2vram
#ifdef PSXDMA_LOG
			PSXDMA_LOG("*** DMA 2 - GPU mem2vram *** %lx addr = %lx size = %lx\n", chcr, madr, bcr);
#endif
			ptr = (u32 *)PSXM(madr);
			if (ptr == INVALID_PTR) {
#ifdef CPU_LOG
				CPU_LOG("*** DMA2 GPU - mem2vram *** NULL Pointer!!!\n");
#endif
				break;
			}
			// BA blocks * BS words (word = 32-bits)
			words = (bcr >> 16) * (bcr & 0xffff);
			GPU_writeDataMem(ptr, words);

			HW_DMA2_MADR = SWAPu32(madr + words * 4);

			// already 32-bit word size ((size * 4) / 4)
			GPUDMA_INT(words / 4);
			return;

		case 0x01000401: // dma chain
#ifdef PSXDMA_LOG
			PSXDMA_LOG("*** DMA 2 - GPU dma chain *** %lx addr = %lx size = %lx\n", chcr, madr, bcr);
#endif
			// when not emulating walking progress, end immediately
			madr_next = 0xffffff;

			do_walking = Config.GpuListWalking;
			if (do_walking < 0)
				do_walking = Config.hacks.gpu_slow_list_walking;
			madr_next_p = do_walking ? &madr_next : NULL;

			size = GPU_dmaChain((u32 *)psxM, madr & 0x1fffff, madr_next_p);
			if ((int)size <= 0)
				size = gpuDmaChainSize(madr);

			HW_GPU_STATUS &= SWAP32(~PSXGPU_nBUSY);
			HW_DMA2_MADR = SWAPu32(madr_next);

			// Tekken 3 = use 1.0 only (not 1.5x)

			// Einhander = parse linked list in pieces (todo)
			// Rebel Assault 2 = parse linked list in pieces (todo)
			GPUDMA_INT(size);
			return;

		default:
			log_unhandled("*** DMA 2 - GPU unknown *** %x addr = %x size = %x\n", chcr, madr, bcr);
			break;
	}

	HW_DMA2_CHCR &= SWAP32(~0x01000000);
	DMA_INTERRUPT(2);
}

void gpuInterrupt() {
	if (HW_DMA2_CHCR == SWAP32(0x01000401) && !(HW_DMA2_MADR & SWAP32(0x800000)))
	{
		u32 size, madr_next = 0xffffff;
		size = GPU_dmaChain((u32 *)psxM, HW_DMA2_MADR & 0x1fffff, &madr_next);
		HW_DMA2_MADR = SWAPu32(madr_next);
		GPUDMA_INT(size);
		return;
	}
	if (HW_DMA2_CHCR & SWAP32(0x01000000))
	{
		HW_DMA2_CHCR &= SWAP32(~0x01000000);
		DMA_INTERRUPT(2);
	}
	HW_GPU_STATUS |= SWAP32(PSXGPU_nBUSY); // GPU no longer busy
}

void psxDma6(u32 madr, u32 bcr, u32 chcr) {
	u32 words;
	u32 *mem = (u32 *)PSXM(madr);

#ifdef PSXDMA_LOG
	PSXDMA_LOG("*** DMA6 OT *** %x addr = %x size = %x\n", chcr, madr, bcr);
#endif

	if (chcr == 0x11000002) {
		if (mem == INVALID_PTR) {
#ifdef CPU_LOG
			CPU_LOG("*** DMA6 OT *** NULL Pointer!!!\n");
#endif
			HW_DMA6_CHCR &= SWAP32(~0x01000000);
			DMA_INTERRUPT(6);
			return;
		}

		// already 32-bit size
		words = bcr;

		while (bcr--) {
			*mem-- = SWAP32((madr - 4) & 0xffffff);
			madr -= 4;
		}
		*++mem = SWAP32(0xffffff);

		//GPUOTCDMA_INT(size);
		// halted
		psxRegs.cycle += words;
		GPUOTCDMA_INT(16);
		return;
	}
	else {
		// Unknown option
		log_unhandled("*** DMA6 OT - unknown *** %x addr = %x size = %x\n", chcr, madr, bcr);
	}

	HW_DMA6_CHCR &= SWAP32(~0x01000000);
	DMA_INTERRUPT(6);
}

void gpuotcInterrupt()
{
	if (HW_DMA6_CHCR & SWAP32(0x01000000))
	{
		HW_DMA6_CHCR &= SWAP32(~0x01000000);
		DMA_INTERRUPT(6);
	}
}
