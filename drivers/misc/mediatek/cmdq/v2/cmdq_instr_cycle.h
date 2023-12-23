// SPDX-License-Identifier: GPL-2.0
/*
 * Copyright (c) 2015 MediaTek Inc.
 */

/* id	HW_OP     MASK_EN     cycle   name */
DECLARE_CMDQ_INSTR_CYCLE(CMDQ_STA_WRI, CMDQ_CODE_WRITE, 4, WRI)
DECLARE_CMDQ_INSTR_CYCLE(CMDQ_STA_WRI_WITH_MASK, CMDQ_CODE_WRITE, 36,
			 WRI_W_MASK) /* 32 for read, 4 for write */
DECLARE_CMDQ_INSTR_CYCLE(CMDQ_STA_POLL, CMDQ_CODE_POLL, 32, POLL)
DECLARE_CMDQ_INSTR_CYCLE(CMDQ_STA_MOVE, CMDQ_CODE_MOVE, 1, MOVE)
DECLARE_CMDQ_INSTR_CYCLE(CMDQ_STA_READ, CMDQ_CODE_READ, 32, READ)
DECLARE_CMDQ_INSTR_CYCLE(CMDQ_STA_WFE, CMDQ_CODE_WFE, 3,
			 WAIT) /* need wait event */
DECLARE_CMDQ_INSTR_CYCLE(CMDQ_STA_SYNC, CMDQ_CODE_WFE, 3,
			 SYNC) /* no need wait event and update event */
DECLARE_CMDQ_INSTR_CYCLE(CMDQ_STA_JUMP, CMDQ_CODE_JUMP, 1, JUMP)
DECLARE_CMDQ_INSTR_CYCLE(CMDQ_STA_EOC, CMDQ_CODE_EOC, 1, MARKER)
