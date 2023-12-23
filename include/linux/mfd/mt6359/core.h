/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) 2019 MediaTek Inc.
 */

#ifndef __MFD_MT6359_CORE_H__
#define __MFD_MT6359_CORE_H__

#define MT6359_REG_WIDTH 16

enum mt6359_irq_top_status_shift {
	MT6359_BUCK_TOP = 0,
	MT6359_LDO_TOP = 1,
	MT6359_PSC_TOP = 2,
	MT6359_SCK_TOP = 3,
	MT6359_BM_TOP = 4,
	MT6359_HK_TOP = 5,
	MT6359_AUD_TOP = 7,
	MT6359_MISC_TOP = 8,
};

enum mt6359_irq_numbers {
	MT6359_IRQ_VPU_OC = 0,
	MT6359_IRQ_VCORE_OC = 1,
	MT6359_IRQ_VGPU11_OC = 2,
	MT6359_IRQ_VGPU12_OC = 3,
	MT6359_IRQ_VMODEM_OC = 4,
	MT6359_IRQ_VPROC1_OC = 5,
	MT6359_IRQ_VPROC2_OC = 6,
	MT6359_IRQ_VS1_OC = 7,
	MT6359_IRQ_VS2_OC = 8,
	MT6359_IRQ_VPA_OC = 9,
	MT6359_IRQ_VFE28_OC = 16,
	MT6359_IRQ_VXO22_OC = 17,
	MT6359_IRQ_VRF18_OC = 18,
	MT6359_IRQ_VRF12_OC = 19,
	MT6359_IRQ_VEFUSE_OC = 20,
	MT6359_IRQ_VCN33_1_OC = 21,
	MT6359_IRQ_VCN33_2_OC = 22,
	MT6359_IRQ_VCN13_OC = 23,
	MT6359_IRQ_VCN18_OC = 24,
	MT6359_IRQ_VA09_OC = 25,
	MT6359_IRQ_VCAMIO_OC = 26,
	MT6359_IRQ_VA12_OC = 27,
	MT6359_IRQ_VAUX18_OC = 28,
	MT6359_IRQ_VAUD18_OC = 29,
	MT6359_IRQ_VIO18_OC = 30,
	MT6359_IRQ_VSRAM_PROC1_OC = 31,
	MT6359_IRQ_VSRAM_PROC2_OC = 32,
	MT6359_IRQ_VSRAM_OTHERS_OC = 33,
	MT6359_IRQ_VSRAM_MD_OC = 34,
	MT6359_IRQ_VEMC_OC = 35,
	MT6359_IRQ_VSIM1_OC = 36,
	MT6359_IRQ_VSIM2_OC = 37,
	MT6359_IRQ_VUSB_OC = 38,
	MT6359_IRQ_VRFCK_OC = 39,
	MT6359_IRQ_VBBCK_OC = 40,
	MT6359_IRQ_VBIF28_OC = 41,
	MT6359_IRQ_VIBR_OC = 42,
	MT6359_IRQ_VIO28_OC = 43,
	MT6359_IRQ_VM18_OC = 44,
	MT6359_IRQ_VUFS_OC = 45,
	MT6359_IRQ_PWRKEY = 48,
	MT6359_IRQ_HOMEKEY = 49,
	MT6359_IRQ_PWRKEY_R = 50,
	MT6359_IRQ_HOMEKEY_R = 51,
	MT6359_IRQ_NI_LBAT_INT = 52,
	MT6359_IRQ_CHRDET_EDGE = 53,
	MT6359_IRQ_RTC = 64,
	MT6359_IRQ_FG_BAT_H = 80,
	MT6359_IRQ_FG_BAT_L = 81,
	MT6359_IRQ_FG_CUR_H = 82,
	MT6359_IRQ_FG_CUR_L = 83,
	MT6359_IRQ_FG_ZCV = 84,
	MT6359_IRQ_FG_N_CHARGE_L = 87,
	MT6359_IRQ_FG_IAVG_H = 88,
	MT6359_IRQ_FG_IAVG_L = 89,
	MT6359_IRQ_FG_DISCHARGE = 91,
	MT6359_IRQ_FG_CHARGE = 92,
	MT6359_IRQ_BATON_LV = 96,
	MT6359_IRQ_BATON_BAT_IN = 98,
	MT6359_IRQ_BATON_BAT_OUT = 99,
	MT6359_IRQ_BIF = 100,
	MT6359_IRQ_BAT_H = 112,
	MT6359_IRQ_BAT_L = 113,
	MT6359_IRQ_BAT2_H = 114,
	MT6359_IRQ_BAT2_L = 115,
	MT6359_IRQ_BAT_TEMP_H = 116,
	MT6359_IRQ_BAT_TEMP_L = 117,
	MT6359_IRQ_THR_H = 118,
	MT6359_IRQ_THR_L = 119,
	MT6359_IRQ_AUXADC_IMP = 120,
	MT6359_IRQ_NAG_C_DLTV = 121,
	MT6359_IRQ_AUDIO = 128,
	MT6359_IRQ_ACCDET = 133,
	MT6359_IRQ_ACCDET_EINT0 = 134,
	MT6359_IRQ_ACCDET_EINT1 = 135,
	MT6359_IRQ_SPI_CMD_ALERT = 144,
	MT6359_IRQ_NR = 145,
};

#define MT6359_IRQ_BUCK_BASE MT6359_IRQ_VPU_OC
#define MT6359_IRQ_LDO_BASE MT6359_IRQ_VFE28_OC
#define MT6359_IRQ_PSC_BASE MT6359_IRQ_PWRKEY
#define MT6359_IRQ_SCK_BASE MT6359_IRQ_RTC
#define MT6359_IRQ_BM_BASE MT6359_IRQ_FG_BAT_H
#define MT6359_IRQ_HK_BASE MT6359_IRQ_BAT_H
#define MT6359_IRQ_AUD_BASE MT6359_IRQ_AUDIO
#define MT6359_IRQ_MISC_BASE MT6359_IRQ_SPI_CMD_ALERT

#define MT6359_IRQ_BUCK_BITS \
	(MT6359_IRQ_VPA_OC - MT6359_IRQ_BUCK_BASE)
#define MT6359_IRQ_LDO_BITS \
	(MT6359_IRQ_VUFS_OC - MT6359_IRQ_LDO_BASE)
#define MT6359_IRQ_PSC_BITS \
	(MT6359_IRQ_CHRDET_EDGE - MT6359_IRQ_PSC_BASE)
#define MT6359_IRQ_SCK_BITS \
	(MT6359_IRQ_RTC - MT6359_IRQ_SCK_BASE)
#define MT6359_IRQ_BM_BITS \
	(MT6359_IRQ_BIF - MT6359_IRQ_BM_BASE)
#define MT6359_IRQ_HK_BITS \
	(MT6359_IRQ_NAG_C_DLTV - MT6359_IRQ_HK_BASE)
#define MT6359_IRQ_AUD_BITS \
	(MT6359_IRQ_ACCDET_EINT1 - MT6359_IRQ_AUD_BASE)
#define MT6359_IRQ_MISC_BITS \
	(MT6359_IRQ_SPI_CMD_ALERT - MT6359_IRQ_MISC_BASE)

#define MT6359_TOP_GEN(sp)	\
{	\
	.hwirq_base = MT6359_IRQ_##sp##_BASE,	\
	.num_int_regs =	\
		(MT6359_IRQ_##sp##_BITS / MT6359_REG_WIDTH) + 1,	\
	.en_reg = MT6359_##sp##_TOP_INT_CON0,		\
	.en_reg_shift = 0x6,	\
	.sta_reg = MT6359_##sp##_TOP_INT_STATUS0,		\
	.sta_reg_shift = 0x2,	\
	.top_offset = MT6359_##sp##_TOP,	\
}

#endif /* __MFD_MT6359_CORE_H__ */
