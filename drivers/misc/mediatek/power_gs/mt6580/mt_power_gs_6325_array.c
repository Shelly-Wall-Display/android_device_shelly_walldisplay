/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (C) 2020 MediaTek Inc.
 */

/* This file is generated by GenLP_setting.pl v1.4 */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

const unsigned int MT6325_PMIC_REG_gs_flightmode_suspend_mode_data[] = {
/* Address     Mask        Golden Setting Value */
	0x001E, 0x0800, 0x0000, /* "STRUP_CON16" */
	0x0204, 0x0000, 0x0030, /* "TOP_CON" */
	0x0238, 0x0000, 0xFEFC, /* "TOP_CKPDN_CON0" */
	0x023E, 0x0000, 0x00AC, /* "TOP_CKPDN_CON1" */
	0x0244, 0x0000, 0x7773, /* "TOP_CKPDN_CON2" */
	0x024A, 0x0000, 0x05E0, /* "TOP_CKPDN_CON3" */
	0x0250, 0x0000, 0x8000, /* "TOP_CKSEL_CON0" */
	0x0268, 0x0000, 0x06FF, /* "TOP_CKHWEN_CON" */
	0x0274, 0x0239, 0x0000, /* "TOP_CLKSQ" */
	0x027A, 0x0000, 0x0002, /* "TOP_CLKSQ_RTC" */
	0x02B6, 0x8000, 0x0000, /* "FQMTR_CON0" */
	0x04B0, 0x0000, 0x0002, /* "VDVFS11_CON7" */
	0x04B4, 0x0001, 0x0000, /* "VDVFS11_CON9" */
	0x04C6, 0x0100, 0x0000, /* "VDVFS11_CON18" */
	0x04D6, 0x0001, 0x0000, /* "VDVFS12_CON7" */
	0x04EC, 0x0100, 0x0000, /* "VDVFS12_CON18" */
	0x0522, 0x0001, 0x0000, /* "VDRAM_CON7" */
	0x0526, 0x0000, 0x0001, /* "VDRAM_CON9" */
	0x0538, 0x0000, 0x0100, /* "VDRAM_CON18" */
	0x0548, 0x0000, 0x0001, /* "VRF18_0_CON7" */
	0x054A, 0x0000, 0x0001, /* "VRF18_0_CON8" */
	0x055E, 0x0100, 0x0000, /* "VRF18_0_CON18" */
	0x060E, 0x0001, 0x0000, /* "VGPU_CON7" */
	0x0624, 0x0100, 0x0000, /* "VGPU_CON18" */
	0x0634, 0x0001, 0x0000, /* "VCORE1_CON7" */
	0x065A, 0x0000, 0x0002, /* "VCORE2_CON7" */
	0x065E, 0x0000, 0x0001, /* "VCORE2_CON9" */
	0x0670, 0x0000, 0x0100, /* "VCORE2_CON18" */
	0x0684, 0x0001, 0x0000, /* "VIO18_CON7" */
	0x0688, 0x0000, 0x0001, /* "VIO18_CON9" */
	0x069A, 0x0000, 0x0100, /* "VIO18_CON18" */
	0x06AA, 0x0003, 0x0000, /* "VPA_CON7" */
	0x06AE, 0x0001, 0x0000, /* "VPA_CON9" */
	0x0834, 0x000F, 0x0000, /* "ISINK_EN_CTRL" */
	0x0A00, 0x0000, 0x0008, /* "LDO_CON0" */
	0x0A02, 0x000F, 0x0000, /* "LDO_CON1" */
	0x0A04, 0x000F, 0x0000, /* "LDO_CON2" */
	0x0A06, 0x0000, 0x0006, /* "LDO_CON3" */
	0x0A08, 0x0000, 0x0008, /* "LDO_CON4" */
	0x0A0A, 0x0002, 0x0000, /* "LDO_CON5" */
	0x0A0C, 0x000F, 0x0000, /* "LDO_CON6" */
	0x0A0E, 0x000F, 0x0000, /* "LDO_CON7" */
	0x0A10, 0x000F, 0x0000, /* "LDO_CON8" */
	0x0A12, 0x0000, 0x0006, /* "LDO_CON9" */
	0x0A14, 0x000F, 0x0000, /* "LDO_CON10" */
	0x0A16, 0x000F, 0x0000, /* "LDO_CON11" */
	0x0A18, 0x0000, 0x0004, /* "LDO_CON12" */
	0x0A1A, 0x0000, 0x0006, /* "LDO_CON13" */
	0x0A1C, 0x000F, 0x0000, /* "LDO_CON14" */
	0x0A1E, 0x000F, 0x0000, /* "LDO_CON15" */
	0x0A20, 0x000F, 0x0000, /* "LDO_CON16" */
	0x0A22, 0x000F, 0x0000, /* "LDO_CON17" */
	0x0A24, 0x000F, 0x0000, /* "LDO_CON18" */
	0x0A26, 0x000F, 0x0000, /* "LDO_CON19" */
	0x0A28, 0x0002, 0x0000, /* "LDO_CON20" */
	0x0A2A, 0x000F, 0x0000, /* "LDO_CON21" */
	0x0A2E, 0x000D, 0x0000, /* "LDO_CON23" */
	0x0A30, 0x000F, 0x0000, /* "LDO_CON24" */
	0x0A32, 0x000F, 0x0000, /* "LDO_CON25" */
	0x0A34, 0x000D, 0x0000, /* "LDO_CON26" */
	0x0A36, 0x000F, 0x0000, /* "LDO_CON27" */
	0x0A38, 0x000F, 0x0000, /* "LDO_CON28" */
	0x0A94, 0x0001, 0x0000, /* "BIF_CON18" */
	0x0AC2, 0x0001, 0x0000, /* "SPK_CON0" */
	0x0CEE, 0x0000, 0x0002, /* "AUDDEC_ANA_CON8" */
	0x0EBC, 0x0000, 0x8000, /* "AUXADC_CON26" */
	0x0EBE, 0x0000, 0x8000, /* "AUXADC_CON27" */
	0x0EC2, 0x0001, 0x0000, /* "ACCDET_CON1" */
};

const unsigned int *MT6325_PMIC_REG_gs_flightmode_suspend_mode = MT6325_PMIC_REG_gs_flightmode_suspend_mode_data;

unsigned int MT6325_PMIC_REG_gs_flightmode_suspend_mode_len = 204;
