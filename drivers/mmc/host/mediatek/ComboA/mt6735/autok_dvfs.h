// SPDX-License-Identifier: GPL-2.0
/*
* Copyright (C) 2019  MediaTek Inc.
*
*/

#ifndef _AUTOK_DVFS_H_
#define _AUTOK_DVFS_H_
#include "msdc_cust.h"
#include "autok.h"

#define VCOREFS_READY

#if defined(VCOREFS_READY)
#include <linux/pm_qos.h>
#include "mt_vcore_dvfs.h"
#include <mach/mtk_pmic_wrap.h>
#endif

enum AUTOK_VCORE {
	AUTOK_VCORE_LEVEL0 = 0,
	AUTOK_VCORE_LEVEL1,
	AUTOK_VCORE_LEVEL2,
	AUTOK_VCORE_MERGE,
	AUTOK_VCORE_NUM = AUTOK_VCORE_MERGE
};

#define MSDC_DVFS_TIMEOUT       (HZ/100 * 5)     /* 10ms x5 */

#define MSDC_DVFS_SET_SIZE      0x48
#define MSDC_TOP_SET_SIZE       0x30
#define SDIO_DVFS_TIMEOUT       (HZ/100 * 5)    /* 10ms x5 */
/* Enable later@Peter */
/* #define SDIO_HW_DVFS_CONDITIONAL */

/**********************************************************
 * Function Declaration                                   *
 **********************************************************/
extern int sdio_autok_res_apply(struct msdc_host *host, int vcore);
extern int sdio_autok_res_save(struct msdc_host *host, int vcore, u8 *res);

extern int emmc_execute_dvfs_autok(struct msdc_host *host, u32 opcode);
extern int sd_execute_dvfs_autok(struct msdc_host *host, u32 opcode);
extern void sdio_execute_dvfs_autok(struct msdc_host *host);

extern void sdio_dvfs_reg_restore(struct msdc_host *host);
extern void msdc_dump_autok(char **buff, unsigned long *size,
	struct seq_file *m, struct msdc_host *host);
extern void msdc_dvfs_reg_backup_init(struct msdc_host *host);
extern void msdc_dvfs_reg_restore(struct msdc_host *host);
#ifdef EMMC_RUNTIME_AUTOK_MERGE
extern int emmc_runtime_autok_merge(u32 opcode);
#endif

#endif /* _AUTOK_DVFS_H_ */

