//#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#* DtBcIPFIFO.h *#*#*#*#*#*#*#*#*#*# (C) 2018 DekTec
//
// This file is not part of the PCIe driver. It can be used as template to create a new
// block controller. Replace "IPFIFO" by the building block's shortname (all uppercase)
// and replace "Template" by the building block's (long) name.
// 

//-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- License -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

// Copyright (C) 2018 DekTec Digital Video B.V.
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

#ifndef __DT_BC_IPFIFO_H
#define __DT_BC_IPFIFO_H

//.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Include files -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-
#include "DtBc.h"

// Name and short-name of the IpDdrFifo block (must match block ID)
#define DT_BC_IPFIFO_NAME        "IpDdrFifo"
#define DT_BC_IPFIFO_SHORTNAME   "IPFIFO"

// MACRO: to init an block-controller-ID for the IPFIFO-BC
#define DT_BC_IPFIFO_INIT_ID(ID, ROLE, INSTANCE, UUID)                                   \
do                                                                                       \
{                                                                                        \
    DT_BC_INIT_ID(ID, DT_BC_IPFIFO_NAME, DT_BC_IPFIFO_SHORTNAME, ROLE,                   \
                                                                        INSTANCE, UUID); \
}                                                                                        \
while (0)

//+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
//+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+ DtBcIPFIFO definitions +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
//+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=


//-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- DtBcIPFIFO -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
typedef  struct _DtBcIPFIFO
{
    // NOTE: common block data must be the first members to allow casting to DtBc
    DT_BC_COMMON_DATA;

    // Cached settings
    Bool  m_BlockEnabled;
    Int  m_OperationalMode;
}  DtBcIPFIFO;

//.-.-.-.-.-.-.-.-.-.-.-.-.-. DtBcIPFIFO public functions -.-.-.-.-.-.-.-.-.-.-.-.-.-

void  DtBcIPFIFO_Close(DtBc*);
DtBcIPFIFO*  DtBcIPFIFO_Open(Int  Address, DtCore*, DtPt*  pPt, const char*  pRole, 
                                                                Int  Instance, Int  Uuid);
DtStatus DtBcIPFIFO_GetOperationalMode(DtBcIPFIFO* pBc, Int* pOpMode);
DtStatus DtBcIPFIFO_SetOperationalMode(DtBcIPFIFO* pBc, Int OpMode);
DtStatus DtBcIPFIFO_SetFifoAddr(DtBcIPFIFO* pBc, UInt32 FifoAddr);
DtStatus DtBcIPFIFO_SetFifoSize(DtBcIPFIFO* pBc, UInt32 FifoSize);
#endif  // #ifndef __DT_BC_IPFIFO_H
