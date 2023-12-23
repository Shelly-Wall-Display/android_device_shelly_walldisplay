// SPDX-License-Identifier: GPL-2.0
/*
* Copyright (C) 2018 MediaTek Inc.
*
*/

#ifndef __COMPAT_MTK_DISP_MGR_H
#define __COMPAT_MTK_DISP_MGR_H
#include <linux/uaccess.h>
#include <linux/compat.h>

#include "mtk_disp_mgr.h"
#include "disp_session.h"


#ifdef CONFIG_COMPAT

/* /============================================================================= */
/* structure declarations */
/* /=========================== */

typedef struct compat_disp_session_config_t {
	compat_uint_t type;
	compat_uint_t device_id;
	compat_uint_t mode;
	compat_uint_t session_id;
	compat_uint_t user;
	compat_uint_t present_fence_idx;
	compat_uint_t dc_type;
	compat_int_t need_merge;
	compat_uint_t tigger_mode;
} compat_disp_session_config;

typedef struct {
	compat_uint_t session_id;
	compat_uint_t vsync_cnt;
	compat_u64 vsync_ts;
	compat_int_t lcm_fps;
} compat_disp_session_vsync_config;

struct compat_layer_dirty_roi {
	compat_ushort_t dirty_x;
	compat_ushort_t dirty_y;
	compat_ushort_t dirty_w;
	compat_ushort_t dirty_h;
};

typedef struct compat_disp_input_config_t {
	compat_uptr_t src_base_addr;
	compat_uptr_t src_phy_addr;
	compat_uint_t buffer_source;
	compat_uint_t security;
	compat_uint_t src_fmt;
	compat_uint_t src_alpha;
	compat_uint_t dst_alpha;
	compat_uint_t yuv_range;

	compat_uint_t layer_rotation;
	compat_uint_t layer_type;
	compat_uint_t video_rotation;

	compat_uint_t next_buff_idx;
	compat_uint_t src_fence_fd;	/* fence to be waited before using this buffer. -1 if invalid */
	compat_uptr_t src_fence_struct;	/* fence struct of src_fence_fd, used in kernel */

	compat_uint_t src_color_key;
	compat_uint_t frm_sequence;

	compat_uptr_t dirty_roi_addr;
	compat_ushort_t dirty_roi_num;

	compat_ushort_t src_pitch;
	compat_ushort_t src_offset_x, src_offset_y;
	compat_ushort_t src_width, src_height;
	compat_ushort_t tgt_offset_x, tgt_offset_y;
	compat_ushort_t tgt_width, tgt_height;

	u8 alpha_enable;
	u8 alpha;
	u8 sur_aen;
	u8 src_use_color_key;
	u8 layer_id;
	u8 layer_enable;
	u8 src_direct_link;

	u8 isTdshp;
	u8 identity;
	u8 connected_type;
	u8 ext_sel_layer;
} compat_disp_input_config;

typedef struct compat_disp_output_config_t {
	compat_uptr_t va;
	compat_uptr_t pa;
	compat_uint_t fmt;
	compat_uint_t x;
	compat_uint_t y;
	compat_uint_t width;
	compat_uint_t height;
	compat_uint_t pitch;
	compat_uint_t pitchUV;
	compat_uint_t security;
	compat_uint_t buff_idx;
	compat_uint_t interface_idx;
	compat_uint_t src_fence_fd;	/* fence to be waited before using this buffer. -1 if invalid */
	compat_uptr_t src_fence_struct;	/* fence struct of src_fence_fd, used in kernel */
	compat_uint_t frm_sequence;
} compat_disp_output_config;

typedef struct compat_disp_session_input_config_t {
	compat_uint_t setter;
	compat_uint_t session_id;
	compat_uint_t config_layer_num;
	compat_disp_input_config config[12];
} compat_disp_session_input_config;

typedef struct compat_disp_session_output_config_t {
	compat_uint_t session_id;
	compat_disp_output_config config;
} compat_disp_session_output_config;

typedef struct compat_disp_session_layer_num_config_t {
	compat_uint_t session_id;
	compat_uint_t max_layer_num;
} compat_disp_session_layer_num_config;

struct compat_disp_frame_cfg_t {
	compat_uint_t setter;
	compat_uint_t session_id;

	/* input config */
	compat_uint_t input_layer_num;
	compat_disp_input_config input_cfg[12];
	compat_uint_t overlap_layer_num;

	/* constant layer */
	compat_uint_t const_layer_num;
	compat_disp_input_config const_layer[1];

	/* output config */
	compat_int_t output_en;
	compat_disp_output_config output_cfg;

	/* trigger config */
	compat_uint_t mode;
	compat_uint_t present_fence_idx;
	compat_uint_t prev_present_fence_fd;
	compat_uptr_t prev_present_fence_struct;
	compat_uint_t tigger_mode;
	compat_uint_t user;
};

typedef struct compat_disp_session_info_t {
	compat_uint_t session_id;
	compat_uint_t maxLayerNum;
	compat_uint_t isHwVsyncAvailable;
	compat_uint_t displayType;
	compat_uint_t displayWidth;
	compat_uint_t displayHeight;
	compat_uint_t displayFormat;
	compat_uint_t displayMode;
	compat_uint_t vsyncFPS;
	compat_uint_t physicalWidth;	/* length: mm, for legacy use */
	compat_uint_t physicalHeight;	/* length: mm, for legacy use */
	compat_uint_t physicalWidthUm;	/* length: um, for more precise precision */
	compat_uint_t physicalHeightUm;	/* length: um, for more precise precision */
	compat_uint_t isConnected;
	compat_uint_t isHDCPSupported;
	compat_uint_t isOVLDisabled;
	compat_uint_t is3DSupport;
	compat_uint_t const_layer_num;
	/* updateFPS: fps of HWC trigger display */
	/* notes: for better Accuracy, updateFPS = real_fps*100 */
	compat_uint_t updateFPS;
	compat_uint_t is_updateFPS_stable;
} compat_disp_session_info;

typedef struct compat_disp_buffer_info_t {
	/* Session */
	compat_uint_t session_id;
	/* Input */
	compat_uint_t layer_id;
	compat_uint_t layer_en;
	compat_int_t ion_fd;
	compat_uint_t cache_sync;
	/* Output */
	compat_uint_t index;
	compat_int_t fence_fd;
	compat_uint_t interface_index;
	compat_int_t interface_fence_fd;
} compat_disp_buffer_info;

typedef struct compat_disp_present_fence_info_t {
	/* input */
	compat_uint_t session_id;
	/* output */
	compat_uint_t present_fence_fd;
	compat_uint_t present_fence_index;
} compat_disp_present_fence;

typedef struct compat_disp_present_fence_t {
	/* Session */
	compat_uint_t session_id;

	/* Output */
	compat_uint_t index;
	compat_int_t fence_fd;
} compat_disp_present_fence_info;

typedef struct compat_disp_caps_t {
	compat_uint_t output_mode;
	compat_uint_t output_pass;
	compat_uint_t max_layer_num;
#ifdef CONFIG_FOR_SOURCE_PQ
	compat_uint_t max_pq_num;
#endif
	compat_uint_t disp_feature;
	compat_int_t is_support_frame_cfg_ioctl;
	compat_int_t is_output_rotated;
	compat_int_t lcm_degree;
	/* resizer input resolution list
	 * format:
	 *   sequence from big resolution to small
	 *   portrait width first then height
	 */
	compat_uint_t rsz_in_res_list[RSZ_RES_LIST_NUM][2];
} compat_disp_caps_info;

typedef struct compat_disp_session_buf_t {
	compat_uint_t session_id;
	compat_uint_t buf_hnd[3];
} compat_disp_session_buf_info;

typedef struct compat_layer_config_t {
	compat_uint_t ovl_id;
	compat_uint_t src_fmt;
	compat_uint_t dst_offset_x, dst_offset_y;
	compat_uint_t dst_width, dst_height;
	compat_uint_t ext_sel_layer;
} compat_layer_config;

typedef struct compat_disp_layer_info_t {
	compat_layer_config * input_config[2];
	compat_int_t disp_mode[2];
	compat_int_t layer_num[2];
	compat_int_t gles_head[2];
	compat_int_t gles_tail[2];
	compat_int_t hrt_num;
} compat_disp_layer_info;

struct compat_disp_scenario_config_t {
	compat_uint_t session_id;
	compat_uint_t scenario;
};

/* IOCTL commands. */
int _compat_ioctl_create_session(struct file *file, unsigned long arg);
int _compat_ioctl_destroy_session(struct file *file, unsigned long arg);
int _compat_ioctl_trigger_session(struct file *file, unsigned long arg);
int _compat_ioctl_prepare_present_fence(struct file *file, unsigned long arg);
int _compat_ioctl_prepare_buffer(struct file *file, unsigned long arg, ePREPARE_FENCE_TYPE type);
int _compat_ioctl_set_input_buffer(struct file *file, unsigned long arg);
int _compat_ioctl_set_output_buffer(struct file *file, unsigned long arg);
int _compat_ioctl_get_info(struct file *file, unsigned long arg);
int _compat_ioctl_get_is_driver_suspend(struct file *file, unsigned long arg);
int _compat_ioctl_get_display_caps(struct file *file, unsigned long arg);
int _compat_ioctl_wait_vsync(struct file *file, unsigned long arg);
int _compat_ioctl_set_vsync(struct file *file, unsigned long arg);
int _compat_ioctl_insert_session_buffers(struct file *file, unsigned long arg);
int _compat_ioctl_screen_freeze(struct file *file, unsigned long arg);
int _compat_ioctl_set_session_mode(struct file *file, unsigned long arg);


#define	COMPAT_DISP_IOCTL_CREATE_SESSION				DISP_IOW(201, compat_disp_session_config)
#define	COMPAT_DISP_IOCTL_DESTROY_SESSION				DISP_IOW(202, compat_disp_session_config)
#define	COMPAT_DISP_IOCTL_TRIGGER_SESSION				DISP_IOW(203, compat_disp_session_config)
#define	COMPAT_DISP_IOCTL_PREPARE_INPUT_BUFFER			DISP_IOW(204, compat_disp_buffer_info)
#define	COMPAT_DISP_IOCTL_PREPARE_OUTPUT_BUFFER		DISP_IOW(205, compat_disp_buffer_info)
#define	COMPAT_DISP_IOCTL_SET_INPUT_BUFFER				DISP_IOW(206, compat_disp_session_input_config)
#define	COMPAT_DISP_IOCTL_SET_OUTPUT_BUFFER			DISP_IOW(207, compat_disp_session_output_config)
#define	COMPAT_DISP_IOCTL_GET_SESSION_INFO				DISP_IOW(208, compat_disp_session_info)


#define	COMPAT_DISP_IOCTL_SET_SESSION_MODE				DISP_IOW(209, compat_disp_session_config)
#define	COMPAT_DISP_IOCTL_GET_SESSION_MODE				DISP_IOW(210, compat_disp_session_config)
#define	COMPAT_DISP_IOCTL_SET_SESSION_TYPE				DISP_IOW(211, compat_disp_session_config)
#define	COMPAT_DISP_IOCTL_GET_SESSION_TYPE				DISP_IOW(212, compat_disp_session_config)
#define	COMPAT_DISP_IOCTL_WAIT_FOR_VSYNC				DISP_IOW(213, compat_disp_session_vsync_config)
#define	COMPAT_DISP_IOCTL_SET_MAX_LAYER_NUM			DISP_IOW(214, compat_disp_session_layer_num_config)
#define	COMPAT_DISP_IOCTL_GET_VSYNC_FPS				DISP_IOW(215, compat_uint_t)
#define	COMPAT_DISP_IOCTL_SET_VSYNC_FPS				DISP_IOW(216, compat_uint_t)
#define	COMPAT_DISP_IOCTL_GET_PRESENT_FENCE			DISP_IOW(217, compat_disp_present_fence)

#define COMPAT_DISP_IOCTL_GET_IS_DRIVER_SUSPEND		DISP_IOW(218, compat_uint_t)
#define COMPAT_DISP_IOCTL_GET_DISPLAY_CAPS			DISP_IOW(219, compat_disp_caps_info)
#define COMPAT_DISP_IOCTL_INSERT_SESSION_BUFFERS			DISP_IOW(220, compat_disp_session_buf_info)
#define	COMPAT_DISP_IOCTL_FRAME_CONFIG				DISP_IOW(221, compat_disp_session_output_config)
#define COMPAT_DISP_IOCTL_QUERY_VALID_LAYER			DISP_IOW(222, compat_disp_layer_info)
#define	COMPAT_DISP_IOCTL_SET_SCENARIO				DISP_IOW(223, struct compat_disp_scenario_config_t)
#define	COMPAT_DISP_IOCTL_WAIT_ALL_JOBS_DONE			DISP_IOW(224, compat_uint_t)
#define	COMPAT_DISP_IOCTL_SCREEN_FREEZE			DISP_IOW(225, compat_uint_t)


#endif
#endif				/* __COMPAT_MTK_DISP_MGR_H */
