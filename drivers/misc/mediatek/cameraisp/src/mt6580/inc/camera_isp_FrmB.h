/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (C) 2020 MediaTek Inc.
 */

#ifndef _MT_ISP_FRMB_H
#define _MT_ISP_FRMB_H

#include "camera_isp.h"
#include <linux/types.h>

/* #define KERNEL_LOG  //enable debug log flag if defined */
#define ISR_LOG_ON		/* turn on log print at isr if defined */
/* time stamp workaround method.
 * (increase timestamp baseon fix fps, not read at each isr)
 */
#define T_STAMP_2_0

#define _rtbc_buf_que_2_0_

/*************************************************
 *
 ************************************************/
enum ISP_IRQ_CLEAR_ENUM_FRMB {
	ISP_IRQ_CLEAR_NONE_FRMB,
	ISP_IRQ_CLEAR_WAIT_FRMB,
	ISP_IRQ_CLEAR_STATUS_FRMB,
	ISP_IRQ_CLEAR_ALL_FRMB
};


enum ISP_IRQ_TYPE_ENUM_FRMB {
	ISP_IRQ_TYPE_INT_FRMB,
	ISP_IRQ_TYPE_DMA_FRMB,
	ISP_IRQ_TYPE_INTB_FRMB,
	ISP_IRQ_TYPE_DMAB_FRMB,
	ISP_IRQ_TYPE_INTC_FRMB,
	ISP_IRQ_TYPE_DMAC_FRMB,
	ISP_IRQ_TYPE_INTX_FRMB,
	ISP_IRQ_TYPE_DMAX_FRMB,
	ISP_IRQ_TYPE_AMOUNT_FRMB
};

/* special user for specific operation */
enum ISP_IRQ_WAITIRQ_SPEUSER_ENUM {
	ISP_IRQ_WAITIRQ_SPEUSER_NONE = 0,
	ISP_IRQ_WAITIRQ_SPEUSER_EIS = 1,
	ISP_IRQ_WAITIRQ_SPEUSER_NUM
};
struct ISP_IRQ_USER_STRUCT_FRMB {
	enum ISP_IRQ_TYPE_ENUM_FRMB Type;
	unsigned int Status;
	int UserKey;		/* user key for doing interrupt operation */
};

struct ISP_IRQ_TIME_STRUCT_FRMB {
/* time stamp of the latest occurring signal */
	unsigned int tLastSig_sec;
/* time stamp of the latest occurring signal */
	unsigned int tLastSig_usec;
/* time period from marking a signal to user
 * try to wait and get the signal
 */
	unsigned int tMark2WaitSig_sec;
/* time period from marking a signal to user
 * try to wait and get the signal
 */
	unsigned int tMark2WaitSig_usec;
/* time period from latest occurring signal to user
 * try to wait and get the signal
 */
	unsigned int tLastSig2GetSig_sec;
/* time period from latest occurring signal to user
 * try to wait and get the signal
 */
	unsigned int tLastSig2GetSig_usec;
	int passedbySigcnt;	/* the count for the signal passed by  */
};

struct ISP_EIS_META_STRUCT {
/* time stamp of the last closest occurring
 * sof signal for pass1 done
 */
	unsigned int tLastSOF2P1done_sec;
/* time stamp of the last closest occurring
 * sof signal for pass1 done
 */
	unsigned int tLastSOF2P1done_usec;
};

struct ISP_WAIT_IRQ_STRUCT_FRMB {
	enum ISP_IRQ_CLEAR_ENUM_FRMB Clear;
	struct ISP_IRQ_USER_STRUCT_FRMB UserInfo;
	struct ISP_IRQ_TIME_STRUCT_FRMB TimeInfo;
	struct ISP_EIS_META_STRUCT EisMeta;
	enum ISP_IRQ_WAITIRQ_SPEUSER_ENUM SpecUser;
/* time out for waiting for a specific interrupt */
	unsigned int Timeout;
	unsigned int bDumpReg;
};

struct ISP_REGISTER_USERKEY_STRUCT_FRMB {
	int userKey;
	char *userName;
};


struct ISP_READ_IRQ_STRUCT_FRMB {
	enum ISP_IRQ_TYPE_ENUM Type;
	unsigned int Status;
};

struct ISP_CLEAR_IRQ_STRUCT_FRMB {
	enum ISP_IRQ_TYPE_ENUM Type;
	unsigned int Status;
};

enum ISP_HOLD_TIME_ENUM_FRMB {
	ISP_HOLD_TIME_VD_FRMB,
	ISP_HOLD_TIME_EXPDONE_FRMB
};

struct ISP_REG_STRUCT_FRMB {
	unsigned int Addr_FrmB;	/* register's addr */
	unsigned int Val_FrmB;	/* register's value */
};

struct ISP_REG_IO_STRUCT_FRMB {
	/* unsigned int Data_FrmB;   // pointer to ISP_REG_STRUCT */
	struct ISP_REG_STRUCT_FRMB *pData_FrmB;
	unsigned int Count_FrmB;	/* count */
};

/* typedef void (*pIspCallback)(void); */

enum ISP_CALLBACK_ENUM_FRMB {
/* Work queue. It is interruptible, so there can
 * be "Sleep" in work queue function.
 */
	ISP_CALLBACK_WORKQUEUE_VD_FRMB,
	ISP_CALLBACK_WORKQUEUE_EXPDONE_FRMB,
/* Tasklet. It is uninterrupted, so there can NOT
 * be "Sleep" in tasklet function.
 */
	ISP_CALLBACK_TASKLET_VD_FRMB,
	ISP_CALLBACK_TASKLET_EXPDONE_FRMB,
	ISP_CALLBACK_AMOUNT_FRMB
};

struct ISP_CALLBACK_STRUCT_FRMB {
	enum ISP_CALLBACK_ENUM Type_FrmB;
	pIspCallback Func_FrmB;
};

/*  */
/* length of the two memory areas */
#define P1_DEQUE_CNT    1
/* ////////////////////////////////////// */
/* DEFINED IN CAMREA_ISP.H */
/* #define RT_BUF_TBL_NPAGES 16 */
/* #define ISP_RT_BUF_SIZE 16 */
/* #define ISP_RT_CQ0C_BUF_SIZE (ISP_RT_BUF_SIZE)//(ISP_RT_BUF_SIZE>>1) */
/* ///////////////////////////////////// */
/* pass1 setting sync index */
#define ISP_REG_P1_CFG_IDX 0x4090


/*  */
enum _isp_tg_enum_ {
	_cam_tg_ = 0,
	_cam_tg2_,		/* 1 */
	_camsv_tg_,		/* 2 */
	_camsv2_tg_,		/* 3 */
	_cam_tg_max_
};

/*  */
struct ISP_RT_IMAGE_INFO_STRUCT {
	unsigned int w;
	unsigned int h;
	unsigned int xsize;
	unsigned int stride;
	unsigned int fmt;
	unsigned int pxl_id;
	unsigned int wbn;
	unsigned int ob;
	unsigned int lsc;
	unsigned int rpg;
	unsigned int m_num_0;
	unsigned int frm_cnt;
};

struct ISP_RT_HRZ_INFO_STRUCT {
	unsigned int srcX;	/* crop window start point */
	unsigned int srcY;
	unsigned int srcW;	/* crop window size */
	unsigned int srcH;
	unsigned int dstW;	/* rrz out size */
	unsigned int dstH;
};

struct ISP_RT_DMAO_CROPPING_STRUCT {
	unsigned int x;		/* in pix */
	unsigned int y;		/* in pix */
	unsigned int w;		/* in byte */
	unsigned int h;		/* in byte */
};


struct ISP_RT_BUF_INFO_STRUCT_FRMB {
	unsigned int memID;
	unsigned int size;
	long long base_vAddr;
	unsigned int base_pAddr;
	unsigned int timeStampS;
	unsigned int timeStampUs;
	unsigned int bFilled;
	struct ISP_RT_IMAGE_INFO_STRUCT image;
	struct ISP_RT_HRZ_INFO_STRUCT HrzInfo;
	struct ISP_RT_DMAO_CROPPING_STRUCT dmaoCrop;	/* imgo */
	unsigned int bDequeued;
	signed int bufIdx;	/* used for replace buffer */
};

/*  */
struct ISP_DEQUE_BUF_INFO_STRUCT_FRMB {
	unsigned int count;
	unsigned int sof_cnt;	/* cnt for current sof */
	unsigned int img_cnt;	/* cnt for mapping to which sof */
	/*support only deque 1 image at a time */
	/* ISP_RT_BUF_INFO_STRUCT  data[ISP_RT_BUF_SIZE]; */
	struct ISP_RT_BUF_INFO_STRUCT_FRMB data[P1_DEQUE_CNT];
};

/*  */
struct ISP_RT_RING_BUF_INFO_STRUCT_FRMB {
	unsigned int start;	/* current DMA accessing buffer */
/* total buffer number.Include Filled and empty */
	unsigned int total_count;
/* total empty buffer number include
 * current DMA accessing buffer
 */
	unsigned int empty_count;
/* previous total empty buffer number include
 * current DMA accessing buffer
 */
	unsigned int pre_empty_count;
	unsigned int active;
	unsigned int read_idx;
	unsigned int img_cnt;	/* cnt for mapping to which sof */
	struct ISP_RT_BUF_INFO_STRUCT_FRMB data[ISP_RT_BUF_SIZE];
};

/*  */
enum ISP_RT_BUF_CTRL_ENUM_FRMB {
	ISP_RT_BUF_CTRL_ENQUE_FRMB,	/* 0 */
#ifdef _rtbc_buf_que_2_0_
	ISP_RT_BUF_CTRL_ENQUE_IMD_FRMB,
#else
	ISP_RT_BUF_CTRL_ENQUE_IMD_FRMB = ISP_RT_BUF_CTRL_ENQUE_FRMB,
#endif
	ISP_RT_BUF_CTRL_EXCHANGE_ENQUE_FRMB,	/* 1 */
	ISP_RT_BUF_CTRL_DEQUE_FRMB,	/* 2 */
	ISP_RT_BUF_CTRL_IS_RDY_FRMB,	/* 3 */
#ifdef _rtbc_buf_que_2_0_
	ISP_RT_BUF_CTRL_DMA_EN_FRMB,	/* 4 */
#endif
	ISP_RT_BUF_CTRL_GET_SIZE_FRMB,	/* 5 */
	ISP_RT_BUF_CTRL_CLEAR_FRMB,	/* 6 */
	ISP_RT_BUF_CTRL_CUR_STATUS_FRMB,	/* 7 */
	ISP_RT_BUF_CTRL_MAX_FRMB
};

struct ISP_RT_BUF_STRUCT_FRMB {
	enum ISP_RTBC_STATE_ENUM state;
	unsigned long dropCnt;
	struct ISP_RT_RING_BUF_INFO_STRUCT_FRMB ring_buf[_rt_dma_max_];
};
/*  */
struct ISP_BUFFER_CTRL_STRUCT_FRMB {
	enum ISP_RT_BUF_CTRL_ENUM_FRMB ctrl;
	enum _isp_dma_enum_ buf_id;
	/* unsigned int            data_ptr; */
	/* unsigned int            ex_data_ptr; //exchanged buffer */
	struct ISP_RT_BUF_INFO_STRUCT_FRMB *data_ptr;
	struct ISP_RT_BUF_INFO_STRUCT_FRMB *ex_data_ptr;
	unsigned char *pExtend;
};


/*  */
/* reference count */
#define _use_kernel_ref_cnt_

/*  */
enum ISP_REF_CNT_CTRL_ENUM_FRMB {
	ISP_REF_CNT_GET_FRMB,	/* 0 */
	ISP_REF_CNT_INC_FRMB,	/* 1 */
	ISP_REF_CNT_DEC_FRMB,	/* 2 */
	ISP_REF_CNT_DEC_AND_RESET_P1_P2_IF_LAST_ONE_FRMB,	/* 3 */
	ISP_REF_CNT_DEC_AND_RESET_P1_IF_LAST_ONE_FRMB,	/* 4 */
	ISP_REF_CNT_DEC_AND_RESET_P2_IF_LAST_ONE_FRMB,	/* 5 */
	ISP_REF_CNT_MAX_FRMB
};

/*  */
enum ISP_REF_CNT_ID_ENUM_FRMB {
	ISP_REF_CNT_ID_IMEM_FRMB,	/* 0 */
	ISP_REF_CNT_ID_ISP_FUNC_FRMB,	/* 1 */
	ISP_REF_CNT_ID_GLOBAL_PIPE_FRMB,	/* 2 */
	ISP_REF_CNT_ID_P1_PIPE_FRMB,	/* 3 */
	ISP_REF_CNT_ID_P2_PIPE_FRMB,	/* 4 */
	ISP_REF_CNT_ID_MAX_FRMB,
};

struct ISP_REF_CNT_CTRL_STRUCT_FRMB {
	enum ISP_REF_CNT_CTRL_ENUM_FRMB ctrl;
	enum ISP_REF_CNT_ID_ENUM_FRMB id;
	signed int *data_ptr;
};


/* struct for enqueue/dequeue control in ihalpipe wrapper */
enum ISP_ED_BUFQUE_CTRL_ENUM {
/* 0,signal that a specific buffer is enqueued */
	ISP_ED_BUFQUE_CTRL_ENQUE_FRAME = 0,
/* 1,a dequeue thread is waiting to do dequeue */
	ISP_ED_BUFQUE_CTRL_WAIT_DEQUE,
/* 2,signal that a buffer is dequeued (success) */
	ISP_ED_BUFQUE_CTRL_DEQUE_SUCCESS,
/* 3,signal that a buffer is dequeued (fail) */
	ISP_ED_BUFQUE_CTRL_DEQUE_FAIL,
	ISP_ED_BUFQUE_CTRL_WAIT_FRAME,	/* 4,wait for a specific buffer */
/* 5,wake all slept users to check buffer is dequeued or not */
	ISP_ED_BUFQUE_CTRL_WAKE_WAITFRAME,
	ISP_ED_BUFQUE_CTRL_CLAER_ALL,	/* 6,free all recored dequeued buffer */
	ISP_ED_BUFQUE_CTRL_MAX
};

struct ISP_ED_BUFQUE_STRUCT_FRMB {
	enum ISP_ED_BUFQUE_CTRL_ENUM ctrl;
	unsigned int processID;
	unsigned int callerID;
	int p2burstQIdx;
	int p2dupCQIdx;
	unsigned int timeoutUs;
};

enum ISP_ED_BUF_STATE_ENUM {
	ISP_ED_BUF_STATE_NONE = -1,
	ISP_ED_BUF_STATE_ENQUE = 0,
	ISP_ED_BUF_STATE_RUNNING,
	ISP_ED_BUF_STATE_WAIT_DEQUE_FAIL,
	ISP_ED_BUF_STATE_DEQUE_SUCCESS,
	ISP_ED_BUF_STATE_DEQUE_FAIL
};


/*************************************************
 * pass1 real time buffer control use cq0c
 ************************************************/
/*  */
/* #define _rtbc_use_cq0c_ //defined in camera_isp.h */

#define _MAGIC_NUM_ERR_HANDLING_

#if defined(_rtbc_use_cq0c_)
/*  */
struct CQ_INFO_RTBC_ST_FRMB {
	struct CQ_CMD_ST imgo_frmb;
	struct CQ_CMD_ST img2o_frmb;	/* rrzo */
	struct CQ_CMD_ST next_cq0ci_frmb;
	struct CQ_CMD_ST end_frmb;
	unsigned long imgo_base_pAddr_frmb;
	unsigned long img2o_base_pAddr_frmb;	/* rrzo */
	signed int imgo_buf_idx_frmb;	/* used for replace buffer */
	signed int img2o_buf_idx_frmb;	/* used for replace buffer//rrzo */
};

struct CQ_RING_CMD_ST_FRMB {
	struct CQ_INFO_RTBC_ST_FRMB cq_rtbc_frmb;
	unsigned long next_pa_frmb;
	struct CQ_RING_CMD_ST_FRMB *pNext_frmb;
};

struct CQ_RTBC_RING_ST_FRMB {
	struct CQ_RING_CMD_ST_FRMB rtbc_ring_frmb[ISP_RT_CQ0C_BUF_SIZE];
	unsigned long imgo_ring_size_frmb;
	unsigned long img2o_ring_size_frmb;	/* rrzo */
};

#endif

/* CQ0B for AE smoothing, set obc_gain0~3 */
struct CQ0B_INFO_RTBC_ST_FRMB {
	struct CQ_CMD_ST ob_frmb;
	struct CQ_CMD_ST end_frmb;
};

struct CQ0B_RING_CMD_ST_FRMB {
	struct CQ0B_INFO_RTBC_ST_FRMB cq0b_rtbc_frmb;
	unsigned long next_pa_frmb;
	struct CQ0B_RING_CMD_ST_FRMB *pNext_frmb;
};

struct CQ0B_RTBC_RING_ST_FRMB {
	struct CQ0B_RING_CMD_ST_FRMB rtbc_ring_frmb;
};


#ifdef CONFIG_COMPAT
struct compat_ISP_REGISTER_USERKEY_STRUCT_FRMB {
	int userKey;
	compat_uptr_t userName;
};

struct compat_ISP_REG_IO_STRUCT_FRMB {
	compat_uptr_t pData;
	unsigned int Count;	/* count */
};

struct compat_ISP_BUFFER_CTRL_STRUCT_FRMB {
	ISP_RT_BUF_CTRL_ENUM ctrl;
	enum _isp_dma_enum_ buf_id;
	compat_uptr_t data_ptr;
	compat_uptr_t ex_data_ptr;	/* exchanged buffer */
	compat_uptr_t pExtend;
};

struct compat_ISP_REF_CNT_CTRL_STRUCT_FRMB {
	ISP_REF_CNT_CTRL_ENUM ctrl;
	ISP_REF_CNT_ID_ENUM id;
	compat_uptr_t data_ptr;
};
#endif

/*  */
/*************************************************
 *
 ************************************************/


/*************************************************
 *
 ************************************************/

enum ISP_CMD_ENUM_FRMB {
	/* ISP_CMD_RESET,          //Reset */
	/* ISP_CMD_RESET_BUF, */
	/* ISP_CMD_READ_REG,       //Read register from driver */
	/* ISP_CMD_WRITE_REG,      //Write register to driver */
	/* ISP_CMD_HOLD_TIME, */
	/* ISP_CMD_HOLD_REG,       //Hold reg write to hw, on/off */
	/* ISP_CMD_WAIT_IRQ,       //Wait IRQ */
	/* /ISP_CMD_READ_IRQ,       //Read IRQ */
	/* ISP_CMD_CLEAR_IRQ,      //Clear IRQ */
	/* ISP_CMD_DUMP_REG,       //Dump ISP registers , for debug usage */
	/* ISP_CMD_SET_USER_PID,   //for signal */
	/* ISP_CMD_RT_BUF_CTRL,   //for pass buffer control */
	/* ISP_CMD_REF_CNT,        //get imem reference count */
	/* ISP_CMD_DEBUG_FLAG,      //Dump message level */
	/* ISP_CMD_SENSOR_FREQ_CTRL      // sensor frequence control */

/* register for a specific irq */
	ISP_CMD_REGISTER_IRQ_FRMB = ISP_CMD_SENSOR_FREQ_CTRL + 1,
	ISP_CMD_DEBUG_FLAG_FRMB,
	ISP_CMD_UNREGISTER_IRQ_FRMB,	/* unregister for a specific irq */
	ISP_CMD_WAIT_IRQ_FRMB,	/* Wait IRQ */
	ISP_CMD_ED_QUEBUF_CTRL_FRMB,
	ISP_CMD_UPDATE_REGSCEN_FRMB,
	ISP_CMD_QUERY_REGSCEN_FRMB,
	ISP_CMD_UPDATE_BURSTQNUM_FRMB,
	ISP_CMD_QUERY_BURSTQNUM_FRMB,
	ISP_CMD_DUMP_ISR_LOG_FRMB,	/* dump isr log */
	ISP_CMD_GET_CUR_SOF_FRMB,
	ISP_CMD_GET_DMA_ERR_FRMB,
	ISP_CMD_GET_INT_ERR_FRMB,
#ifdef T_STAMP_2_0
	ISP_CMD_SET_FPS_FRMB,
#endif
/* register for a user key to do irq operation */
	ISP_CMD_REGISTER_IRQ_USER_KEY,
	/* mark for a specific register before wait
	 * for the interrupt if needed
	 */
	ISP_CMD_MARK_IRQ_REQUEST,
	/* query time information between read and mark */
	ISP_CMD_GET_MARK2QUERY_TIME,
	ISP_CMD_FLUSH_IRQ_REQUEST,	/* flush signal */
	ISP_CMD_SET_CAM_VERSION,	/* set camera version */
	/* dump current frame informaiton, 1 for drop frmae,
	 * 2 for last working frame
	 */
	ISP_CMD_GET_DROP_FRAME_FRMB,
};
/*  */
/* #define ISP_RESET           _IO  (ISP_MAGIC,
 * ISP_CMD_RESET)
 */
/* #define ISP_RESET_BUF       _IO  (ISP_MAGIC,
 * ISP_CMD_RESET_BUF)
 */
/* #define ISP_READ_REGISTER   _IOWR(ISP_MAGIC,
 * ISP_CMD_READ_REG,      ISP_REG_IO_STRUCT)
 */
/* #define ISP_WRITE_REGISTER  _IOWR(ISP_MAGIC,
 * ISP_CMD_WRITE_REG,     ISP_REG_IO_STRUCT)
 */
/* #define ISP_HOLD_REG_TIME   _IOW (ISP_MAGIC,
 *ISP_CMD_HOLD_TIME,     ISP_HOLD_TIME_ENUM)
 */
/* #define ISP_HOLD_REG        _IOW (ISP_MAGIC,
 * ISP_CMD_HOLD_REG,      bool)
 */
/* #define ISP_WAIT_IRQ        _IOW (ISP_MAGIC,
 * ISP_CMD_WAIT_IRQ,      ISP_WAIT_IRQ_STRUCT)
 */
/* #define ISP_READ_IRQ        _IOR (ISP_MAGIC,
 * ISP_CMD_READ_IRQ,      ISP_READ_IRQ_STRUCT)
 */
/* #define ISP_CLEAR_IRQ       _IOW (ISP_MAGIC,
 * ISP_CMD_CLEAR_IRQ,     ISP_CLEAR_IRQ_STRUCT)
 */
/* #define ISP_DUMP_REG        _IO  (ISP_MAGIC,
 * ISP_CMD_DUMP_REG)
 */
/* #define ISP_SET_USER_PID    _IOW (ISP_MAGIC,
 * ISP_CMD_SET_USER_PID,    unsigned long)
 */
/* #define ISP_BUFFER_CTRL     _IOWR(ISP_MAGIC,
 * ISP_CMD_RT_BUF_CTRL,    ISP_BUFFER_CTRL_STRUCT)
 */
/* #define ISP_REF_CNT_CTRL    _IOWR(ISP_MAGIC,
 * ISP_CMD_REF_CNT,       ISP_REF_CNT_CTRL_STRUCT)
 */
#define ISP_DEBUG_FLAG_FRMB         _IOW(ISP_MAGIC, \
ISP_CMD_DEBUG_FLAG_FRMB,    unsigned long)
/* #define ISP_SENSOR_FREQ_CTRL  _IOW (ISP_MAGIC,
 * ISP_CMD_SENSOR_FREQ_CTRL,    unsigned long)
 */
#define ISP_REGISTER_IRQ_FRMB       _IOW(ISP_MAGIC, \
ISP_CMD_REGISTER_IRQ_FRMB,  struct ISP_WAIT_IRQ_STRUCT_FRMB)
#define ISP_UNREGISTER_IRQ_FRMB     _IOW(ISP_MAGIC, \
ISP_CMD_UNREGISTER_IRQ_FRMB, struct ISP_WAIT_IRQ_STRUCT_FRMB)
#define ISP_WAIT_IRQ_FRMB           _IOW(ISP_MAGIC, \
ISP_CMD_WAIT_IRQ_FRMB, struct ISP_WAIT_IRQ_STRUCT_FRMB)
#define ISP_ED_QUEBUF_CTRL_FRMB     _IOWR(ISP_MAGIC, \
ISP_CMD_ED_QUEBUF_CTRL_FRMB, struct ISP_ED_BUFQUE_STRUCT_FRMB)
#define ISP_UPDATE_REGSCEN_FRMB     _IOWR(ISP_MAGIC, \
ISP_CMD_UPDATE_REGSCEN_FRMB, unsigned int)
#define ISP_QUERY_REGSCEN_FRMB      _IOR(ISP_MAGIC, \
ISP_CMD_QUERY_REGSCEN_FRMB, unsigned int)
#define ISP_UPDATE_BURSTQNUM_FRMB   _IOW(ISP_MAGIC, \
ISP_CMD_UPDATE_BURSTQNUM_FRMB, int)
#define ISP_QUERY_BURSTQNUM_FRMB    _IOR(ISP_MAGIC, \
ISP_CMD_QUERY_BURSTQNUM_FRMB, int)
#define ISP_DUMP_ISR_LOG_FRMB       _IO(ISP_MAGIC, \
ISP_CMD_DUMP_ISR_LOG_FRMB)
#define ISP_GET_CUR_SOF_FRMB        _IOWR(ISP_MAGIC, \
ISP_CMD_GET_CUR_SOF_FRMB, unsigned long)
#define ISP_GET_DMA_ERR_FRMB        _IOWR(ISP_MAGIC, \
ISP_CMD_GET_DMA_ERR_FRMB, unsigned int)
#define ISP_GET_INT_ERR_FRMB        _IOR(ISP_MAGIC, \
ISP_CMD_GET_INT_ERR_FRMB, unsigned long)
#ifdef T_STAMP_2_0
#define ISP_SET_FPS_FRMB        _IOW(ISP_MAGIC, \
ISP_CMD_SET_FPS_FRMB,    unsigned int)
#endif
#define ISP_GET_DROP_FRAME_FRMB     _IOWR(ISP_MAGIC, \
ISP_CMD_GET_DROP_FRAME_FRMB, unsigned int)
#define ISP_REGISTER_IRQ_USER_KEY   _IOWR(ISP_MAGIC, \
ISP_CMD_REGISTER_IRQ_USER_KEY, \
struct ISP_REGISTER_USERKEY_STRUCT_FRMB)
#define ISP_MARK_IRQ_REQUEST        _IOWR(ISP_MAGIC, \
ISP_CMD_MARK_IRQ_REQUEST, struct ISP_WAIT_IRQ_STRUCT_FRMB)
#define ISP_GET_MARK2QUERY_TIME     _IOWR(ISP_MAGIC, \
ISP_CMD_GET_MARK2QUERY_TIME, struct ISP_WAIT_IRQ_STRUCT_FRMB)
#define ISP_FLUSH_IRQ_REQUEST       _IOW(ISP_MAGIC, \
ISP_CMD_FLUSH_IRQ_REQUEST, struct ISP_WAIT_IRQ_STRUCT_FRMB)
#define ISP_SET_CAM_VERSION         _IOW(ISP_MAGIC, \
ISP_CMD_SET_CAM_VERSION, bool)

#ifdef CONFIG_COMPAT
#define COMPAT_ISP_DEBUG_FLAG_FRMB      _IOW(ISP_MAGIC, \
ISP_CMD_DEBUG_FLAG_FRMB,    compat_uptr_t)
#define COMPAT_ISP_REGISTER_IRQ_USER_KEY    _IOWR(ISP_MAGIC, \
ISP_CMD_REGISTER_IRQ_USER_KEY, \
struct compat_ISP_REGISTER_USERKEY_STRUCT_FRMB)
#define COMPAT_ISP_GET_DMA_ERR_FRMB     _IOWR(ISP_MAGIC, \
ISP_CMD_GET_DMA_ERR_FRMB,  compat_uptr_t)
#define COMPAT_ISP_GET_INT_ERR_FRMB     _IOR(ISP_MAGIC, \
ISP_CMD_GET_INT_ERR_FRMB, compat_uptr_t)
#define COMPAT_ISP_WAIT_IRQ             _IOW(ISP_MAGIC, \
ISP_CMD_WAIT_IRQ_FRMB,      compat_ISP_WAIT_IRQ_STRUCT_FRMB)
#define COMPAT_ISP_MARK_IRQ_REQUEST     _IOWR(ISP_MAGIC, \
ISP_CMD_MARK_IRQ_REQUEST, compat_ISP_WAIT_IRQ_STRUCT_FRMB)
#define COMPAT_ISP_GET_MARK2QUERY_TIME  _IOWR(ISP_MAGIC, \
ISP_CMD_GET_MARK2QUERY_TIME, compat_ISP_WAIT_IRQ_STRUCT_FRMB)
#define COMPAT_ISP_FLUSH_IRQ_REQUEST    _IOW(ISP_MAGIC, \
ISP_CMD_FLUSH_IRQ_REQUEST, compat_ISP_WAIT_IRQ_STRUCT_FRMB)
#define COMPAT_ISP_GET_CUR_SOF_FRMB     _IOWR(ISP_MAGIC, \
ISP_CMD_GET_CUR_SOF_FRMB, compat_uptr_t)
#endif

/*  */


/*  */
/* int32_t ISP_MDPClockOnCallback(uint64_t engineFlag); */
/* int32_t ISP_MDPDumpCallback(uint64_t engineFlag, int level); */
/* int32_t ISP_MDPResetCallback(uint64_t engineFlag); */
/* int32_t ISP_MDPClockOffCallback(uint64_t engineFlag); */
/* int32_t ISP_BeginGCECallback(uint32_t taskID,
 * uint32_t *regCount, uint32_t **regAddress);
 */
/* int32_t ISP_EndGCECallback(uint32_t taskID,
 * uint32_t regCount, uint32_t *regValues);
 */
/*  */

/* basically , should separate into p1/p1_d/p2/camsv/camsv_d, */
/* currently, only use camsv/camsv_d/others */
enum eISPIrq {
	_IRQ = 0,
	_IRQ_D = 1,
	_CAMSV_IRQ = 2,
	_CAMSV_D_IRQ = 3,
	_IRQ_MAX = 4,
};
/*  */

/* static int ISP_ED_BufQue_CTRL_FUNC(ISP_ED_BUFQUE_STRUCT param); */
/* static int ISP_RTBC_ENQUE_FRMB(int dma,
 * ISP_RT_BUF_INFO_STRUCT* prt_buf_info);
 */
/* static int ISP_RTBC_DEQUE_FRMB(int dma,
 * ISP_DEQUE_BUF_INFO_STRUCT*    pdeque_buf);
 */
/* static long ISP_Buf_CTRL_FUNC_FRMB(unsigned int Param); */
/* static int ISP_SOF_Buf_Get_FRMB(eISPIrq irqT,
 * unsigned long long sec,unsigned long usec,bool bDrop);
 */
/* static int ISP_DONE_Buf_Time_FrmB(eISPIrq irqT,
 * unsigned long long sec,unsigned long usec);
 */
/* static int ISP_WaitIrq_FrmB(struct ISP_WAIT_IRQ_STRUCT_FRMB* WaitIrq); */
/*  */

#endif
