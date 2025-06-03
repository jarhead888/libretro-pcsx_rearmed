################################################################################
#
# PCSX_REARMED
#
################################################################################
PCSX_REARMED_DEPENDENCIES = retroarch
PCSX_REARMED_DIR=$(BUILD_DIR)/libretro-pcsx_rearmed

$(PCSX_REARMED_DIR)/.source:
	mkdir -pv $(PCSX_REARMED_DIR)
	cp -raf package/libretro-pcsx_rearmed/src/* $(PCSX_REARMED_DIR)
	touch $@

$(PCSX_REARMED_DIR)/.configured : $(PCSX_REARMED_DIR)/.source
	touch $@

libretro-pcsx_rearmed-binary: $(PCSX_REARMED_DIR)/.configured $(PCSX_REARMED_DEPENDENCIES)
	BASE_DIR="$(BASE_DIR)" CFLAGS="$(TARGET_CFLAGS) -I${STAGING_DIR}/usr/include/ -I$(PCSX_REARMED_DIR)/" CXXFLAGS="$(TARGET_CXXFLAGS)" LDFLAGS="$(TARGET_LDFLAGS)" CC="$(TARGET_CC)" CXX="$(TARGET_CXX)" $(MAKE) -C $(PCSX_REARMED_DIR)/ -f Makefile.libretro platform="allwinner-h6"

libretro-pcsx_rearmed: libretro-pcsx_rearmed-binary
	mkdir -p $(TARGET_DIR)/usr/lib/libretro
	cp -raf $(PCSX_REARMED_DIR)/pcsx_rearmed_libretro.so $(TARGET_DIR)/usr/lib/libretro/pcsx_rearmed_libretro.so
	$(TARGET_STRIP) $(TARGET_DIR)/usr/lib/libretro/pcsx_rearmed_libretro.so

ifeq ($(BR2_PACKAGE_LIBRETRO_PCSX_REARMED), y)
TARGETS += libretro-pcsx_rearmed
endif
