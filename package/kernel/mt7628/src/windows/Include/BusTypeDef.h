/*
 ***************************************************************************
 * Ralink Tech Inc.
 * 4F, No. 2 Technology 5th Rd.
 * Science-based Industrial Park
 * Hsin-chu, Taiwan, R.O.C.
 *
 * (c) Copyright 2002-2004, Ralink Technology, Inc.
 *
 * All rights reserved. Ralink's source code is an unpublished work and the
 * use of a copyright notice does not imply otherwise. This source code
 * contains confidential trade secret material of Ralink Tech. Any attemp
 * or participation in deciphering, decoding, reverse engineering or in any
 * way altering the source code is stricitly prohibited, unless the prior
 * written consent of Ralink Technology, Inc. is obtained.
 ***************************************************************************

    Module Name:
    BusTypeDef.h

    Abstract:
    

    Revision History:
    Who         When          What
    --------    ----------    ----------------------------------------------


*/
#ifndef __BUSTYPEDEF_H__
#define __BUSTYPEDEF_H__

//Only use for compiler time.
#define BUS_TYPE_PCI        0x100
#define BUS_TYPE_USB       0x200
#define BUS_TYPE_SDIO      0x400

#define DEV_BUS_TYPE    BUS_TYPE_USB

#endif