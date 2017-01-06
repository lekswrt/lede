/*
    ***************************************************************************
    * Ralink Technology, Corp.
    * 5F., No. 5, Tai-Yuan 1st St., Jhubei City, Hsinchu County 30265, Taiwan
    *
    * (c) Copyright 2002-2011, Ralink Technology, Corp.
    *
    * All rights reserved. Ralink's source code is an unpublished work and the use of a copyright notice 
    * does not imply otherwise. This source code contains confidential trade secret material of 
    * Ralink Technology, Corp. Any attempt or participation in deciphering, decoding, reverse engineering 
    * or in any way altering the source code is stricitly prohibited, unless the prior written consent of 
    * Ralink Technology, Corp. is obtained.
    ***************************************************************************

    Module Name: 
    RT6X9X.c

    Abstract: 
    RT6X9X features (RT6590/RT6592/MT7601)

    Revision History:
    Who                         When            What
    -------------------     ----------      ----------------------------------------------
    ShiuanWen Chen      2012/12/4       MT7610 Power Table implementation
*/
TX_POWER_CONTROL_EXT_OVER_MAC_WITH_VHT VhtTxPwrTableForFCC =
{
  // BW20Over2Dot4GCh1
  0x0e0e1010,
  0x0d0d0e0e,
  0x00000d0d,
  0x0d0d0000,
  0x00000d0d,
  0x000d000e,
  0x0000000d,
  // BW20Over2Dot4GCh6
  0x15151010,
  0x15151515,
  0x00001515,
  0x15150000,
  0x00001515,
  0x00150015,
  0x00000015,
  // BW20Over2Dot4GCh11
  0x0e0e1010,
  0x0d0d0e0e,
  0x00000d0d,
  0x0d0d0000,
  0x00000d0d,
  0x000d000e,
  0x0000000d,
  // BW40Over2Dot4GCh3
  0x0e0e1010,
  0x0c0c0e0e,
  0x00000c0c,
  0x0c0c0000,
  0x00000c0c,
  0x000c000e,
  0x0000000c,
  // BW40Over2Dot4GCh6
  0x15151010,
  0x0f0f1515,
  0x00000f0f,
  0x0f0f0000,
  0x00000f0f,
  0x000f0015,
  0x0000000f,
  // BW40Over2Dot4GCh9
  0x0e0e1010,
  0x0c0c0e0e,
  0x00000c0c,
  0x0c0c0000,
  0x00000c0c,
  0x000c000e,
  0x0000000c,
  // BW20Over5GLow
  0x10100000,
  0x10101010,
  0x00001010,
  0x10100000,
  0x00001010,
  0x00100010,
  0x00000010,
  0x10100000,
  // BW20Over5GMiddle
  0x13130000,
  0x13131313,
  0x00001313,
  0x13130000,
  0x00001313,
  0x00130013,
  0x00000013,
  0x13130000,
  // BW20Over5GHigh
  0x12120000,
  0x10101212,
  0x00001010,
  0x10100000,
  0x00001010,
  0x00100012,
  0x00000010,
  0x10100000,
  // BW20Over5GX1
  0x16160000,
  0x16161616,
  0x00001616,
  0x16160000,
  0x00001616,
  0x00160016,
  0x00000016,
  0x16160000,
  // BW40Over5GLow
  0x10100000,
  0x0c0c1010,
  0x00000c0c,
  0x0c0c0000,
  0x00000c0c,
  0x000c0010,
  0x0000000c,
  0x0c0c0000,
  // BW40Over5GMiddle
  0x13130000,
  0x0e0e1313,
  0x00000e0e,
  0x0e0e0000,
  0x00000e0e,
  0x000e0013,
  0x0000000e,
  0x0e0e0000,
  // BW40Over5GHigh
  0x12120000,
  0x10101212,
  0x00001010,
  0x10100000,
  0x00001010,
  0x00100012,
  0x00000010,
  0x10100000,
  // BW40Over5GX1
  0x16160000,
  0x15151616,
  0x00001515,
  0x15150000,
  0x00001515,
  0x00150016,
  0x00000015,
  0x15150000,
  // BW80Over5GLow
  0x10100000,
  0x09091010,
  0x00000909,
  0x09090000,
  0x00000909,
  0x00090010,
  0x00000009,
  0x09090000,
  // BW80Over5GMiddle
  0x13130000,
  0x0d0d1313,
  0x00000d0d,
  0x0d0d0000,
  0x00000d0d,
  0x000d0013,
  0x0000000d,
  0x0d0d0000,
  // BW80Over5GHigh
  0x12120000,
  0x0d0d1212,
  0x00000d0d,
  0x0d0d0000,
  0x00000d0d,
  0x000d0012,
  0x0000000d,
  0x0d0d0000,
  // BW80Over5GX1
  0x16160000,
  0x15151616,
  0x00001515,
  0x15150000,
  0x00001515,
  0x00150016,
  0x00000015,
  0x15150000,
};

TX_POWER_CONTROL_EXT_OVER_MAC_WITH_VHT VhtTxPwrTableForCE =
{
  // BW20Over2Dot4GCh1
  0x0e0e0e0e,
  0x0e0e0e0e,
  0x00000e0e,
  0x0e0e0000,
  0x00000e0e,
  0x000e000e,
  0x0000000e,
  // BW20Over2Dot4GCh6
  0x0e0e0e0e,
  0x0e0e0e0e,
  0x00000e0e,
  0x0e0e0000,
  0x00000e0e,
  0x000e000e,
  0x0000000e,
  // BW20Over2Dot4GCh11
  0x0e0e0e0e,
  0x0e0e0e0e,
  0x00000e0e,
  0x0e0e0000,
  0x00000e0e,
  0x000e000e,
  0x0000000e,
  // BW40Over2Dot4GCh3
  0x0e0e0e0e,
  0x0e0e0e0e,
  0x00000e0e,
  0x0e0e0000,
  0x00000e0e,
  0x000e000e,
  0x0000000e,
  // BW40Over2Dot4GCh6
  0x0e0e0e0e,
  0x0e0e0e0e,
  0x00000e0e,
  0x0e0e0000,
  0x00000e0e,
  0x000e000e,
  0x0000000e,
  // BW40Over2Dot4GCh9
  0x0e0e0e0e,
  0x0e0e0e0e,
  0x00000e0e,
  0x0e0e0000,
  0x00000e0e,
  0x000e000e,
  0x0000000e,
  // BW20Over5GLow
  0x0f0f0000,
  0x0f0f0f0f,
  0x00000f0f,
  0x0f0f0000,
  0x00000f0f,
  0x000f000f,
  0x0000000f,
  0x0f0f0000,
  // BW20Over5GMiddle
  0x0f0f0000,
  0x0f0f0f0f,
  0x00000f0f,
  0x0f0f0000,
  0x00000f0f,
  0x000f000f,
  0x0000000f,
  0x0f0f0000,
  // BW20Over5GHigh
  0x0f0f0000,
  0x0f0f0f0f,
  0x00000f0f,
  0x0f0f0000,
  0x00000f0f,
  0x000f000f,
  0x0000000f,
  0x0f0f0000,
  // BW20Over5GX1
  0x0f0f0000,
  0x0f0f0f0f,
  0x00000f0f,
  0x0f0f0000,
  0x00000f0f,
  0x000f000f,
  0x0000000f,
  0x0f0f0000,
  // BW40Over5GLow
  0x0f0f0000,
  0x0f0f0f0f,
  0x00000f0f,
  0x0f0f0000,
  0x00000f0f,
  0x000f000f,
  0x0000000f,
  0x0f0f0000,
  // BW40Over5GMiddle
  0x0f0f0000,
  0x0f0f0f0f,
  0x00000f0f,
  0x0f0f0000,
  0x00000f0f,
  0x000f000f,
  0x0000000f,
  0x0f0f0000,
  // BW40Over5GHigh
  0x0f0f0000,
  0x0f0f0f0f,
  0x00000f0f,
  0x0f0f0000,
  0x00000f0f,
  0x000f000f,
  0x0000000f,
  0x0f0f0000,
  // BW40Over5GX1
  0x0f0f0000,
  0x0f0f0f0f,
  0x00000f0f,
  0x0f0f0000,
  0x00000f0f,
  0x000f000f,
  0x0000000f,
  0x0f0f0000,
  // BW80Over5GLow
  0x0f0f0000,
  0x0f0f0f0f,
  0x00000f0f,
  0x0f0f0000,
  0x00000f0f,
  0x000f000f,
  0x0000000f,
  0x0f0f0000,
  // BW80Over5GMiddle
  0x0f0f0000,
  0x10100f0f,
  0x00001010,
  0x10100000,
  0x00001010,
  0x0010000f,
  0x00000010,
  0x10100000,
  // BW80Over5GHigh
  0x0f0f0000,
  0x0f0f0f0f,
  0x00000f0f,
  0x0f0f0000,
  0x00000f0f,
  0x000f000f,
  0x0000000f,
  0x0f0f0000,
  // BW80Over5GX1
  0x0f0f0000,
  0x0f0f0f0f,
  0x00000f0f,
  0x0f0f0000,
  0x00000f0f,
  0x000f000f,
  0x0000000f,
  0x0f0f0000,
};

TX_POWER_CONTROL_EXT_OVER_MAC_WITH_VHT VhtTxPwrTableForAS =
{
  // BW20Over2Dot4GCh1
  0x0e0e0e0e,
  0x0d0d0e0e,
  0x00000d0d,
  0x0d0d0000,
  0x00000d0d,
  0x000d000e,
  0x0000000d,
  // BW20Over2Dot4GCh6
  0x0e0e0e0e,
  0x0e0e0e0e,
  0x00000e0e,
  0x0e0e0000,
  0x00000e0e,
  0x000e000e,
  0x0000000e,
  // BW20Over2Dot4GCh11
  0x0e0e0e0e,
  0x0d0d0e0e,
  0x00000d0d,
  0x0d0d0000,
  0x00000d0d,
  0x000d000e,
  0x0000000d,
  // BW40Over2Dot4GCh3
  0x0e0e0e0e,
  0x0c0c0e0e,
  0x00000c0c,
  0x0c0c0000,
  0x00000c0c,
  0x000c000e,
  0x0000000c,
  // BW40Over2Dot4GCh6
  0x0e0e0e0e,
  0x0e0e0e0e,
  0x00000e0e,
  0x0e0e0000,
  0x00000e0e,
  0x000e000e,
  0x0000000e,
  // BW40Over2Dot4GCh9
  0x0e0e0e0e,
  0x0c0c0e0e,
  0x00000c0c,
  0x0c0c0000,
  0x00000c0c,
  0x000c000e,
  0x0000000c,
  // BW20Over5GLow
  0x0f0f0000,
  0x0f0f0f0f,
  0x00000f0f,
  0x0f0f0000,
  0x00000f0f,
  0x000f000f,
  0x0000000f,
  0x0f0f0000,
  // BW20Over5GMiddle
  0x0f0f0000,
  0x0f0f0f0f,
  0x00000f0f,
  0x0f0f0000,
  0x00000f0f,
  0x000f000f,
  0x0000000f,
  0x0f0f0000,
  // BW20Over5GHigh
  0x0f0f0000,
  0x0f0f0f0f,
  0x00000f0f,
  0x0f0f0000,
  0x00000f0f,
  0x000f000f,
  0x0000000f,
  0x0f0f0000,
  // BW20Over5GX1
  0x0f0f0000,
  0x0f0f0f0f,
  0x00000f0f,
  0x0f0f0000,
  0x00000f0f,
  0x000f000f,
  0x0000000f,
  0x0f0f0000,
  // BW40Over5GLow
  0x0f0f0000,
  0x0c0c0f0f,
  0x00000c0c,
  0x0c0c0000,
  0x00000c0c,
  0x000c000f,
  0x0000000c,
  0x0c0c0000,
  // BW40Over5GMiddle
  0x0f0f0000,
  0x0e0e0f0f,
  0x00000e0e,
  0x0e0e0000,
  0x00000e0e,
  0x000e000f,
  0x0000000e,
  0x0e0e0000,
  // BW40Over5GHigh
  0x0f0f0000,
  0x0f0f0f0f,
  0x00000f0f,
  0x0f0f0000,
  0x00000f0f,
  0x000f000f,
  0x0000000f,
  0x0f0f0000,
  // BW40Over5GX1
  0x0f0f0000,
  0x0f0f0f0f,
  0x00000f0f,
  0x0f0f0000,
  0x00000f0f,
  0x000f000f,
  0x0000000f,
  0x0f0f0000,
  // BW80Over5GLow
  0x0f0f0000,
  0x09090f0f,
  0x00000909,
  0x09090000,
  0x00000909,
  0x0009000f,
  0x00000009,
  0x09090000,
  // BW80Over5GMiddle
  0x0f0f0000,
  0x0d0d0f0f,
  0x00000d0d,
  0x0d0d0000,
  0x00000d0d,
  0x000d000f,
  0x0000000d,
  0x0d0d0000,
  // BW80Over5GHigh
  0x0f0f0000,
  0x0d0d0f0f,
  0x00000d0d,
  0x0d0d0000,
  0x00000d0d,
  0x000d000f,
  0x0000000d,
  0x0d0d0000,
  // BW80Over5GX1
  0x0f0f0000,
  0x0f0f0f0f,
  0x00000f0f,
  0x0f0f0000,
  0x00000f0f,
  0x000f000f,
  0x0000000f,
  0x0f0f0000,
};