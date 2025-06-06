#if __WORDSIZE == 64
#define JIT_INSTR_MAX 168
    0,	/* data */
    0,	/* live */
    4,	/* align */
    0,	/* save */
    0,	/* load */
    0,	/* #name */
    0,	/* #note */
    0,	/* label */
    88,	/* prolog */
    0,	/* ellipsis */
    0,	/* va_push */
    0,	/* allocai */
    0,	/* allocar */
    0,	/* arg */
    0,	/* getarg_c */
    0,	/* getarg_uc */
    0,	/* getarg_s */
    0,	/* getarg_us */
    0,	/* getarg_i */
    0,	/* getarg_ui */
    0,	/* getarg_l */
    0,	/* putargr */
    0,	/* putargi */
    20,	/* va_start */
    24,	/* va_arg */
    44,	/* va_arg_d */
    0,	/* va_end */
    4,	/* addr */
    32,	/* addi */
    12,	/* addcr */
    40,	/* addci */
    28,	/* addxr */
    28,	/* addxi */
    4,	/* subr */
    32,	/* subi */
    12,	/* subcr */
    40,	/* subci */
    28,	/* subxr */
    28,	/* subxi */
    36,	/* rsbi */
    4,	/* mulr */
    32,	/* muli */
    44,	/* qmulr */
    56,	/* qmuli */
    12,	/* qmulr_u */
    32,	/* qmuli_u */
    44,	/* divr */
    68,	/* divi */
    44,	/* divr_u */
    68,	/* divi_u */
    52,	/* qdivr */
    52,	/* qdivi */
    52,	/* qdivr_u */
    52,	/* qdivi_u */
    44,	/* remr */
    68,	/* remi */
    44,	/* remr_u */
    68,	/* remi_u */
    4,	/* andr */
    32,	/* andi */
    4,	/* orr */
    32,	/* ori */
    4,	/* xorr */
    32,	/* xori */
    4,	/* lshr */
    4,	/* lshi */
    4,	/* rshr */
    4,	/* rshi */
    4,	/* rshr_u */
    4,	/* rshi_u */
    4,	/* negr */
    4,	/* comr */
    4,	/* ltr */
    4,	/* lti */
    4,	/* ltr_u */
    8,	/* lti_u */
    4,	/* ler */
    8,	/* lei */
    4,	/* ler_u */
    4,	/* lei_u */
    4,	/* eqr */
    4,	/* eqi */
    4,	/* ger */
    8,	/* gei */
    4,	/* ger_u */
    8,	/* gei_u */
    4,	/* gtr */
    8,	/* gti */
    4,	/* gtr_u */
    8,	/* gti_u */
    8,	/* ner */
    12,	/* nei */
    4,	/* movr */
    32,	/* movi */
    4,	/* movnr */
    4,	/* movzr */
    8,	/* extr_c */
    8,	/* extr_uc */
    8,	/* extr_s */
    8,	/* extr_us */
    8,	/* extr_i */
    8,	/* extr_ui */
    16,	/* htonr_us */
    36,	/* htonr_ui */
    36,	/* htonr_ul */
    12,	/* ldr_c */
    40,	/* ldi_c */
    4,	/* ldr_uc */
    32,	/* ldi_uc */
    12,	/* ldr_s */
    40,	/* ldi_s */
    4,	/* ldr_us */
    32,	/* ldi_us */
    4,	/* ldr_i */
    32,	/* ldi_i */
    12,	/* ldr_ui */
    40,	/* ldi_ui */
    4,	/* ldr_l */
    32,	/* ldi_l */
    16,	/* ldxr_c */
    44,	/* ldxi_c */
    8,	/* ldxr_uc */
    36,	/* ldxi_uc */
    16,	/* ldxr_s */
    44,	/* ldxi_s */
    8,	/* ldxr_us */
    36,	/* ldxi_us */
    8,	/* ldxr_i */
    36,	/* ldxi_i */
    16,	/* ldxr_ui */
    44,	/* ldxi_ui */
    8,	/* ldxr_l */
    36,	/* ldxi_l */
    4,	/* str_c */
    32,	/* sti_c */
    4,	/* str_s */
    32,	/* sti_s */
    4,	/* str_i */
    32,	/* sti_i */
    4,	/* str_l */
    32,	/* sti_l */
    8,	/* stxr_c */
    36,	/* stxi_c */
    8,	/* stxr_s */
    36,	/* stxi_s */
    8,	/* stxr_i */
    36,	/* stxi_i */
    8,	/* stxr_l */
    36,	/* stxi_l */
    8,	/* bltr */
    8,	/* blti */
    8,	/* bltr_u */
    12,	/* blti_u */
    8,	/* bler */
    12,	/* blei */
    8,	/* bler_u */
    12,	/* blei_u */
    8,	/* beqr */
    40,	/* beqi */
    8,	/* bger */
    12,	/* bgei */
    8,	/* bger_u */
    12,	/* bgei_u */
    8,	/* bgtr */
    12,	/* bgti */
    8,	/* bgtr_u */
    12,	/* bgti_u */
    8,	/* bner */
    36,	/* bnei */
    8,	/* bmsr */
    8,	/* bmsi */
    8,	/* bmcr */
    8,	/* bmci */
    28,	/* boaddr */
    32,	/* boaddi */
    16,	/* boaddr_u */
    16,	/* boaddi_u */
    28,	/* bxaddr */
    32,	/* bxaddi */
    16,	/* bxaddr_u */
    16,	/* bxaddi_u */
    28,	/* bosubr */
    32,	/* bosubi */
    16,	/* bosubr_u */
    16,	/* bosubi_u */
    28,	/* bxsubr */
    32,	/* bxsubi */
    16,	/* bxsubr_u */
    16,	/* bxsubi_u */
    4,	/* jmpr */
    36,	/* jmpi */
    8,	/* callr */
    36,	/* calli */
    0,	/* prepare */
    0,	/* pushargr */
    0,	/* pushargi */
    0,	/* finishr */
    0,	/* finishi */
    0,	/* ret */
    0,	/* retr */
    0,	/* reti */
    0,	/* retval_c */
    0,	/* retval_uc */
    0,	/* retval_s */
    0,	/* retval_us */
    0,	/* retval_i */
    0,	/* retval_ui */
    0,	/* retval_l */
    76,	/* epilog */
    0,	/* arg_f */
    0,	/* getarg_f */
    0,	/* putargr_f */
    0,	/* putargi_f */
    8,	/* addr_f */
    40,	/* addi_f */
    8,	/* subr_f */
    40,	/* subi_f */
    40,	/* rsbi_f */
    8,	/* mulr_f */
    40,	/* muli_f */
    8,	/* divr_f */
    40,	/* divi_f */
    4,	/* negr_f */
    4,	/* absr_f */
    8,	/* sqrtr_f */
    32,	/* ltr_f */
    64,	/* lti_f */
    32,	/* ler_f */
    64,	/* lei_f */
    32,	/* eqr_f */
    64,	/* eqi_f */
    32,	/* ger_f */
    64,	/* gei_f */
    32,	/* gtr_f */
    64,	/* gti_f */
    32,	/* ner_f */
    64,	/* nei_f */
    32,	/* unltr_f */
    64,	/* unlti_f */
    32,	/* unler_f */
    64,	/* unlei_f */
    32,	/* uneqr_f */
    64,	/* uneqi_f */
    32,	/* unger_f */
    64,	/* ungei_f */
    32,	/* ungtr_f */
    64,	/* ungti_f */
    32,	/* ltgtr_f */
    64,	/* ltgti_f */
    20,	/* ordr_f */
    52,	/* ordi_f */
    20,	/* unordr_f */
    52,	/* unordi_f */
    16,	/* truncr_f_i */
    16,	/* truncr_f_l */
    12,	/* extr_f */
    4,	/* extr_d_f */
    4,	/* movr_f */
    32,	/* movi_f */
    4,	/* ldr_f */
    32,	/* ldi_f */
    8,	/* ldxr_f */
    36,	/* ldxi_f */
    4,	/* str_f */
    32,	/* sti_f */
    8,	/* stxr_f */
    36,	/* stxi_f */
    24,	/* bltr_f */
    56,	/* blti_f */
    24,	/* bler_f */
    56,	/* blei_f */
    24,	/* beqr_f */
    56,	/* beqi_f */
    24,	/* bger_f */
    56,	/* bgei_f */
    24,	/* bgtr_f */
    56,	/* bgti_f */
    28,	/* bner_f */
    60,	/* bnei_f */
    28,	/* bunltr_f */
    60,	/* bunlti_f */
    28,	/* bunler_f */
    60,	/* bunlei_f */
    28,	/* buneqr_f */
    60,	/* buneqi_f */
    28,	/* bunger_f */
    60,	/* bungei_f */
    28,	/* bungtr_f */
    60,	/* bungti_f */
    28,	/* bltgtr_f */
    60,	/* bltgti_f */
    12,	/* bordr_f */
    44,	/* bordi_f */
    12,	/* bunordr_f */
    44,	/* bunordi_f */
    0,	/* pushargr_f */
    0,	/* pushargi_f */
    0,	/* retr_f */
    0,	/* reti_f */
    0,	/* retval_f */
    0,	/* arg_d */
    0,	/* getarg_d */
    0,	/* putargr_d */
    0,	/* putargi_d */
    8,	/* addr_d */
    40,	/* addi_d */
    8,	/* subr_d */
    40,	/* subi_d */
    40,	/* rsbi_d */
    8,	/* mulr_d */
    40,	/* muli_d */
    8,	/* divr_d */
    40,	/* divi_d */
    4,	/* negr_d */
    4,	/* absr_d */
    8,	/* sqrtr_d */
    32,	/* ltr_d */
    64,	/* lti_d */
    32,	/* ler_d */
    64,	/* lei_d */
    32,	/* eqr_d */
    64,	/* eqi_d */
    32,	/* ger_d */
    64,	/* gei_d */
    32,	/* gtr_d */
    64,	/* gti_d */
    32,	/* ner_d */
    64,	/* nei_d */
    32,	/* unltr_d */
    64,	/* unlti_d */
    32,	/* unler_d */
    64,	/* unlei_d */
    32,	/* uneqr_d */
    64,	/* uneqi_d */
    32,	/* unger_d */
    64,	/* ungei_d */
    32,	/* ungtr_d */
    64,	/* ungti_d */
    32,	/* ltgtr_d */
    64,	/* ltgti_d */
    20,	/* ordr_d */
    52,	/* ordi_d */
    20,	/* unordr_d */
    52,	/* unordi_d */
    16,	/* truncr_d_i */
    16,	/* truncr_d_l */
    12,	/* extr_d */
    4,	/* extr_f_d */
    4,	/* movr_d */
    32,	/* movi_d */
    4,	/* ldr_d */
    32,	/* ldi_d */
    8,	/* ldxr_d */
    36,	/* ldxi_d */
    4,	/* str_d */
    32,	/* sti_d */
    8,	/* stxr_d */
    36,	/* stxi_d */
    24,	/* bltr_d */
    56,	/* blti_d */
    24,	/* bler_d */
    56,	/* blei_d */
    24,	/* beqr_d */
    56,	/* beqi_d */
    24,	/* bger_d */
    56,	/* bgei_d */
    24,	/* bgtr_d */
    56,	/* bgti_d */
    28,	/* bner_d */
    60,	/* bnei_d */
    28,	/* bunltr_d */
    60,	/* bunlti_d */
    28,	/* bunler_d */
    60,	/* bunlei_d */
    28,	/* buneqr_d */
    60,	/* buneqi_d */
    28,	/* bunger_d */
    60,	/* bungei_d */
    28,	/* bungtr_d */
    60,	/* bungti_d */
    28,	/* bltgtr_d */
    60,	/* bltgti_d */
    12,	/* bordr_d */
    44,	/* bordi_d */
    12,	/* bunordr_d */
    44,	/* bunordi_d */
    0,	/* pushargr_d */
    0,	/* pushargi_d */
    0,	/* retr_d */
    0,	/* reti_d */
    0,	/* retval_d */
    0,	/* movr_w_f */
    0,	/* movr_ww_d */
    0,	/* movr_w_d */
    0,	/* movr_f_w */
    0,	/* movi_f_w */
    0,	/* movr_d_ww */
    0,	/* movi_d_ww */
    0,	/* movr_d_w */
    0,	/* movi_d_w */
    16,	/* bswapr_us */
    36,	/* bswapr_ui */
    36,	/* bswapr_ul */
    32,	/* casr */
    60,	/* casi */
#endif /* __WORDSIZE */
