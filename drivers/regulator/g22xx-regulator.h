/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * G22XX series PMIC regulator common
 *
 * Copyright (C) 2017-2019 Realtek Semiconductor Corporation
 * Author: Cheng-Yu Lee <cylee12@realtek.com>
 */

#ifndef __G22XX_REGULATOR_H
#define __G22XX_REGULATOR_H

#include <linux/i2c.h>
#include <linux/bitops.h>
#include <linux/list.h>
#include <linux/regulator/driver.h>
#include <linux/regulator/machine.h>
#include <linux/regmap.h>
#include <dt-bindings/regulator/gmt,g22xx.h>
#include <linux/mfd/g22xx.h>

struct g22xx_regulator_desc {
	struct regulator_desc desc;
	u8 nmode_reg;
	u8 nmode_mask;
	u8 smode_reg;
	u8 smode_mask;
	u8 svsel_reg;
	u8 svsel_mask;
};

struct g22xx_regulator_data {
	struct list_head list;
	struct regulator_dev *rdev;
	struct g22xx_regulator_desc *gd;

	struct regmap_field *svsel;
	struct regmap_field *nmode;
	struct regmap_field *smode;

	struct regulator_state state_mem;
	struct regulator_state state_coldboot;

	u32 fixed_uV;
};

struct g22xx_regulator_device {
	struct device *dev;
	struct regmap *regmap;
	struct list_head list;
};

extern const struct regulator_ops g22xx_regulator_ops;
extern const struct regulator_ops g22xx_regulator_fixed_uV_ops;

int g22xx_regulator_of_parse_cb(struct device_node *np,
				const struct regulator_desc *desc,
				struct regulator_config *config);
unsigned int g22xx_regulator_dc_of_map_mode(unsigned int mode);
unsigned int g22xx_regulator_ldo_of_map_mode(unsigned int mode);
int g22xx_regulator_set_state(struct regulator_dev *rdev, int is_coldboot);
struct regulator_dev *g22xx_regulator_register(
		struct g22xx_regulator_device *grdev,
		struct g22xx_regulator_desc *gd);

static inline int g22xx_regulator_type_is_ldo(struct g22xx_regulator_desc *gd)
{
	return gd->desc.of_map_mode == g22xx_regulator_ldo_of_map_mode;
}


#endif
