/*
 * rtk_chip.h
 *
 * Copyright (c) 2017 Realtek Semiconductor Corp.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 */

#ifndef _RTK_CHIP_H_INCLUDED_
#define _RTK_CHIP_H_INCLUDED_

enum rtd_chip_id {
	CHIP_ID_RTD1195 = 0x1195,
	CHIP_ID_RTD129X = 0x1290,
	CHIP_ID_RTD1293 = 0x1293,
	CHIP_ID_RTD1294 = 0x1294,
	CHIP_ID_RTD1295 = 0x1295,
	CHIP_ID_RTD1296 = 0x1296,
	CHIP_ID_RTD139X = 0x1390,
	CHIP_ID_RTD1392 = 0x1392,
	CHIP_ID_RTD1395 = 0x1395,
	CHIP_ID_RTD161X = 0x1610,
	CHIP_ID_RTD1619 = 0x1619,
	CHIP_ID_RTD131X = 0x1310,
	CHIP_ID_RTD1315 = 0x1315,
	CHIP_ID_RTD1317 = 0x1317,
	CHIP_ID_RTD1319 = 0x1319,
	CHIP_ID_UNKNOWN = 0xFFFF,
};

int get_rtd_chip_id(void);

enum rtd_chip_revision {
	RTD_CHIP_A00 = 0xA00,
	RTD_CHIP_A01 = 0xA01,
	RTD_CHIP_A02 = 0xA02,
	RTD_CHIP_B00 = 0xB00,
	RTD_CHIP_B01 = 0xB01,
	RTD_CHIP_B02 = 0xB02,
	RTD_CHIP_UNKNOWN_REV = 0xFFF,
};

int get_rtd_chip_revision(void);

#endif //_RTK_CHIP_H_INCLUDED_
