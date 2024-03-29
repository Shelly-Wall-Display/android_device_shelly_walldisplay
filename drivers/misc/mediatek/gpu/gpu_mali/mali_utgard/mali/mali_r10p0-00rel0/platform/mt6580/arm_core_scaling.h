/*
 * Copyright (C) 2010, 2012-2016 ARM Limited. All rights reserved.
 *
 * This program is free software and is provided to you under the terms of the GNU General Public License version 2
 * as published by the Free Software Foundation, and any use by you of this program is subject to the terms of such GNU licence.
 *
 *
 *
 */


/**
 * @file arm_core_scaling.h
 * Example core scaling policy.
 */

#ifndef __ARM_CORE_SCALING_H__
#define __ARM_CORE_SCALING_H__
//#error "IO_VIRT_TO_PHYS define there"
struct mali_gpu_utilization_data;

/**
 * Initialize core scaling policy.
 *
 * @note The core scaling policy will assume that all PP cores are on initially.
 *
 * @param num_pp_cores Total number of PP cores.
 */
void mali_core_scaling_init(int num_pp_cores);

/**
 * Terminate core scaling policy.
 */
void mali_core_scaling_term(void);

/**
 * Update core scaling policy with new utilization data.
 *
 * @param data Utilization data.
 */
void mali_core_scaling_update(struct mali_gpu_utilization_data *data);

void mali_core_scaling_sync(int num_cores);

#endif /* __ARM_CORE_SCALING_H__ */
