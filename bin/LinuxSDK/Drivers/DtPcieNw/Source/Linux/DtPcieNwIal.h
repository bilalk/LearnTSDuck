//#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#* DtPcieNwIal.h *#*#*#*#*#*#*#*#* (C) 2011-2016 DekTec
//
// DtPcieNw driver - Definition of the Linux Network driver interface.
//

//-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- License -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

// Copyright (C) 2011-2016 DekTec Digital Video B.V.
//
// Redistribution and use in source and binary forms, with or without modification, are
// permitted provided that the following conditions are met:
//  1. Redistributions of source code must retain the above copyright notice, this list
//     of conditions and the following disclaimer.
//  2. Redistributions in binary format must reproduce the above copyright notice, this
//     list of conditions and the following disclaimer in the documentation.
//
// THIS SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
// INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
// PURPOSE AND NONINFRINGEMENT.
// IN NO EVENT SHALL DEKTEC DIGITAL VIDEO BV, ITS AGENTS OR ITS EMPLOYEES BE LIABLE FOR
// ANY DIRECT, INDIRECT, CONSEQUENTIAL, INCIDENTAL, OR OTHER DAMAGES (INCLUDING DAMAGES
// FOR THE LOSS OF USE, INFORMATION, GOODWILL, PROFIT, WORK STOPPAGE, DATA, BUSINESS OR
// REVENUE) UNDER ANY CIRCUMSTANCES, OR UNDER ANY LEGAL THEORY, WHETHER IN CONTRACT, IN
// TORT, IN NEGLIGENCE, OR OTHERWISE, ARISING FROM THE USE OF, OR INABILITY TO USE THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.

#ifndef __DTPCIENW_IAL_H
#define __DTPCIENW_IAL_H

//-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Includes -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-
//
#include <linux/netdevice.h>
#include <linux/etherdevice.h>
#include <linux/skbuff.h>
#include <linux/ethtool.h>
#include <linux/net_tstamp.h>

#include "DtIal.h" // needed for child devices 
#include "EthPrtcls.h" // needed for EthernetIIHeaderVlan
#include "PtpPkt.h"

//-.-.-.-.-.-.-.-.-.-.- Detect kernel version and check if supported -.-.-.-.-.-.-.-.-.-.-
//
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,14) && LINUX_VERSION_CODE < KERNEL_VERSION(2,6,23)
    #define PERM_ADDR_SUPPORT
#endif

// The GET/SET settings functions are removed from kernel version 4.20
// But for backports, we set the version lower
#if LINUX_VERSION_CODE <= KERNEL_VERSION(4,10,0)
    #define GS_SETTINGS_SUPPORT
#endif

// Linux version < 2.6.19 had a CHECKSUM_HW define
#ifndef CHECKSUM_PARTIAL
    #define  CHECKSUM_PARTIAL  CHECKSUM_HW
#endif

#if LINUX_VERSION_CODE < KERNEL_VERSION(3,0,0)
    #define NO_HW_FEATURE_SUPPORT
#endif

// Linux version < v2.6.23
#ifndef NETIF_F_IPV6_CSUM
    #define NETIF_F_IPV6_CSUM      16
#endif

// Linux version < v2.6.39
#ifndef NETIF_F_RXCSUM
    #define NETIF_F_RXCSUM         (1 << 29)
#endif

// Linux version < v3.4
#ifndef NETIF_F_RXFCS
    #define NETIF_F_RXFCS          0
#endif

#if LINUX_VERSION_CODE < KERNEL_VERSION(3,3,0)
    typedef u32  dt_netdev_features;
#else
    typedef netdev_features_t  dt_netdev_features;
#endif

// The HAVE_NETDEV_PRIV define has been removed from new kernel versions
// The function is still there.
#if LINUX_VERSION_CODE < KERNEL_VERSION(2,6,40)
#ifndef HAVE_NETDEV_PRIV
#define HAVE_NETDEV_PRIV
static inline void *netdev_priv(struct net_device *dev)
{
    return dev->priv;
}
#endif // HAVE_NETDEV_PRIV
#endif // LINUX_VERSION_CODE < KERNEL_VERSION(2,6,40)

#ifndef netdev_mc_count
    #define netdev_mc_count(dev) ((dev)->mc_count)
#endif

//-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Type definitions -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-
//

// DtPcieNwIalData
typedef struct _DtPcieNwIalData
{
    UInt  m_DvcIndex;
    Int  m_Id;
    DtDeviceItf*  m_pDeviceItf;
    struct net_device*  m_pNwDevice;
    struct net_device_stats  m_NetStats;    // Network statistics
    DtDrvObject  m_Driver;
    Bool  m_AutoNegEn;
    struct hwtstamp_config  m_HwTsConfig;
    //Int  m_PtpHwClockIndex;
} DtPcieNwIalData;

//.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Function callbacks to IAL -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-
void  DtPcieNwEvtLinkStatusCallback(DtPcieNwDeviceData* pDvcData);
void  DtPcieNwEvtNewPacketRxCallback(DtPcieNwDeviceData* pDvcData, 
                                 UInt32 TodSeconds, UInt32 TodNanoSeconds, UInt8* pPacket,
                                 UInt PacketSize, UInt RxFlags, DektecTlvs* pDektecTlv);
void  DtPcieNwEvtHwTxTimestampReceived(DtPcieNwDeviceData* pDvcData, void* pPkt, 
                                                UInt32 TodSeconds, UInt32 TodNanoSeconds);
void  DtPcieNwEvtHwTxTimestampNotReceived(DtPcieNwDeviceData* pDvcData, void* pPkt);
void  DtPcieNwAquireLockIal(DtPcieNwDeviceData* pDvcData);
void  DtPcieNwReleaseLockIal(DtPcieNwDeviceData* pDvcData);
#endif // __DTPCIENW_IAL_H
