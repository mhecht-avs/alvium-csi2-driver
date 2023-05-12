#ifndef __AVT_CSI2_H__
#define __AVT_CSI2_H__

#include "avt-csi2-regs.h"
#include "libcsi_ioctl.h"

#define USEMUTEX


/* Driver release version */
#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)

/* Driver release version */
#define DRV_VER_MAJOR           3
#define DRV_VER_MINOR           0
#define DRV_VER_PATCH           0
#define DRV_VER_BUILD           0
/* Major:Minor:Patch:Build */
#define DRIVER_VERSION          STR(DRV_VER_MAJOR) "." STR(DRV_VER_MINOR) "." STR(DRV_VER_PATCH) "." STR(DRV_VER_BUILD)


#define BCRM_DEVICE_VERSION	0x00010000
#define BCRM_MAJOR_VERSION	0x0001
#define BCRM_MINOR_VERSION	0x0000

#define GCPRM_DEVICE_VERSION	0x00010000
#define GCPRM_MAJOR_VERSION	0x0001
#define GCPRM_MINOR_VERSION	0x0000


struct avt_frame_param {
	/* crop settings */
	struct v4l2_rect r;

	/* min/max/step values for frame size */
	uint32_t minh;
	uint32_t maxh;
	uint32_t sh;
	uint32_t minw;
	uint32_t maxw;
	uint32_t sw;
	uint32_t minhoff;
	uint32_t maxhoff;
	uint32_t shoff;
	uint32_t minwoff;
	uint32_t maxwoff;
	uint32_t swoff;
};

enum avt_mode {
	AVT_BCRM_MODE,
	AVT_GENCP_MODE,
};

enum avt3_frame_rate
{
	AVT3_02_FPS = 0,
	AVT3_05_FPS,
	AVT3_08_FPS,
	AVT3_10_FPS,
	AVT3_11_FPS,
	AVT3_12_FPS,
	AVT3_13_FPS,
	AVT3_14_FPS,
	AVT3_15_FPS,
	AVT3_20_FPS,
	AVT3_24_FPS,
	AVT3_25_FPS,
	AVT3_30_FPS,
	AVT3_40_FPS,
	AVT3_45_FPS,
	AVT3_50_FPS,
	AVT3_60_FPS,
	AVT3_75_FPS,
	AVT3_90_FPS,
	AVT3_100_FPS,
	AVT3_120_FPS,
	AVT3_150_FPS,
	AVT3_200_FPS,
	AVT3_250_FPS,
	AVT3_300_FPS,
	AVT3_500_FPS,
	AVT3_750_FPS,
	AVT3_1000_FPS,
	AVT3_1200_FPS,
	AVT3_1400_FPS,
	AVT3_1500_FPS,
	AVT3_1600_FPS,
	AVT3_1650_FPS,
	AVT3_1750_FPS,
	AVT3_1800_FPS,
	AVT3_2000_FPS,
	AVT3_NUM_FRAMERATES,
};

enum avt3_mode_id
{
	AVT3_MODE_FF_32_16 = 0,
//	AVT3_MODE_FF_32_32,
	AVT3_MODE_FF_64_32,
//	AVT3_MODE_FF_64_64,
//	AVT3_MODE_FF_96_32,
	AVT3_MODE_FF_128_32,
	AVT3_MODE_FF_128_64,
	AVT3_MODE_FF_176_64,
	AVT3_MODE_QCIF_176_144,
	AVT3_MODE_QVGA_320_240,
	AVT3_MODE_VGA_640_480,
	AVT3_MODE_NTSC_720_480,
	AVT3_MODE_PAL_720_576,
//	AVT3_MODE_XGA_1024_768,
	AVT3_MODE_720P_1280_720,
	AVT3_MODE_1080P_1920_1080,
	AVT3_MODE_QSXGA_2592_1944,
	AVT3_MODE_UHD_3840_2160,
	AVT3_MODE_UHD2_4096_3672,
	AVT3_MODE_5376_3672,
	AVT3_NUM_MODES,
};

//#define AVT_RESET_DELAY1			(2000000)
//#define AVT_RESET_DELAY2			(2500000)

#define AVT_CTRL_STREAM_DISABLED (1 << 1)


struct avt_ctrl_mapping {
	u8	reg_size;
	u8	data_size;
	u16	min_offset;
	u16	max_offset;
	u16	reg_offset;
	u16	step_offset;
	u32	id;
	u32	type;
	u32	flags;
	struct {
		s8	*name;
		u8	feature_avail;
	} attr;
    bool custom;
    s64 min_value;
    s64 max_value;
    const char * const * qmenu;
    u32 avt_flags;
};

#define AV_ATTR_REVERSE_X			{"Reverse X",		0}
#define AV_ATTR_REVERSE_Y			{"Reverse Y",		1}
#define AV_ATTR_INTENSITY_AUTO		{"Intensity Auto",	2}
#define AV_ATTR_BRIGHTNESS			{"Brightness",		3}
/* Red & Blue balance features are enabled by default since it doesn't have
 * option in BCRM FEATURE REGISTER
 */
#define AV_ATTR_RED_BALANCE			{"Red Balance",         3}
#define AV_ATTR_BLUE_BALANCE		{"Blue Balance",        3}
#define AV_ATTR_GAIN				{"Gain",				4}
#define AV_ATTR_GAMMA				{"Gamma",				5}
#define AV_ATTR_CONTRAST			{"Contrast",			6}
#define AV_ATTR_SATURATION			{"Saturation",			7}
#define AV_ATTR_HUE					{"Hue",					8}
#define AV_ATTR_WHITEBALANCE		{"White Balance",		9}
#define AV_ATTR_SHARPNESS			{"Sharpness",	       10}
#define AV_ATTR_EXPOSURE_AUTO		{"Exposure Auto",      11}
#define AV_ATTR_AUTOGAIN			{"Auto Gain",          12}
#define AV_ATTR_EXPOSURE			{"Exposure",	       13}
#define AV_ATTR_EXPOSURE_ABS		{"Exposure Absolute",  13}
#define AV_ATTR_WHITEBALANCE_AUTO	{"Auto White Balance", 14}
#define AV_ATTR_LINK_FREQ			{"MIPI CSI-2 Link Frequency", 15}


#define AV_ATTR_TRIGGER_MODE                    {"Trigger Mode",                    17}
#define AV_ATTR_TRIGGER_ACTIVATION              {"Trigger Activation",              17}
#define AV_ATTR_TRIGGER_SOURCE                  {"Trigger Source",                  17}
#define AV_ATTR_TRIGGER_SOFTWARE                {"Trigger Software",                17}

/* Trigger mode to ON/OFF */
#define V4L2_CID_TRIGGER_MODE                   (V4L2_CID_CAMERA_CLASS_BASE+47)

/* trigger activation: edge_rising, edge_falling, edge_any, level_high, level_low */
#define V4L2_CID_TRIGGER_ACTIVATION             (V4L2_CID_CAMERA_CLASS_BASE+48)

/* trigger source: software, gpio0, gpio1 */
#define V4L2_CID_TRIGGER_SOURCE                 (V4L2_CID_CAMERA_CLASS_BASE+49)

/* Execute a software trigger */
#define V4L2_CID_TRIGGER_SOFTWARE               (V4L2_CID_CAMERA_CLASS_BASE+50)

static const char * const v4l2_triggeractivation_menu[] = {
        "Rising Edge",
        "Falling Edge",
        "Any Edge",
        "Level High",
        "Level Low"
};
static const char * const v4l2_triggersource_menu[] = {
        "Line 0",
        "Line 1",
        "Line 2",
        "Line 3",
        "Software"
};

const struct avt_ctrl_mapping avt_ctrl_mappings[] = {
	{
		.id				= V4L2_CID_EXPOSURE,
		.attr			= AV_ATTR_EXPOSURE,
		.min_offset		= BCRM_EXPOSURE_TIME_MIN_64R,
		.max_offset		= BCRM_EXPOSURE_TIME_MAX_64R,
		.reg_offset		= BCRM_EXPOSURE_TIME_64RW,
		.step_offset	= BCRM_EXPOSURE_TIME_INC_64R,
		.reg_size		= AV_CAM_REG_SIZE,
		.data_size		= AV_CAM_DATA_SIZE_64,
		.type			= V4L2_CTRL_TYPE_INTEGER64,
		.flags			= 0,
	},
	{
		.id			= V4L2_CID_EXPOSURE_ABSOLUTE,
		.attr			= AV_ATTR_EXPOSURE_ABS,
		.min_offset		= BCRM_EXPOSURE_TIME_MIN_64R,
		.max_offset		= BCRM_EXPOSURE_TIME_MAX_64R,
		.reg_offset		= BCRM_EXPOSURE_TIME_64RW,
		.step_offset	= BCRM_EXPOSURE_TIME_INC_64R,
		.reg_size		= AV_CAM_REG_SIZE,
		.data_size		= AV_CAM_DATA_SIZE_64,
		.type			= V4L2_CTRL_TYPE_INTEGER64,
		.flags			= 0,
	},
	{
		.id				= V4L2_CID_GAIN,
		.attr			= AV_ATTR_GAIN,
		.min_offset		= BCRM_GAIN_MIN_64R,
		.max_offset		= BCRM_GAIN_MAX_64R,
		.reg_offset		= BCRM_GAIN_64RW,
		.step_offset	= BCRM_GAIN_INC_64R,
		.reg_size		= AV_CAM_REG_SIZE,
		.data_size		= AV_CAM_DATA_SIZE_64,
		.type			= V4L2_CTRL_TYPE_INTEGER64,
		.flags			= 0,
	},

	{
		.id				= V4L2_CID_HFLIP,
		.attr			= AV_ATTR_REVERSE_X,
		.reg_offset		= BCRM_IMG_REVERSE_X_8RW,
		.reg_size		= AV_CAM_REG_SIZE,
		.data_size		= AV_CAM_DATA_SIZE_8,
		.type			= V4L2_CTRL_TYPE_BOOLEAN,
		.flags			= 0,
	},
	{
		.id				= V4L2_CID_VFLIP,
		.attr			= AV_ATTR_REVERSE_Y,
		.reg_offset		= BCRM_IMG_REVERSE_Y_8RW,
		.reg_size		= AV_CAM_REG_SIZE,
		.data_size		= AV_CAM_DATA_SIZE_8,
		.type			= V4L2_CTRL_TYPE_BOOLEAN,
		.flags			= 0,
	},
	{
		.id			= V4L2_CID_BRIGHTNESS,
		.attr			= AV_ATTR_BRIGHTNESS,
		.min_offset		= BCRM_BLACK_LEVEL_MIN_32R,
		.max_offset		= BCRM_BLACK_LEVEL_MAX_32R,
		.reg_offset		= BCRM_BLACK_LEVEL_32RW,
		.step_offset	= BCRM_BLACK_LEVEL_INC_32R,
		.reg_size		= AV_CAM_REG_SIZE,
		.data_size		= AV_CAM_DATA_SIZE_32,
		.type			= V4L2_CTRL_TYPE_INTEGER,
		.flags			= 0,
	},
	{
		.id				= V4L2_CID_CONTRAST,
		.attr			= AV_ATTR_CONTRAST,
		.min_offset		= BCRM_CONTRAST_VALUE_MIN_32R,
		.max_offset		= BCRM_CONTRAST_VALUE_MAX_32R,
		.reg_offset		= BCRM_CONTRAST_VALUE_32RW,
		.step_offset	= BCRM_CONTRAST_VALUE_INC_32R,
		.reg_size		= AV_CAM_REG_SIZE,
		.data_size		= AV_CAM_DATA_SIZE_32,
		.type			= V4L2_CTRL_TYPE_INTEGER,
		.flags			= 0,
	},
	{
		.id				= V4L2_CID_SATURATION,
		.attr			= AV_ATTR_SATURATION,
		.min_offset		= BCRM_SATURATION_MIN_32R,
		.max_offset		= BCRM_SATURATION_MAX_32R,
		.reg_offset		= BCRM_SATURATION_32RW,
		.step_offset	= BCRM_SATURATION_INC_32R,
		.reg_size		= AV_CAM_REG_SIZE,
		.data_size		= AV_CAM_DATA_SIZE_32,
		.type			= V4L2_CTRL_TYPE_INTEGER,
		.flags			= 0,
	},

	{
		.id				= V4L2_CID_HUE,
		.attr			= AV_ATTR_HUE,
		.min_offset		= BCRM_HUE_MIN_32R,
		.max_offset		= BCRM_HUE_MAX_32R,
		.reg_offset		= BCRM_HUE_32RW,
		.step_offset	= BCRM_HUE_INC_32R,
		.reg_size		= AV_CAM_REG_SIZE,
		.data_size		= AV_CAM_DATA_SIZE_32,
		.type			= V4L2_CTRL_TYPE_INTEGER,
		.flags			= 0,
	},
	{
		.id				= V4L2_CID_AUTO_WHITE_BALANCE,
		.attr			= AV_ATTR_WHITEBALANCE_AUTO,
		.reg_offset		= BCRM_WHITE_BALANCE_AUTO_8RW,
		.reg_size		= AV_CAM_REG_SIZE,
		.data_size		= AV_CAM_DATA_SIZE_8,
		.type			= V4L2_CTRL_TYPE_INTEGER, //V4L2_CTRL_TYPE_BOOLEAN,
		.flags			= 0,
	},
	{
		.id				= V4L2_CID_DO_WHITE_BALANCE,
		.attr			= AV_ATTR_WHITEBALANCE,
		.reg_offset		= BCRM_WHITE_BALANCE_AUTO_8RW,
		.reg_size		= AV_CAM_REG_SIZE,
		.data_size		= AV_CAM_DATA_SIZE_8,
		.type			= V4L2_CTRL_TYPE_BUTTON,
		.flags			= 0,
	},
	{
		.id				= V4L2_CID_RED_BALANCE,
		.attr			= AV_ATTR_RED_BALANCE,
		.min_offset		= BCRM_RED_BALANCE_RATIO_MIN_64R,
		.max_offset		= BCRM_RED_BALANCE_RATIO_MAX_64R,
		.reg_offset		= BCRM_RED_BALANCE_RATIO_64RW,
		.step_offset	= BCRM_RED_BALANCE_RATIO_INC_64R,
		.reg_size		= AV_CAM_REG_SIZE,
		.data_size		= AV_CAM_DATA_SIZE_64,
		.type			= V4L2_CTRL_TYPE_INTEGER64,
		.flags			= 0,
	},
	{
		.id				= V4L2_CID_BLUE_BALANCE,
		.attr			= AV_ATTR_BLUE_BALANCE,
		.min_offset		= BCRM_BLUE_BALANCE_RATIO_MIN_64R,
		.max_offset		= BCRM_BLUE_BALANCE_RATIO_MAX_64R,
		.reg_offset		= BCRM_BLUE_BALANCE_RATIO_64RW,
		.step_offset	= BCRM_BLUE_BALANCE_RATIO_INC_64R,
		.reg_size		= AV_CAM_REG_SIZE,
		.data_size		= AV_CAM_DATA_SIZE_64,
		.type			= V4L2_CTRL_TYPE_INTEGER64,
		.flags			= 0,
	},
	{
		.id				= V4L2_CID_GAMMA,
		.attr			= AV_ATTR_GAMMA,
		.min_offset		= BCRM_GAMMA_MIN_64R,
		.max_offset		= BCRM_GAMMA_MAX_64R,
		.reg_offset		= BCRM_GAMMA_64RW,
		.step_offset	= BCRM_GAMMA_INC_64R,
		.reg_size		= AV_CAM_REG_SIZE,
		.data_size		= AV_CAM_DATA_SIZE_64,
		.type			= V4L2_CTRL_TYPE_INTEGER64,
		.flags			= 0,
	},
	{
		.id				= V4L2_CID_AUTOGAIN,
		.attr			= AV_ATTR_AUTOGAIN,
		.reg_offset		= BCRM_GAIN_AUTO_8RW,
		.reg_size		= AV_CAM_REG_SIZE,
		.data_size		= AV_CAM_DATA_SIZE_8,
		.type			= V4L2_CTRL_TYPE_BOOLEAN,
		.flags			= 0,
	},
	{
		.id				= V4L2_CID_SHARPNESS,
		.attr			= AV_ATTR_SHARPNESS,
		.min_offset		= BCRM_SHARPNESS_MIN_32R,
		.max_offset		= BCRM_SHARPNESS_MAX_32R,
		.reg_offset		= BCRM_SHARPNESS_32RW,
		.step_offset	= BCRM_SHARPNESS_INC_32R,
		.reg_size		= AV_CAM_REG_SIZE,
		.data_size		= AV_CAM_DATA_SIZE_32,
		.type			= V4L2_CTRL_TYPE_INTEGER,
		.flags			= 0,
	},
	{
		.id				= V4L2_CID_EXPOSURE_AUTO,
		.attr			= AV_ATTR_EXPOSURE_AUTO,
		.reg_offset		= BCRM_EXPOSURE_AUTO_8RW,
		.reg_size		= AV_CAM_REG_SIZE,
		.data_size		= AV_CAM_DATA_SIZE_8,
		.type			= V4L2_CTRL_TYPE_MENU,
		.flags			= 0,
	},
    {
            .id				= V4L2_CID_TRIGGER_MODE,
            .attr			= AV_ATTR_TRIGGER_MODE,
            .reg_offset		= BCRM_FRAME_START_TRIGGER_MODE_8RW,
            .reg_size		= AV_CAM_REG_SIZE,
            .data_size		= AV_CAM_DATA_SIZE_8,
            .type			= V4L2_CTRL_TYPE_BOOLEAN,
            .flags			= 0,
            .custom         = true,
            .avt_flags      = AVT_CTRL_STREAM_DISABLED,
    },
    {
            .id				= V4L2_CID_TRIGGER_ACTIVATION,
            .attr			= AV_ATTR_TRIGGER_ACTIVATION,
            .reg_offset		= BCRM_FRAME_START_TRIGGER_ACTIVATION_8RW,
            .reg_size		= AV_CAM_REG_SIZE,
            .data_size		= AV_CAM_DATA_SIZE_8,
            .type			= V4L2_CTRL_TYPE_MENU,
            .flags			= 0,
            .custom         = true,
            .min_value      = 0,
            .max_value      = 4,
            .qmenu          = v4l2_triggeractivation_menu,
            .avt_flags      = AVT_CTRL_STREAM_DISABLED,
    },
    {
            .id				= V4L2_CID_TRIGGER_SOURCE,
            .attr			= AV_ATTR_TRIGGER_SOURCE,
            .reg_offset		= BCRM_FRAME_START_TRIGGER_SOURCE_8RW,
            .reg_size		= AV_CAM_REG_SIZE,
            .data_size		= AV_CAM_DATA_SIZE_8,
            .type			= V4L2_CTRL_TYPE_MENU,
            .flags			= 0,
            .custom         = true,
            .min_value      = 0,
            .max_value      = 4,
            .qmenu          = v4l2_triggersource_menu,
            .avt_flags      = AVT_CTRL_STREAM_DISABLED,
    },
    {
            .id				= V4L2_CID_TRIGGER_SOFTWARE,
            .attr			= AV_ATTR_TRIGGER_SOFTWARE,
            .reg_offset		= BCRM_FRAME_START_TRIGGER_SOFTWARE_8W,
            .reg_size		= AV_CAM_REG_SIZE,
            .data_size		= AV_CAM_DATA_SIZE_8,
            .type			= V4L2_CTRL_TYPE_BUTTON,
            .flags			= V4L2_CTRL_FLAG_INACTIVE,
            .custom         = true,
    },
};


#define AVT_MAX_CTRLS (ARRAY_SIZE(avt_ctrl_mappings))

enum avt_exposure_mode {
	EMODE_MANUAL = 0,
	EMODE_AUTO = 2,
};

struct avt3_dev
{
	struct i2c_client *i2c_client;
	struct v4l2_subdev sd;
	struct mutex lock;

	struct regmap *regmap8;
	struct regmap *regmap16;
	struct regmap *regmap32;
	struct regmap *regmap64;
	
	struct media_pad 		pad;
//	struct media_pad		pads[AVT_CSI2_SENS_PADS_NUM];
	union device_firmware_version_reg cam_firmware_version;
	uint32_t				bcrm_handshake_timeout_ms;
	bool					bcrm_write_handshake;

	struct v4l2_mbus_framefmt fmt;
	bool 			pending_fmt_change;
	bool 			pending_mode_change;
	int 			open_refcnt;
	bool 			is_streaming;
	enum avt_mode 	mode;

	struct v4l2_ctrl_handler	v4l2_ctrl_hdl;
	struct v4l2_ctrl_config		avt3_ctrl_cfg[AVT_MAX_CTRLS];
	struct v4l2_ctrl			*avt3_ctrls[AVT_MAX_CTRLS];

	struct v4l2_fwnode_endpoint v4l2_fwnode_ep; /* the parsed DT endpoint info */
	struct fwnode_handle 		*endpoint;
	
	struct gpio_desc 		*reset_gpio;
	struct gpio_desc		 *pwdn_gpio;

	int power_count;
	//int force_reset_at_close;

	struct v4l2_mbus_framefmt 	mbus_framefmt;
	struct v4l2_captureparm		streamcap;

	struct v4l2_rect		max_rect;
	struct v4l2_rect		min_rect;
	struct v4l2_rect		curr_rect;

	int							pending_hardtreset_request;
	int							pending_softreset_request;
	int 						pending_dphyreset_request;

	bool 						hflip;
	bool 						vflip;
	uint64_t 					gain;
	uint64_t 					exposure_time;
	int							exposure_mode;
	//uint8_t						trigger_mode;	
	struct v4l2_trigger_status	avt_trigger_status;
	
	uint32_t				 	avt_min_clk;
	uint32_t					avt_max_clk;

	const struct avt3_mode_info *current_mode;
	const struct avt3_mode_info *last_mode;
	enum avt3_frame_rate 		current_fr;
	struct v4l2_fract 			frame_interval;

	union cci_reg cci_reg;
	struct gencp_reg gencp_reg;

	//union cci_device_caps_reg 		device_caps;
	union bcrm_feature_inquiry_reg		feature_inquiry_reg;
	union bcrm_avail_mipi_reg 			avail_mipi_reg;
	union bcrm_avail_mipi_reg 			ignore_avail_mipi_reg;
	union bcrm_bayer_inquiry_reg 		bayer_inquiry_reg;
	union bcrm_supported_lanecount_reg	lane_capabilities;

	struct avt_csi_mipi_mode_mapping *available_fmts;
//	uint16_t *available_fmts;
	uint32_t available_fmts_cnt;

	struct list_head requests_queued;
	struct completion bcrm_wrhs_completion;

//	struct delayed_work bcrm_wrhs_dwork;
	struct work_struct 			bcrm_wrhs_work;
	struct workqueue_struct 	*bcrm_wrhs_queue;

// from avt_csi2_priv
	u32						mbus_fmt_code;
	bool 					cross_update;
	struct avt_frame_param 	frmp;
	uint32_t				streamon_delay; 
	uint32_t				force_reset_on_init;

#ifdef BCRM_HS_THREAD
	struct task_struct *bcrm_hs_task;
	struct semaphore 	bcrm_sem;
	struct completion 	bcrm_completion;
#endif
};

struct avt_ctrl {
	__u32		id;
	union {
		__u64	value64;
		struct {
			__u32		value0;
			__u32		value1;
		};
	};
};

#define V4L2_AV_CSI2_BASE								0x1000
#define V4L2_AV_CSI2_WIDTH_R		(V4L2_AV_CSI2_BASE+0x0001)
#define V4L2_AV_CSI2_WIDTH_W		(V4L2_AV_CSI2_BASE+0x0002)
#define V4L2_AV_CSI2_WIDTH_MINVAL_R	(V4L2_AV_CSI2_BASE+0x0003)
#define V4L2_AV_CSI2_WIDTH_MAXVAL_R	(V4L2_AV_CSI2_BASE+0x0004)
#define V4L2_AV_CSI2_WIDTH_INCVAL_R	(V4L2_AV_CSI2_BASE+0x0005)
#define V4L2_AV_CSI2_HEIGHT_R		(V4L2_AV_CSI2_BASE+0x0006)
#define V4L2_AV_CSI2_HEIGHT_W		(V4L2_AV_CSI2_BASE+0x0007)
#define V4L2_AV_CSI2_HEIGHT_MINVAL_R	(V4L2_AV_CSI2_BASE+0x0008)
#define V4L2_AV_CSI2_HEIGHT_MAXVAL_R	(V4L2_AV_CSI2_BASE+0x0009)
#define V4L2_AV_CSI2_HEIGHT_INCVAL_R	(V4L2_AV_CSI2_BASE+0x000A)
#define V4L2_AV_CSI2_PIXELFORMAT_R	(V4L2_AV_CSI2_BASE+0x000B)
#define V4L2_AV_CSI2_PIXELFORMAT_W	(V4L2_AV_CSI2_BASE+0x000C)
#define V4L2_AV_CSI2_PAYLOADSIZE_R	(V4L2_AV_CSI2_BASE+0x000D)
#define V4L2_AV_CSI2_STREAMON_W		(V4L2_AV_CSI2_BASE+0x000E)
#define V4L2_AV_CSI2_STREAMOFF_W	(V4L2_AV_CSI2_BASE+0x000F)
#define V4L2_AV_CSI2_ABORT_W		(V4L2_AV_CSI2_BASE+0x0010)
#define V4L2_AV_CSI2_ACQ_STATUS_R	(V4L2_AV_CSI2_BASE+0x0011)
#define V4L2_AV_CSI2_HFLIP_R		(V4L2_AV_CSI2_BASE+0x0012)
#define V4L2_AV_CSI2_HFLIP_W		(V4L2_AV_CSI2_BASE+0x0013)
#define V4L2_AV_CSI2_VFLIP_R		(V4L2_AV_CSI2_BASE+0x0014)
#define V4L2_AV_CSI2_VFLIP_W		(V4L2_AV_CSI2_BASE+0x0015)
#define V4L2_AV_CSI2_OFFSET_X_W		(V4L2_AV_CSI2_BASE+0x0016)
#define V4L2_AV_CSI2_OFFSET_X_R		(V4L2_AV_CSI2_BASE+0x0017)
#define V4L2_AV_CSI2_OFFSET_X_MIN_R	(V4L2_AV_CSI2_BASE+0x0018)
#define V4L2_AV_CSI2_OFFSET_X_MAX_R	(V4L2_AV_CSI2_BASE+0x0019)
#define V4L2_AV_CSI2_OFFSET_X_INC_R	(V4L2_AV_CSI2_BASE+0x001A)
#define V4L2_AV_CSI2_OFFSET_Y_W		(V4L2_AV_CSI2_BASE+0x001B)
#define V4L2_AV_CSI2_OFFSET_Y_R		(V4L2_AV_CSI2_BASE+0x001C)
#define V4L2_AV_CSI2_OFFSET_Y_MIN_R	(V4L2_AV_CSI2_BASE+0x001D)
#define V4L2_AV_CSI2_OFFSET_Y_MAX_R	(V4L2_AV_CSI2_BASE+0x001E)
#define V4L2_AV_CSI2_OFFSET_Y_INC_R	(V4L2_AV_CSI2_BASE+0x001F)
#define V4L2_AV_CSI2_SENSOR_WIDTH_R	(V4L2_AV_CSI2_BASE+0x0020)
#define V4L2_AV_CSI2_SENSOR_HEIGHT_R	(V4L2_AV_CSI2_BASE+0x0021)
#define V4L2_AV_CSI2_MAX_WIDTH_R	(V4L2_AV_CSI2_BASE+0x0022)
#define V4L2_AV_CSI2_MAX_HEIGHT_R	(V4L2_AV_CSI2_BASE+0x0023)
#define V4L2_AV_CSI2_CURRENTMODE_R	(V4L2_AV_CSI2_BASE+0x0024)
#define V4L2_AV_CSI2_CHANGEMODE_W	(V4L2_AV_CSI2_BASE+0x0025)
#define V4L2_AV_CSI2_BAYER_PATTERN_R	(V4L2_AV_CSI2_BASE+0x0026)
#define V4L2_AV_CSI2_BAYER_PATTERN_W	(V4L2_AV_CSI2_BASE+0x0027)

enum bayer_format {
	bayer_ignore = -1,
	monochrome = 0,
	bayer_gr = 1,
	bayer_rg = 2,
	bayer_gb = 3,
	bayer_bg = 4,
};

struct avt_csi_mipi_mode_mapping {
//        u32   	pixelformat;
        u32   mbus_code;
		u16	  mipi_fmt;
		u32   colorspace;
        u32   fourcc;           /* v4l2 format id */
		enum bayer_format bayer_pattern;
//        int   bpp;
		//bool  valid;
		//bool  enumfmt;
		//int	  idx;
        char  name[32];
#ifdef DEBUG
		char  mb_code_string[32];
#endif
};

struct bcrm_to_v4l2 {
	int64_t min_bcrm;
	int64_t max_bcrm;
	int64_t step_bcrm;
	int32_t min_v4l2;
	int32_t max_v4l2;
	int32_t step_v4l2;
};

#define CLEAR(x)       memset(&(x), 0, sizeof(x))

#define EXP_ABS		100000UL
#define UHZ_TO_HZ	1000000UL

#define CCI_REG_LAYOUT_MINVER_MASK (0x0000ffff)
#define CCI_REG_LAYOUT_MINVER_SHIFT (0)
#define CCI_REG_LAYOUT_MAJVER_MASK (0xffff0000)
#define CCI_REG_LAYOUT_MAJVER_SHIFT (16)

#define CCI_REG_LAYOUT_MINVER	0
#define CCI_REG_LAYOUT_MAJVER	1

#endif
