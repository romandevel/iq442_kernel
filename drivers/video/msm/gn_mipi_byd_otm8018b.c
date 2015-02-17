/* Copyright (c) 2012, The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#define DEBUG

#include <mach/socinfo.h>
#include <linux/gpio.h>
#include "msm_fb.h"
#include "mipi_dsi.h"
#include "gn_mipi_byd_otm8018b.h"
//Gionee xiangzhong 2012-09-19 add for device type check begin
#if defined(CONFIG_GN_DEVICE_TYPE_CHECK)
#include <linux/gn_device_check.h>
extern int gn_set_device_info(struct gn_device_info gn_dev_info);
#endif
//Gionee xiangzhong 2012-09-19 add for device type check end

static struct msm_panel_common_pdata *mipi_video_otm8018b_hsd_dijing_wvga_pdata;
//static struct msm_panel_common_pdata *mipi_video_otm8018b_hsd_dijing_wvga_pdata;
static struct dsi_buf byd_otm8018b_tx_buf;
static struct dsi_buf byd_otm8018b_rx_buf;
static int mipi_video_otm8018b_hsd_dijing_wvga_bl_ctrl = 0;

static char video0[]={
        0x00,0x00
};
static char video1[]={
	0xff,0x80,0x09,0x01
};

static char video2[]={
        0x00,0x80
};

static char video3[]={
	0xff,0x80,0x09
};
static char video6[]={
	0x00,0xb4
};

static char video7[]={
	0xc0,0x10
};

static char video4[]={
	0x00,0x03
};

static char video5[]={
	0xff,0x01
};

static char video8[]={
	0x00,0x82
};

static char video9[]={
        0xc5,0xa3
};

static char video10[]={
       0x00,0x90
};

static char video11[]={
        0xc5,0x96,0x76
};

static char video12[]={
        0x00,0x00
};

static char video13[]={
        0xd8,0x70,0x75
};

static char video14[]={
	0x00,0x00
};

static char video15[]={
	0xd9,0x50
};

static char video16[]={
	0x00,0x00
};

static char video17[]={
 	0xe1,0x00,0x0a,0x0e,0x0d,0x07,0x18,0x0f,0x0e,0x00,0x04,0x03,0x06,0x0d,0x24,0x22,0x19
};

static char video18[]={
	0x00,0x00
};

static char video19[]={
	0xe2,0x00,0x0a,0x0e,0x0d,0x07,0x18,0x0f,0x0e,0x00,0x04,0x03,0x06,0x0d,0x24,0x22,0x19
};

static char video20[]={
	0x00,0x81
};

static char video21[]={
	0xc1,0x77
};

static char video22[]={
	0x00,0xa1
};

static char video23[]={
	0xc1,0x0e
};

static char video24[]={
	0x00,0xa0
};

static char video25[]={
	0xc1,0xea
};

static char video26[]={
	0x00,0x89
};

static char video27[]={
 	0xc4,0x08
};

static char video28[]={
	0x00,0xa2

};

static char video29[]={
	0xc0,0x04,0x00,0x02
};


static char video30[]={
	0x00,0xc6
};

static char video31[]={
	0xb0,0x03
};



static char video32[]={
	0x00,0x80
};

static char video33[]={
	0xc4,0x30
};

static char video34[]={
	0x00,0xa6
};

static char video35[]={
	0xc1,0x01
};

static char video36[]={
	0x00,0xc0
};

static char video37[]={
	0xc5,0x00
};
static char video38[]={
	0x00,0x8b
};

static char video39[]={
	0xb0,0x40
};

static char video40[]={
	0x00,0xb2
};

static char video41[]={
	0xf5,0x15,0x00,0x15,0x00
};

static char video42[]={
	0x00,0x93
};

static char video43[]={
	0xc5,0x03
};

static char video44[]={
	0x00,0x81
};

static char video45[]={
	0xc4,0x83
};

static char video46[]={
	0x00,0x92
};

static char video47[]={
	0xc5,0x01
};

static char video48[]={
	0x00,0xb1
};

static char video49[]={
	0xc5,0xa9
};

static char video50[]={
	0x00,0x92
};

static char video51[]={
	0xb3,0x45
};

static char video52[]={
	0x00,0x90
};

static char video53[]={
	0xb3,0x02
};

static char video54[]={
	0x00,0x80
};

static char video55[]={
	0xc0,0x00,0x58,0x00,0x14,0x16
};

static char video56[]={
	0x00,0x90
};

static char video57[]={
	0xc0,0x00,0x56,0x00,0x00,0x00,0x03
};

static char video58[]={
	0x00,0xa6
};

static char video59[]={
	0xc1,0x01,0x00,0x00
};

static char video60[]={
	0x00,0x80
};

static char video61[]={
	0xce,0x87,0x03,0x00,0x85,0x03,0x00,0x86,0x03,0x00,0x84,0x03,0x00
};

static char video62[]={
	0x00,0xa0
};

static char video63[]={
	0xce,0x38,0x03,0x03,0x58,0x00,0x00,0x00,0x38,0x02,0x03,0x59,0x00,0x00,0x00
};

static char video64[]={
	0x00,0xb0
};

static char video65[]={
	0xce,0x38,0x01,0x03,0x5a,0x00,0x00,0x00,0x38,0x00,0x03,0x5b,0x00,0x00,0x00
};

static char video66[]={
	0x00,0xc0
};

static char video67[]={
	0xce,0x30,0x00,0x03,0x5c,0x00,0x00,0x00,0x30,0x01,0x03,0x5d,0x00,0x00,0x00
};

static char video68[]={
	0x00,0xd0
};

static char video69[]={
	0xce,0x30,0x02,0x03,0x5e,0x00,0x00,0x00,0x30,0x03,0x03,0x5f,0x00,0x00,0x00
};

static char video70[]={
	0x00,0xc7
};

static char video71[]={
	0xcf,0x00
};

static char video72[]={
	0x00,0xc9
};

static char video73[] = {
	0xcf,0x00
};

static char video74[] = {
	0x00,0xc4
};

static char video75[] = {
	0xcb,0x04,0x04,0x04,0x04,0x04,0x04
};

static char video76[] = {
	0x00,0xd9
};

static char video77[] = {
	0xcb,0x04,0x04,0x04,0x04,0x04,0x04
};

static char video78[] = {
	0x00,0x84
};

static char video79[] = {
	0xcc,0x0c,0x0a,0x10,0x0e,0x03,0x04
};

static char video80[] = {
	0x00,0x9e
};

static char video81[] = {
	0xcc,0x0b
};

static char video82[] = {
	0x00,0xa0
};

static char video83[] = {
	0xcc,0x09,0x0f,0x0d,0x01,0x02
};

static char video84[] = {
	0x00,0xb4
};

static char video85[] = {
	0xcc,0x0d,0x0f,0x09,0x0b,0x02,0x01
};

static char video86[] = {
	0x00,0xce
};

static char video87[] = {
	0xcc,0x0e
};

static char video88[] = {
	0x00,0xd0
};

static char video89[] = {
	0xcc,0x10,0x0a,0x0c,0x04,0x03,0x05,0x85
};


static char video90[] = {
	0x00,0x80
};

static char video91[] = {
	0xd6,0x68
};


static char video92[] = {
	0x00,0x00
};

static char video93[] = {
	0xff,0xff,0xff,0xff
};


static char video94[] = {
	0x3A, 0x77,
};

static char video95[] = {
	0x20, 0x00,
};

static char byd_otm8018b_exit_sleep[] = {
        0x11, 0x00,
};

static char byd_otm8018b_display_on[] = {
        0x29, 0x00,
};

static struct dsi_cmd_desc video_display_on_cmds[] = {
        {DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video0), video0},
        {DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video1), video1},
        {DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video2), video2},
        {DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video3), video3},
        {DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video4), video4},
        {DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video5), video5},
        {DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video6), video6},
        {DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video7), video7},
        {DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video8), video8},
        {DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video9), video9},
        {DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video10), video10},
        {DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video11), video11},
        {DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video12), video12},
        {DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video13), video13},
        {DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video14), video14},
        {DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video15), video15},
        {DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video16), video16},
        {DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video17), video17},
        {DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video18), video18},
        {DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video19), video19},
        {DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video20), video20},
        {DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video21), video21},
        {DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video22), video22},
        {DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video23), video23},
        {DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video24), video24},
        {DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video25), video25},
        {DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video26), video26},
        {DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video27), video27},
        {DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video28), video28},
        {DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video29), video29},
        {DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video30), video30},
        {DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video31), video31},
        {DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video32), video32},
        {DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video33), video33},
        {DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video34), video34},
        {DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video35), video35},
        {DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video36), video36},
        {DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video37), video37},
        {DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video38), video38},
        {DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video39), video39},
        {DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video40), video40},
        {DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video41), video41},
        {DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video42), video42},
        {DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video43), video43},
        {DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video44), video44},
        {DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video45), video45},
        {DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video46), video46},
        {DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video47), video47},
        {DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video48), video48},
        {DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video49), video49},
        {DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video50), video50},
        {DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video51), video51},
        {DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video52), video52},
        {DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video53), video53},
        {DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video54), video54},
        {DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video55), video55},
        {DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video56), video56},
        {DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video57), video57},
        {DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video58), video58},
        {DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video59), video59},
        {DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video60), video60},
        {DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video61), video61},
        {DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video62), video62},
        {DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video63), video63},
        {DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video64), video64},
        {DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video65), video65},
        {DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video66), video66},
        {DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video67), video67},
        {DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video68), video68},
        {DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video69), video69},
        {DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video70), video70},
	{DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video71), video71},
	{DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video72), video72},
	{DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video73), video73},
	{DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video74), video74},
	{DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video75), video75},
	{DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video76), video76},
	{DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video77), video77},
	{DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video78), video78},
	{DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video79), video79},
	{DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video80), video80},
	{DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video81), video81},
	{DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video82), video82},
	{DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video83), video83},
	{DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video84), video84},
	{DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video85), video85},
	{DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video86), video86},
	{DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video87), video87},
	{DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video88), video88},
	{DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video89), video89},
	{DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video90), video90},
	{DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video91), video91},
	{DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video92), video92},
	{DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video93), video93},
	{DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video94), video94},
	{DTYPE_GEN_LWRITE, 1, 0, 0, 0, sizeof(video95), video95},
	
        {DTYPE_DCS_WRITE, 1, 0, 0, 120, sizeof(byd_otm8018b_exit_sleep), byd_otm8018b_exit_sleep},
        {DTYPE_DCS_WRITE, 1, 0, 0, 200, sizeof(byd_otm8018b_display_on), byd_otm8018b_display_on},
};

static char byd_otm8018b_set_sleepin[2] = {0x28, 0x00};
static char byd_otm8018b_set_disp_off[2] = {0x10, 0x00};

static struct dsi_cmd_desc video_display_off_cmds[] = {
        {DTYPE_DCS_WRITE, 1, 0, 0, 120, sizeof(byd_otm8018b_set_sleepin), byd_otm8018b_set_sleepin},
        {DTYPE_DCS_WRITE, 1, 0, 0, 10, sizeof(byd_otm8018b_set_disp_off), byd_otm8018b_set_disp_off},
};

static int mipi_video_otm8018b_hsd_dijing_wvga_lcd_on(struct platform_device *pdev)
{
	struct msm_fb_data_type *mfd;
	struct mipi_panel_info *mipi;

	pr_debug("mipi_video_otm8018b_hsd_dijing_wvga_lcd_on E\n");

	mfd = platform_get_drvdata(pdev);
	if (!mfd)
		return -ENODEV;

	if (mfd->key != MFD_KEY)
		return -EINVAL;

	mipi  = &mfd->panel_info.mipi;

	if (!mfd->cont_splash_done) {
		mfd->cont_splash_done = 1;
		return 0;
	}

	if (mipi->mode == DSI_VIDEO_MODE) {
		mipi_dsi_cmds_tx(&byd_otm8018b_tx_buf,
			video_display_on_cmds,
			ARRAY_SIZE(video_display_on_cmds));
	}

	pr_debug("mipi_video_otm8018b_hsd_dijing_wvga_lcd_on X\n");

	return 0;
}

static int mipi_video_otm8018b_hsd_dijing_wvga_lcd_off(struct platform_device *pdev)
{
	struct msm_fb_data_type *mfd;

	pr_debug("mipi_video_otm8018b_hsd_dijing_wvga_lcd_off E\n");

	mfd = platform_get_drvdata(pdev);

	if (!mfd)
		return -ENODEV;
	if (mfd->key != MFD_KEY)
		return -EINVAL;

	mipi_dsi_cmds_tx(&byd_otm8018b_tx_buf, video_display_off_cmds,
			ARRAY_SIZE(video_display_off_cmds));

	pr_debug("mipi_video_otm8018b_hsd_dijing_wvga_lcd_off xx\n");
	return 0;
}

static ssize_t mipi_video_otm8018b_hsd_dijing_wvga_wta_bl_ctrl(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	ssize_t ret = strnlen(buf, PAGE_SIZE);
	int err;

	err =  kstrtoint(buf, 0, &mipi_video_otm8018b_hsd_dijing_wvga_bl_ctrl);
	if (err)
		return ret;

	pr_info("%s: bl ctrl set to %d\n", __func__, mipi_video_otm8018b_hsd_dijing_wvga_bl_ctrl);

	return ret;
}

static DEVICE_ATTR(bl_ctrl, S_IWUSR, NULL, mipi_video_otm8018b_hsd_dijing_wvga_wta_bl_ctrl);

static struct attribute *mipi_video_otm8018b_hsd_dijing_wvga_fs_attrs[] = {
	&dev_attr_bl_ctrl.attr,
	NULL,
};

static struct attribute_group mipi_video_otm8018b_hsd_dijing_wvga_fs_attr_group = {
	.attrs = mipi_video_otm8018b_hsd_dijing_wvga_fs_attrs,
};

static int mipi_video_otm8018b_hsd_dijing_wvga_create_sysfs(struct platform_device *pdev)
{
	int rc;
	struct msm_fb_data_type *mfd = platform_get_drvdata(pdev);

	if (!mfd) {
		pr_err("%s: mfd not found\n", __func__);
		return -ENODEV;
	}
	if (!mfd->fbi) {
		pr_err("%s: mfd->fbi not found\n", __func__);
		return -ENODEV;
	}
	if (!mfd->fbi->dev) {
		pr_err("%s: mfd->fbi->dev not found\n", __func__);
		return -ENODEV;
	}
	rc = sysfs_create_group(&mfd->fbi->dev->kobj,
		&mipi_video_otm8018b_hsd_dijing_wvga_fs_attr_group);
	if (rc) {
		pr_err("%s: sysfs group creation failed, rc=%d\n",
			__func__, rc);
		return rc;
	}

	return 0;
}

static int __devinit mipi_video_otm8018b_hsd_dijing_wvga_lcd_probe(struct platform_device *pdev)
{
	struct platform_device *pthisdev = NULL;
//Gionee xiangzhong 2012-09-19 add for device tpye check begin  
#if defined(CONFIG_GN_DEVICE_TYPE_CHECK) 
	struct gn_device_info gn_mydev_info;
	gn_mydev_info.gn_dev_type = GN_DEVICE_TYPE_LCD;
#endif
//Gionee xiangzhong 2012-09-19 add for device tpye check end
	pr_debug("%s\n", __func__);

	if (pdev->id == 0) {
		mipi_video_otm8018b_hsd_dijing_wvga_pdata = pdev->dev.platform_data;
		if (mipi_video_otm8018b_hsd_dijing_wvga_pdata->bl_lock)
			spin_lock_init(&mipi_video_otm8018b_hsd_dijing_wvga_pdata->bl_spinlock);

                /* SKUD use PWM as backlight control method */
                if(machine_is_msm8625q_skud() || machine_is_msm8625q_evbd()) {
                        mipi_video_otm8018b_hsd_dijing_wvga_bl_ctrl = 1;
                }

		return 0;
	}

	pthisdev = msm_fb_add_device(pdev);
	mipi_video_otm8018b_hsd_dijing_wvga_create_sysfs(pthisdev);

//Gionee xiangzhong 2012-09-19 add for device tpye check begin  
#if defined(CONFIG_GN_DEVICE_TYPE_CHECK) 
	strcpy(gn_mydev_info.name, "BYD_OTM8018B");
	gn_set_device_info(gn_mydev_info);
#endif
//Gionee xiangzhong 2012-09-19 add for device tpye check end
	return 0;
}

static struct platform_driver this_driver = {
	.probe  = mipi_video_otm8018b_hsd_dijing_wvga_lcd_probe,
	.driver = {
		.name   = "mipi_video_otm8018b_hsd_dijing_wvga",
	},
};

static int old_bl_level;

static void mipi_video_otm8018b_hsd_dijing_wvga_set_backlight(struct msm_fb_data_type *mfd)
{
	int bl_level;
	unsigned long flags;
	bl_level = mfd->bl_level;
	if (mipi_video_otm8018b_hsd_dijing_wvga_pdata->bl_lock) {
		if (!mipi_video_otm8018b_hsd_dijing_wvga_bl_ctrl) {
			/* Level received is of range 1 to bl_max,
			   We need to convert the levels to 1
			   to 31 */
			bl_level = (2 * bl_level * 31 + mfd->panel_info.bl_max)
					/(2 * mfd->panel_info.bl_max);
			if (bl_level == old_bl_level)
				return;

			if (bl_level == 0)
				mipi_video_otm8018b_hsd_dijing_wvga_pdata->backlight(0, 1);

			if (old_bl_level == 0)
				mipi_video_otm8018b_hsd_dijing_wvga_pdata->backlight(0, 1);

			spin_lock_irqsave(&mipi_video_otm8018b_hsd_dijing_wvga_pdata->bl_spinlock,
						flags);
			mipi_video_otm8018b_hsd_dijing_wvga_pdata->backlight(bl_level, 0);
			spin_unlock_irqrestore(&mipi_video_otm8018b_hsd_dijing_wvga_pdata->bl_spinlock,
						flags);
			old_bl_level = bl_level;
		} else {
			mipi_video_otm8018b_hsd_dijing_wvga_pdata->backlight(bl_level, 1);
		}
	} else {
		mipi_video_otm8018b_hsd_dijing_wvga_pdata->backlight(bl_level, mipi_video_otm8018b_hsd_dijing_wvga_bl_ctrl);
	}
}

static struct msm_fb_panel_data byd_otm8018b_panel_data = {
	.on	= mipi_video_otm8018b_hsd_dijing_wvga_lcd_on,
	.off = mipi_video_otm8018b_hsd_dijing_wvga_lcd_off,
	.set_backlight = mipi_video_otm8018b_hsd_dijing_wvga_set_backlight,
};

static int ch_used[3];

static int mipi_video_otm8018b_hsd_dijing_wvga_lcd_init(void)
{
	mipi_dsi_buf_alloc(&byd_otm8018b_tx_buf, DSI_BUF_SIZE);
	mipi_dsi_buf_alloc(&byd_otm8018b_rx_buf, DSI_BUF_SIZE);

	return platform_driver_register(&this_driver);
}
int mipi_video_otm8018b_hsd_dijing_wvga_device_register(struct msm_panel_info *pinfo,
					u32 channel, u32 panel)
{
	struct platform_device *pdev = NULL;
	int ret;

	if ((channel >= 3) || ch_used[channel])
		return -ENODEV;

	ch_used[channel] = TRUE;

	ret = mipi_video_otm8018b_hsd_dijing_wvga_lcd_init();
	if (ret) {
		pr_err("mipi_video_otm8018b_hsd_dijing_wvga_lcd_init() failed with ret %u\n", ret);
		return ret;
	}

	pdev = platform_device_alloc("mipi_video_otm8018b_hsd_dijing_wvga", (panel << 8)|channel);
	if (!pdev)
		return -ENOMEM;

	byd_otm8018b_panel_data.panel_info = *pinfo;
	ret = platform_device_add_data(pdev, &byd_otm8018b_panel_data,
				sizeof(byd_otm8018b_panel_data));
	if (ret) {
		pr_debug("%s: platform_device_add_data failed!\n", __func__);
		goto err_device_put;
	}

	ret = platform_device_add(pdev);
	if (ret) {
		pr_debug("%s: platform_device_register failed!\n", __func__);
		goto err_device_put;
	}

	return 0;

err_device_put:
	platform_device_put(pdev);
	return ret;
}
