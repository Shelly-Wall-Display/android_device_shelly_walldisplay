// SPDX-License-Identifier: GPL-2.0
/*
 * AudDrv_Gpio.c  --  Mediatek audio gpio operator
 *
 * Copyright (c) 2020 MediaTek Inc.
 * Author: Shane Chien <shane.chien@mediatek.com>
 */



/*****************************************************************************
 *                     C O M P I L E R   F L A G S
 *****************************************************************************/


/*****************************************************************************
 *                E X T E R N A L   R E F E R E N C E S
 *****************************************************************************/

#if !defined(CONFIG_MTK_LEGACY)
#include <linux/gpio.h>
#include <linux/pinctrl/consumer.h>
#else
#include <mt-plat/mt_gpio.h>
#endif
#include "AudDrv_Gpio.h"

#include <linux/platform_device.h>
#include <linux/of.h>
#include <linux/of_gpio.h>
#include "mt_soc_afe_control.h"

#if !defined(CONFIG_MTK_LEGACY)
struct pinctrl *pinctrlaud;
static int g_extamp_gpio, g_extamp_mode, g_extamp_speech_mode;

enum audio_system_gpio_type {
	GPIO_DEFAULT = 0,
	GPIO_PMIC_MODE0,
	GPIO_PMIC_MODE1,
	GPIO_I2S_MODE0,
	GPIO_I2S_MODE1,
	GPIO_EXTAMP_HIGH,
	GPIO_EXTAMP_LOW,
	GPIO_EXTAMP2_HIGH,
	GPIO_EXTAMP2_LOW,
	GPIO_RCVSPK_HIGH,
	GPIO_RCVSPK_LOW,
	GPIO_NUM
};


struct audio_gpio_attr {
	const char *name;
	bool gpio_prepare;
	struct pinctrl_state *gpioctrl;
};

static struct audio_gpio_attr aud_gpios[GPIO_NUM] = {
	[GPIO_DEFAULT] = {"default", false, NULL},
	[GPIO_PMIC_MODE0] = {"audpmicclk-mode0", false, NULL},
	[GPIO_PMIC_MODE1] = {"audpmicclk-mode1", false, NULL},
	[GPIO_I2S_MODE0] = {"audi2s1-mode0", false, NULL},
	[GPIO_I2S_MODE1] = {"audi2s1-mode1", false, NULL},
	[GPIO_EXTAMP_HIGH] = {"extamp-pullhigh", false, NULL},
	[GPIO_EXTAMP_LOW] = {"extamp-pulllow", false, NULL},
	[GPIO_EXTAMP2_HIGH] = {"extamp2-pullhigh", false, NULL},
	[GPIO_EXTAMP2_LOW] = {"extamp2-pulllow", false, NULL},
	[GPIO_RCVSPK_HIGH] = {"rcvspk-pullhigh", false, NULL},
	[GPIO_RCVSPK_LOW] = {"rcvspk-pulllow", false, NULL},
};

void AudDrv_GPIO_probe(void *dev)
{
	int ret;
	int i = 0;

	struct device_node *np = ((struct device *)dev)->of_node;

	pr_warn("%s\n", __func__);
	g_extamp_gpio = of_get_named_gpio(np, "extamp_gpio", 0);

	if (of_property_read_u32(np, "extamp_mode", &g_extamp_mode)) {
		g_extamp_mode = -1;
		pr_err("Not find extamp_mode\n");
	}

	if (of_property_read_u32(np, "extamp_speech_mode", &g_extamp_speech_mode)) {
		g_extamp_speech_mode = -1;
		pr_err("Not find extamp_speech_mode!\n");
	}

	if (gpio_is_valid(g_extamp_gpio)) {
		ret = devm_gpio_request_one(dev, g_extamp_gpio,
					    GPIOF_OUT_INIT_LOW, "extamp_gpio");
		if(ret)
			pr_err("g_extamp_gpio gpio_request error\n");
	}

	pinctrlaud = devm_pinctrl_get(dev);
	if (IS_ERR(pinctrlaud)) {
		ret = PTR_ERR(pinctrlaud);
		pr_err("Cannot find pinctrlaud!\n");
		return;
	}

	for (i = 0; i < ARRAY_SIZE(aud_gpios); i++) {
		aud_gpios[i].gpioctrl = pinctrl_lookup_state(pinctrlaud, aud_gpios[i].name);
		if (IS_ERR(aud_gpios[i].gpioctrl)) {
			ret = PTR_ERR(aud_gpios[i].gpioctrl);
			pr_err("%s pinctrl_lookup_state %s fail %d\n", __func__, aud_gpios[i].name,
			       ret);
		} else {
			aud_gpios[i].gpio_prepare = true;
		}
	}
#if 0
	pins_default = pinctrl_lookup_state(pinctrlaud, "default");
	if (IS_ERR(pins_default)) {
		ret = PTR_ERR(pins_default);
		dev_err(&pdev->dev, "Cannot find aud pinctrl default!\n");
		return;
	}

	audpmic_mode0 = pinctrl_lookup_state(pinctrlaud, "audpmicclk-mode0");
	if (IS_ERR(audpmic_mode0)) {
		ret = PTR_ERR(audpmic_mode0);
		dev_err(&pdev->dev, "Cannot find pinctrl audpmic_mode0!\n");
		return;
	}

	audpmic_mode1 = pinctrl_lookup_state(pinctrlaud, "audpmicclk-mode1");
	if (IS_ERR(audpmic_mode1)) {
		ret = PTR_ERR(audpmic_mode1);
		dev_err(&pdev->dev, "Cannot find pinctrl audpmic_mode1!\n");
		return;
	}

	audi2s1_mode0 = pinctrl_lookup_state(pinctrlaud, "audi2s1-mode0");
	if (IS_ERR(audi2s1_mode0)) {
		ret = PTR_ERR(audi2s1_mode0);
		dev_err(&pdev->dev, "Cannot find pinctrl audi2s1_mode0!\n");
		return;
	}

	audi2s1_mode1 = pinctrl_lookup_state(pinctrlaud, "audi2s1-mode1");
	if (IS_ERR(audi2s1_mode1)) {
		ret = PTR_ERR(audi2s1_mode1);
		dev_err(&pdev->dev, "Cannot find pinctrl audi2s1_mode1!\n");
		return;
	}


	audextamp_high = pinctrl_lookup_state(pinctrlaud, "extamp-pullhigh");
	if (IS_ERR(audextamp_high)) {
		ret = PTR_ERR(audextamp_high);
		dev_err(&pdev->dev, "Cannot find pinctrl audextamp_high!\n");
		return;
	}


	audextamp_low = pinctrl_lookup_state(pinctrlaud, "extamp-pulllow");
	if (IS_ERR(audextamp_low)) {
		ret = PTR_ERR(audextamp_low);
		dev_err(&pdev->dev, "Cannot find pinctrl audextamp_low!\n");
		return;
	}

	audextamp2_high = pinctrl_lookup_state(pinctrlaud, "extamp2-pullhigh");
	if (IS_ERR(audextamp2_high)) {
		ret = PTR_ERR(audextamp2_high);
		dev_err(&pdev->dev, "Cannot find pinctrl audextamp2_high!\n");
		return;
	}

	audextamp2_low = pinctrl_lookup_state(pinctrlaud, "extamp2-pulllow");
	if (IS_ERR(audextamp2_low)) {
		ret = PTR_ERR(audextamp2_low);
		dev_err(&pdev->dev, "Cannot find pinctrl audextamp2_low!\n");
		return;
	}

	audcvspk_high = pinctrl_lookup_state(pinctrlaud, "rcvspk-pullhigh");
	if (IS_ERR(audcvspk_high)) {
		ret = PTR_ERR(audcvspk_high);
		dev_err(&pdev->dev, "Cannot find pinctrl audcvspk_high!\n");
		return;
	}

	audcvspk_low = pinctrl_lookup_state(pinctrlaud, "rcvspk-pulllow");
	if (IS_ERR(audcvspk_low)) {
		ret = PTR_ERR(audcvspk_low);
		dev_err(&pdev->dev, "Cannot find pinctrl audcvspk_low!\n");
		return;
	}
#endif

}

int ext_amp_gpio_is_valid(void)
{
	if (!gpio_is_valid(g_extamp_gpio))
		return 0;

	if (g_extamp_speech_mode < 0 ||
	    g_extamp_mode < 0)
		return 0;
	else
		return 1;
}

int AudDrv_GPIO_PMIC_Select(int bEnable)
{
	int retval = 0;

	if (bEnable == 1) {
		if (aud_gpios[GPIO_PMIC_MODE1].gpio_prepare) {
			retval =
			    pinctrl_select_state(pinctrlaud, aud_gpios[GPIO_PMIC_MODE1].gpioctrl);
			if (retval)
				pr_err("could not set aud_gpios[GPIO_PMIC_MODE1] pins\n");
		}
	} else {
		if (aud_gpios[GPIO_PMIC_MODE0].gpio_prepare) {
			retval =
			    pinctrl_select_state(pinctrlaud, aud_gpios[GPIO_PMIC_MODE0].gpioctrl);
			if (retval)
				pr_err("could not set aud_gpios[GPIO_PMIC_MODE0] pins\n");
		}

	}
	return retval;
}

int AudDrv_GPIO_I2S_Select(int bEnable)
{
	int retval = 0;

	if (bEnable == 1) {
		if (aud_gpios[GPIO_I2S_MODE1].gpio_prepare) {
			retval =
			    pinctrl_select_state(pinctrlaud, aud_gpios[GPIO_I2S_MODE1].gpioctrl);
			if (retval)
				pr_err("could not set aud_gpios[GPIO_I2S_MODE1] pins\n");
		}
	} else {
		if (aud_gpios[GPIO_I2S_MODE0].gpio_prepare) {
			retval =
			    pinctrl_select_state(pinctrlaud, aud_gpios[GPIO_I2S_MODE0].gpioctrl);
			if (retval)
				pr_err("could not set aud_gpios[GPIO_I2S_MODE0] pins\n");
		}

	}
	return retval;
}

int AudDrv_GPIO_EXTAMP_Select(int bEnable)
{
	int retval = 0;
	int i = 0;
	int loop_cnt = is_speech_active() ? g_extamp_speech_mode: g_extamp_mode;

	if (ext_amp_gpio_is_valid()) {
		if (bEnable) {
			for (i = 0; i < loop_cnt; i++) {
				gpio_set_value(g_extamp_gpio, 0);
				udelay(2);
				gpio_set_value(g_extamp_gpio, 1);
				udelay(2);
			}
		} else {
			gpio_set_value(g_extamp_gpio, 0);
		}
		return retval;
	}

	if (bEnable == 1) {
		if (aud_gpios[GPIO_EXTAMP_HIGH].gpio_prepare) {
			retval =
			    pinctrl_select_state(pinctrlaud, aud_gpios[GPIO_EXTAMP_HIGH].gpioctrl);
			if (retval)
				pr_err("could not set aud_gpios[GPIO_EXTAMP_HIGH] pins\n");
		}
	} else {
		if (aud_gpios[GPIO_EXTAMP_LOW].gpio_prepare) {
			retval =
			    pinctrl_select_state(pinctrlaud, aud_gpios[GPIO_EXTAMP_LOW].gpioctrl);
			if (retval)
				pr_err("could not set aud_gpios[GPIO_EXTAMP_LOW] pins\n");
		}

	}
	return retval;
}

int AudDrv_GPIO_EXTAMP2_Select(int bEnable)
{
	int retval = 0;

	if (bEnable == 1) {
		if (aud_gpios[GPIO_EXTAMP2_HIGH].gpio_prepare) {
			retval =
			    pinctrl_select_state(pinctrlaud, aud_gpios[GPIO_EXTAMP2_HIGH].gpioctrl);
			if (retval)
				pr_err("could not set aud_gpios[GPIO_EXTAMP2_HIGH] pins\n");
		}
	} else {
		if (aud_gpios[GPIO_EXTAMP2_LOW].gpio_prepare) {
			retval =
			    pinctrl_select_state(pinctrlaud, aud_gpios[GPIO_EXTAMP2_LOW].gpioctrl);
			if (retval)
				pr_err("could not set aud_gpios[GPIO_EXTAMP2_LOW] pins\n");
		}

	}
	return retval;
}

int AudDrv_GPIO_RCVSPK_Select(int bEnable)
{
	int retval = 0;

	if (bEnable == 1) {
		if (aud_gpios[GPIO_RCVSPK_HIGH].gpio_prepare) {
			retval =
			    pinctrl_select_state(pinctrlaud, aud_gpios[GPIO_RCVSPK_HIGH].gpioctrl);
			if (retval)
				pr_err("could not set aud_gpios[GPIO_RCVSPK_HIGH] pins\n");
		}
	} else {
		if (aud_gpios[GPIO_RCVSPK_LOW].gpio_prepare) {
			retval =
			    pinctrl_select_state(pinctrlaud, aud_gpios[GPIO_RCVSPK_LOW].gpioctrl);
			if (retval)
				pr_err("could not set aud_gpios[GPIO_RCVSPK_LOW] pins\n");
		}

	}
	return retval;
}

#endif
