#ifndef __FRAME_HDR_H__
#define __FRAME_HDR_H__

#define HDR_TRANS_LEN	50

#ifdef RT_BIG_ENDIAN
typedef struct GNU_PACKED _WIFI_INFO_STRUCT{
	UINT32 more_data:1;
	UINT32 wep:1;
	UINT32 ps:1;
	UINT32 qos:1;
	UINT32 eosp:1;
	UINT32 tid:4;
	UINT32 mode:2;
	UINT32 vlan:1;
	UINT32 rev:3;
	UINT32 bssidx:4;
	UINT32 seq_num:12;
}WIFI_INFO_STRUCT;
#else
typedef struct GNU_PACKED _WIFI_INFO_STRUCT{
	UINT32 seq_num:12;
	UINT32 bssidx:4;
	UINT32 rev:3;
	UINT32 vlan:1;
	UINT32 mode:2;
	UINT32 tid:4;
	UINT32 eosp:1;
	UINT32 qos:1;
	UINT32 rdg:1;
	UINT32 ps:1;
	UINT32 wep:1;
	UINT32 more_data:1;
}WIFI_INFO_STRUCT;
#endif /* RT_BIG_ENDIAN */

WIFI_INFO_STRUCT wifi_info[] = {
	/* mode 1 -> AP, mode 2 --> STA */
	/* seq_num,	bssidx,	rsv,	vlan,	mode,	tid,	eosp,	qos,	rdg,	ps,	wep,	more_data*/
	   {0xff,   5,    	0,   	1,    	1,   	3,   	0, 		1,   	0,  	0, 	0, 		0},
};


UINT8 Input_Frame_Hdr[][HDR_TRANS_LEN] = {
/*type, len, vlan, wcid */
#if 0
{1, 14, 0, 0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfF, 0x00, 0x24, 0x6c, 0xB3, 0x12, 0x21, 0x08, 0x00},	/* IP */
{1, 14, 0, 0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfF, 0x00, 0x24, 0x6c, 0xB3, 0x12, 0x22, 0x08, 0x06},	/* ARP */
{1, 14, 0, 0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfF, 0x00, 0x24, 0x6c, 0xB3, 0x12, 0x23, 0x86, 0xDD},	/* IPv6 */
{1, 14, 0, 0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfF, 0x00, 0x24, 0x6c, 0xB3, 0x12, 0x23, 0x88, 0x8E},	/* EAP */
{1, 14, 0, 0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfF, 0x00, 0x24, 0x6c, 0xB3, 0x12, 0x24, 0x81, 0x37},	/* Novell IPX */
{1, 14, 0, 0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfF, 0x00, 0x24, 0x6c, 0xB3, 0x12, 0x25, 0x80, 0xF3},	/* Apple Talk AARP */
{1, 18, 1, 0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfF, 0x00, 0x24, 0x6c, 0xB3, 0x12, 0x26, 0x81, 0x00, 0x20, 0x01, 0x08, 0x00},	/* VLAN */
#else
/************************************ AP LLC/SNAP *********************************/
#if 0
{2, 26, 0, 0, 0x08, 0x02, 0x00, 0x00, 0x33, 0x33, 0x00, 0x00, 0x00, 0x02, 0x00, 0x11, 0x22, 0x33,
			  0x44, 0x50, 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x50, 0x02, 0x08, 0x00}, /* AP w/o LLC - Ether II*/


{2, 32, 0, 0, 0x08, 0x02, 0x00, 0x00, 0x33, 0x33, 0x00, 0x00, 0x00, 0x02, 0x00, 0x11, 0x22, 0x33,
			  0x44, 0x50, 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x50, 0x02, 0xaa, 0xaa, 0x03, 0x00,
			  0x00, 0x00, 0x08, 0x00}, /* AP with LLC - RFC 1042 encapsulation*/

{2, 32, 0, 0, 0x08, 0x02, 0x00, 0x00, 0x33, 0x33, 0x00, 0x00, 0x00, 0x02, 0x00, 0x11, 0x22, 0x33,
			  0x44, 0x50, 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x50, 0x02, 0xaa, 0xaa, 0x03, 0x00,
			  0x00, 0xf8, 0x08, 0x00}, /* AP with LLC - 802.1h tunnel */

{0, 36, 0, 1, 0x88, 0x02, 0x00, 0x00, 0x33, 0x33, 0x00, 0x00, 0x00, 0x02, 0x00, 0x11, 0x22, 0x33,
			  0x44, 0x50, 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x50, 0x02, 0x03, 0x00, 0x00, 0x00, 
			  0xaa, 0xaa, 0x03, 0x00, 0x00, 0x00, 0x08, 0x00}, /* AP + QoS with LLC - RFC 1042 encapsulation*/
{2, 36, 0, 0, 0x88, 0x02, 0x00, 0x00, 0x33, 0x33, 0x00, 0x00, 0x00, 0x02, 0x00, 0x11, 0x22, 0x33,
			  0x44, 0x50, 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x50, 0x02, 0x03, 0x00, 0x00, 0x00, 
			  0xaa, 0xaa, 0x03, 0x00, 0x00, 0xf8, 0x08, 0x00}, /* AP + QoS with LLC - 802.1h tunnel */

{2, 40, 0, 0, 0x88, 0x82, 0x00, 0x00, 0x33, 0x33, 0x00, 0x00, 0x00, 0x02, 0x00, 0x11, 0x22, 0x33,
			  0x44, 0x50, 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x50, 0x02, 0x03, 0x00, 0x00, 0x00, 
			  0x00, 0x00, 0x00, 0x00, 0xaa, 0xaa, 0x03, 0x00, 0x00, 0x00, 0x08, 0x00}, /* AP + QoS + HTC with LLC - RFC 1042 encapsulation*/

{2, 40, 0, 0, 0x88, 0x82, 0x00, 0x00, 0x33, 0x33, 0x00, 0x00, 0x00, 0x02, 0x00, 0x11, 0x22, 0x33,
			  0x44, 0x50, 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x50, 0x02, 0x03, 0x00, 0x00, 0x00, 
			  0x00, 0x00, 0x00, 0x00, 0xaa, 0xaa, 0x03, 0x00, 0x00, 0xf8, 0x08, 0x00}, /* AP + QoS + HTC with LLC - 802.1h tunnel */

{2, 40, 0, 0, 0x88, 0x82, 0x00, 0x00, 0x33, 0x33, 0x00, 0x00, 0x00, 0x02, 0x00, 0x11, 0x22, 0x33,
			  0x44, 0x50, 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x50, 0x02, 0x03, 0x00, 0x00, 0x00, 
			  0x00, 0x00, 0x00, 0x00, 0xaa, 0xaa, 0x03, 0x00, 0x00, 0x00, 0x81, 0x37}, /* AP + QoS + HTC with LLC - RFC 1042 encapsulation + IPX*/

{2, 40, 0, 0, 0x88, 0x82, 0x00, 0x00, 0x33, 0x33, 0x00, 0x00, 0x00, 0x02, 0x00, 0x11, 0x22, 0x33,
			  0x44, 0x50, 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x50, 0x02, 0x03, 0x00, 0x00, 0x00, 
			  0x00, 0x00, 0x00, 0x00, 0xaa, 0xaa, 0x03, 0x00, 0x00, 0x00, 0x80, 0xf3}, /* AP + QoS + HTC with LLC - RFC 1042 encapsulation + IPX*/

{2, 40, 0, 0, 0x88, 0x82, 0x00, 0x00, 0x33, 0x33, 0x00, 0x00, 0x00, 0x02, 0x00, 0x11, 0x22, 0x33,
			  0x44, 0x50, 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x50, 0x02, 0x03, 0x00, 0x00, 0x00, 
			  0x00, 0x00, 0x00, 0x00, 0xaa, 0xaa, 0x03, 0x00, 0x00, 0x00, 0x88, 0x8E}, /* AP + QoS + HTC with LLC - RFC 1042 encapsulation + EAP */

{2, 40, 0, 0, 0x88, 0x82, 0x00, 0x00, 0x33, 0x33, 0x00, 0x00, 0x00, 0x02, 0x00, 0x11, 0x22, 0x33,
			  0x44, 0x50, 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x50, 0x02, 0x03, 0x00, 0x00, 0x00, 
			  0x00, 0x00, 0x00, 0x00, 0xaa, 0xaa, 0x03, 0x00, 0x00, 0x00, 0x89, 0x0D}, /* AP + QoS + HTC with LLC - RFC 1042 encapsulation + TDLS */
/*********************************** STA LLC/SNAP *******************************/

{2, 26, 0, 0, 0x08, 0x01, 0x00, 0x00, 0x33, 0x33, 0x00, 0x00, 0x00, 0x02, 0x00, 0x11, 0x22, 0x33,
			  0x44, 0x50, 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x50, 0x02, 0x08, 0x00}, /* AP w/o LLC - Ether II*/

{2, 32, 0, 0, 0x08, 0x01, 0x00, 0x00, 0x33, 0x33, 0x00, 0x00, 0x00, 0x02, 0x00, 0x11, 0x22, 0x33,
			  0x44, 0x50, 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x50, 0x02, 0xaa, 0xaa, 0x03, 0x00,
			  0x00, 0x00, 0x08, 0x00}, /* AP with LLC - RFC 1042 encapsulation*/

{2, 32, 0, 0, 0x08, 0x01, 0x00, 0x00, 0x33, 0x33, 0x00, 0x00, 0x00, 0x02, 0x00, 0x11, 0x22, 0x33,
			  0x44, 0x50, 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x50, 0x02, 0xaa, 0xaa, 0x03, 0x00,
			  0x00, 0xf8, 0x08, 0x00}, /* AP with LLC - 802.1h tunnel */

{2, 36, 0, 0, 0x88, 0x01, 0x00, 0x00, 0x33, 0x33, 0x00, 0x00, 0x00, 0x02, 0x00, 0x11, 0x22, 0x33,
			  0x44, 0x50, 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x50, 0x02, 0x03, 0x00, 0x00, 0x00, 
			  0xaa, 0xaa, 0x03, 0x00, 0x00, 0x00, 0x08, 0x00}, /* AP + QoS with LLC - RFC 1042 encapsulation*/

{2, 36, 0, 0, 0x88, 0x01, 0x00, 0x00, 0x33, 0x33, 0x00, 0x00, 0x00, 0x02, 0x00, 0x11, 0x22, 0x33,
			  0x44, 0x50, 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x50, 0x02, 0x03, 0x00, 0x00, 0x00, 
			  0xaa, 0xaa, 0x03, 0x00, 0x00, 0xf8, 0x08, 0x00}, /* AP + QoS with LLC - 802.1h tunnel */

{2, 40, 0, 0, 0x88, 0x81, 0x00, 0x00, 0x33, 0x33, 0x00, 0x00, 0x00, 0x02, 0x00, 0x11, 0x22, 0x33,
			  0x44, 0x50, 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x50, 0x02, 0x03, 0x00, 0x00, 0x00, 
			  0x00, 0x00, 0x00, 0x00, 0xaa, 0xaa, 0x03, 0x00, 0x00, 0x00, 0x08, 0x00}, /* AP + QoS + HTC with LLC - RFC 1042 encapsulation*/

{2, 40, 0, 0, 0x88, 0x81, 0x00, 0x00, 0x33, 0x33, 0x00, 0x00, 0x00, 0x02, 0x00, 0x11, 0x22, 0x33,
			  0x44, 0x50, 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x50, 0x02, 0x03, 0x00, 0x00, 0x00, 
			  0x00, 0x00, 0x00, 0x00, 0xaa, 0xaa, 0x03, 0x00, 0x00, 0xf8, 0x08, 0x00}, /* AP + QoS + HTC with LLC - 802.1h tunnel */

{2, 40, 0, 0, 0x88, 0x81, 0x00, 0x00, 0x33, 0x33, 0x00, 0x00, 0x00, 0x02, 0x00, 0x11, 0x22, 0x33,
			  0x44, 0x50, 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x50, 0x02, 0x03, 0x00, 0x00, 0x00, 
			  0x00, 0x00, 0x00, 0x00, 0xaa, 0xaa, 0x03, 0x00, 0x00, 0x00, 0x81, 0x37}, /* AP + QoS + HTC with LLC - RFC 1042 encapsulation + IPX*/

{2, 40, 0, 0, 0x88, 0x81, 0x00, 0x00, 0x33, 0x33, 0x00, 0x00, 0x00, 0x02, 0x00, 0x11, 0x22, 0x33,
			  0x44, 0x50, 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x50, 0x02, 0x03, 0x00, 0x00, 0x00, 
			  0x00, 0x00, 0x00, 0x00, 0xaa, 0xaa, 0x03, 0x00, 0x00, 0x00, 0x80, 0xf3}, /* AP + QoS + HTC with LLC - RFC 1042 encapsulation + IPX*/

{2, 40, 0, 0, 0x88, 0x81, 0x00, 0x00, 0x33, 0x33, 0x00, 0x00, 0x00, 0x02, 0x00, 0x11, 0x22, 0x33,
			  0x44, 0x50, 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x50, 0x02, 0x03, 0x00, 0x00, 0x00, 
			  0x00, 0x00, 0x00, 0x00, 0xaa, 0xaa, 0x03, 0x00, 0x00, 0x00, 0x88, 0x8E}, /* AP + QoS + HTC with LLC - RFC 1042 encapsulation + EAP */

{2, 40, 0, 0, 0x88, 0x81, 0x00, 0x00, 0x33, 0x33, 0x00, 0x00, 0x00, 0x02, 0x00, 0x11, 0x22, 0x33,
			  0x44, 0x50, 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x50, 0x02, 0x03, 0x00, 0x00, 0x00, 
			  0x00, 0x00, 0x00, 0x00, 0xaa, 0xaa, 0x03, 0x00, 0x00, 0x00, 0x89, 0x0D}, /* AP + QoS + HTC with LLC - RFC 1042 encapsulation + TDLS */
/*********************************** AdHoc LLC/SNAP ****************************/
{2, 26, 0, 0, 0x08, 0x00, 0x00, 0x00, 0x33, 0x33, 0x00, 0x00, 0x00, 0x02, 0x00, 0x11, 0x22, 0x33,
			  0x44, 0x50, 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x50, 0x02, 0x08, 0x00}, /* AP w/o LLC - Ether II*/

{2, 32, 0, 0, 0x08, 0x00, 0x00, 0x00, 0x33, 0x33, 0x00, 0x00, 0x00, 0x02, 0x00, 0x11, 0x22, 0x33,
			  0x44, 0x50, 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x50, 0x02, 0xaa, 0xaa, 0x03, 0x00,
			  0x00, 0x00, 0x08, 0x00}, /* AP with LLC - RFC 1042 encapsulation*/

{2, 32, 0, 0, 0x08, 0x00, 0x00, 0x00, 0x33, 0x33, 0x00, 0x00, 0x00, 0x02, 0x00, 0x11, 0x22, 0x33,
			  0x44, 0x50, 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x50, 0x02, 0xaa, 0xaa, 0x03, 0x00,
			  0x00, 0xf8, 0x08, 0x00}, /* AP with LLC - 802.1h tunnel */

{2, 36, 0, 0, 0x88, 0x00, 0x00, 0x00, 0x33, 0x33, 0x00, 0x00, 0x00, 0x02, 0x00, 0x11, 0x22, 0x33,
			  0x44, 0x50, 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x50, 0x02, 0x03, 0x00, 0x00, 0x00, 
			  0xaa, 0xaa, 0x03, 0x00, 0x00, 0x00, 0x08, 0x00}, /* AP + QoS with LLC - RFC 1042 encapsulation*/

{2, 36, 0, 0, 0x88, 0x00, 0x00, 0x00, 0x33, 0x33, 0x00, 0x00, 0x00, 0x02, 0x00, 0x11, 0x22, 0x33,
			  0x44, 0x50, 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x50, 0x02, 0x03, 0x00, 0x00, 0x00, 
			  0xaa, 0xaa, 0x03, 0x00, 0x00, 0xf8, 0x08, 0x00}, /* AP + QoS with LLC - 802.1h tunnel */

{2, 40, 0, 0, 0x88, 0x80, 0x00, 0x00, 0x33, 0x33, 0x00, 0x00, 0x00, 0x02, 0x00, 0x11, 0x22, 0x33,
			  0x44, 0x50, 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x50, 0x02, 0x03, 0x00, 0x00, 0x00, 
			  0x00, 0x00, 0x00, 0x00, 0xaa, 0xaa, 0x03, 0x00, 0x00, 0x00, 0x08, 0x00}, /* AP + QoS + HTC with LLC - RFC 1042 encapsulation*/

{2, 40, 0, 0, 0x88, 0x80, 0x00, 0x00, 0x33, 0x33, 0x00, 0x00, 0x00, 0x02, 0x00, 0x11, 0x22, 0x33,
			  0x44, 0x50, 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x50, 0x02, 0x03, 0x00, 0x00, 0x00, 
			  0x00, 0x00, 0x00, 0x00, 0xaa, 0xaa, 0x03, 0x00, 0x00, 0xf8, 0x08, 0x00}, /* AP + QoS + HTC with LLC - 802.1h tunnel */

{2, 40, 0, 0, 0x88, 0x80, 0x00, 0x00, 0x33, 0x33, 0x00, 0x00, 0x00, 0x02, 0x00, 0x11, 0x22, 0x33,
			  0x44, 0x50, 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x50, 0x02, 0x03, 0x00, 0x00, 0x00, 
			  0x00, 0x00, 0x00, 0x00, 0xaa, 0xaa, 0x03, 0x00, 0x00, 0x00, 0x81, 0x37}, /* AP + QoS + HTC with LLC - RFC 1042 encapsulation + IPX*/

{2, 40, 0, 0, 0x88, 0x80, 0x00, 0x00, 0x33, 0x33, 0x00, 0x00, 0x00, 0x02, 0x00, 0x11, 0x22, 0x33,
			  0x44, 0x50, 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x50, 0x02, 0x03, 0x00, 0x00, 0x00, 
			  0x00, 0x00, 0x00, 0x00, 0xaa, 0xaa, 0x03, 0x00, 0x00, 0x00, 0x80, 0xf3}, /* AP + QoS + HTC with LLC - RFC 1042 encapsulation + IPX*/

{2, 40, 0, 0, 0x88, 0x80, 0x00, 0x00, 0x33, 0x33, 0x00, 0x00, 0x00, 0x02, 0x00, 0x11, 0x22, 0x33,
			  0x44, 0x50, 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x50, 0x02, 0x03, 0x00, 0x00, 0x00, 
			  0x00, 0x00, 0x00, 0x00, 0xaa, 0xaa, 0x03, 0x00, 0x00, 0x00, 0x88, 0x8E}, /* AP + QoS + HTC with LLC - RFC 1042 encapsulation + EAP */

{2, 40, 0, 0, 0x88, 0x80, 0x00, 0x00, 0x33, 0x33, 0x00, 0x00, 0x00, 0x02, 0x00, 0x11, 0x22, 0x33,
			  0x44, 0x50, 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x50, 0x02, 0x03, 0x00, 0x00, 0x00, 
			  0x00, 0x00, 0x00, 0x00, 0xaa, 0xaa, 0x03, 0x00, 0x00, 0x00, 0x89, 0x0D}, /* AP + QoS + HTC with LLC - RFC 1042 encapsulation + TDLS */
#endif
/************************************ WDS LLC/SNAP ******************************/
{0, 34, 0, 1, 0x08, 0x03, 0x00, 0x00, 0x33, 0x33, 0x00, 0x00, 0x00, 0x02, 0x00, 0x11, 0x22, 0x33,
			  0x44, 0x50, 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x50, 0x02, 0x00, 0xee, 0xee, 0xee,
			  0xee, 0xee, 0x00, 0x00, 0x08, 0x00}, /* AP w/o LLC - Ether II*/

#if 0
{0, 40, 0, 1, 0x08, 0x03, 0x00, 0x00, 0x33, 0x33, 0x00, 0x00, 0x00, 0x02, 0x00, 0x11, 0x22, 0x33,
			  0x44, 0x50, 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x50, 0x02, 0x00, 0xee, 0xee, 0xee,
			  0xee, 0xee, 0x00, 0x00, 0xaa, 0xaa, 0x03, 0x00, 0x00, 0x00, 0x08, 0x00}, /* AP with LLC - RFC 1042 encapsulation*/

{2, 40, 0, 1, 0x08, 0x03, 0x00, 0x00, 0x33, 0x33, 0x00, 0x00, 0x00, 0x02, 0x00, 0x11, 0x22, 0x33,
			  0x44, 0x50, 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x50, 0x02, 0x00, 0xee, 0xee, 0xee,
			  0xee, 0xee, 0x00, 0x00, 0xaa, 0xaa, 0x03, 0x00, 0x00, 0xf8, 0x08, 0x00}, /* AP with LLC - 802.1h tunnel */

{2, 40, 0, 0, 0x88, 0x03, 0x00, 0x00, 0x33, 0x33, 0x00, 0x00, 0x00, 0x02, 0x00, 0x11, 0x22, 0x33,
			  0x44, 0x50, 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x50, 0x02, 0x00, 0xee, 0xee, 0xee,
			  0xee, 0xee, 0x03, 0x00, 0xaa, 0xaa, 0x03, 0x00, 0x00, 0x00, 0x08, 0x00}, /* AP + QoS with LLC - RFC 1042 encapsulation*/

{2, 40, 0, 0, 0x88, 0x03, 0x00, 0x00, 0x33, 0x33, 0x00, 0x00, 0x00, 0x02, 0x00, 0x11, 0x22, 0x33,
			  0x44, 0x50, 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x50, 0x02, 0x00, 0xee, 0xee, 0xee,
			  0xee, 0xee, 0x03, 0x00, 0xaa, 0xaa, 0x03, 0x00, 0x00, 0xf8, 0x08, 0x00}, /* AP + QoS with LLC - 802.1h tunnel */

{2, 44, 0, 0, 0x88, 0x83, 0x00, 0x00, 0x33, 0x33, 0x00, 0x00, 0x00, 0x02, 0x00, 0x11, 0x22, 0x33,
			  0x44, 0x50, 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x50, 0x02, 0x00, 0xee, 0xee, 0xee,
			  0xee, 0xee, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0xaa, 0xaa, 0x03, 0x00, 
			  0x00, 0x00, 0x08, 0x00}, /* AP + QoS + HTC with LLC - RFC 1042 encapsulation*/

{2, 44, 0, 0, 0x88, 0x83, 0x00, 0x00, 0x33, 0x33, 0x00, 0x00, 0x00, 0x02, 0x00, 0x11, 0x22, 0x33,
			  0x44, 0x50, 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x50, 0x02, 0x00, 0xee, 0xee, 0xee,
			  0xee, 0xee, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0xaa, 0xaa, 0x03, 0x00, 
			  0x00, 0xf8, 0x08, 0x00}, /* AP + QoS + HTC with LLC - 802.1h tunnel */

{2, 44, 0, 0, 0x88, 0x83, 0x00, 0x00, 0x33, 0x33, 0x00, 0x00, 0x00, 0x02, 0x00, 0x11, 0x22, 0x33,
			  0x44, 0x50, 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x50, 0x02, 0x00, 0xee, 0xee, 0xee,
			  0xee, 0xee, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0xaa, 0xaa, 0x03, 0x00, 
			  0x00, 0x00, 0x81, 0x37}, /* AP + QoS + HTC with LLC - RFC 1042 encapsulation + IPX*/

{2, 44, 0, 0, 0x88, 0x83, 0x00, 0x00, 0x33, 0x33, 0x00, 0x00, 0x00, 0x02, 0x00, 0x11, 0x22, 0x33,
			  0x44, 0x50, 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x50, 0x02, 0x00, 0xee, 0xee, 0xee,
			  0xee, 0xee, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0xaa, 0xaa, 0x03, 0x00, 
			  0x00, 0x00, 0x80, 0xf3}, /* AP + QoS + HTC with LLC - RFC 1042 encapsulation + IPX*/

{2, 44, 0, 0, 0x88, 0x83, 0x00, 0x00, 0x33, 0x33, 0x00, 0x00, 0x00, 0x02, 0x00, 0x11, 0x22, 0x33,
			  0x44, 0x50, 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x50, 0x02, 0x00, 0xee, 0xee, 0xee,
			  0xee, 0xee, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0xaa, 0xaa, 0x03, 0x00, 
			  0x00, 0x00, 0x88, 0x8E}, /* AP + QoS + HTC with LLC - RFC 1042 encapsulation + EAP */

{2, 44, 0, 0, 0x88, 0x83, 0x00, 0x00, 0x33, 0x33, 0x00, 0x00, 0x00, 0x02, 0x00, 0x11, 0x22, 0x33,
			  0x44, 0x50, 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x50, 0x02, 0x00, 0xee, 0xee, 0xee,
			  0xee, 0xee, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0xaa, 0xaa, 0x03, 0x00, 
			  0x00, 0x00, 0x89, 0x0D}, /* AP + QoS + HTC with LLC - RFC 1042 encapsulation + TDLS */
#endif
#endif
};

UINT8 Hdr_Bssid[] = { 0x00, 0x11, 0x22, 0x33, 0x44, 0x55};

UINT8 Hdr_Wcid[][6] = { 
						{0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, //0
						{0x00, 0x77, 0x77, 0x77, 0x77, 0x77}, //1
						{0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x01}, //2
						{0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x02}, //3
						{0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x03}, //4
						{0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x04}, //5
						{0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x05}, //6
						{0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x06}, //7
						{0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x07}, //8
						{0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x08}, //9
						{0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x09}, //a
						{0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x0a}, //b
						{0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x0b}, //c
						{0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x0c}, //d
						{0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x0d}, //e
						{0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x0e}, //f
					};
UINT8 MAC_WCID[6] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff};

//UINT32 RX_Black_List[] = {0x0d898e88}; /* EAPOL 888E, TDLS 890D */
//UINT32 RX_Black_List[] = {0x888e0800}; /* EAPOL 888E, TDLS 890D */
UINT32 RX_Black_List[] = {}; /* EAPOL 888E, TDLS 890D */
UINT32 TCI[] = {0x10021001, 0x10041003, 0x10061005, 0x10081007};
UINT32 RX_WCID_En[] = {0xFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
#endif
