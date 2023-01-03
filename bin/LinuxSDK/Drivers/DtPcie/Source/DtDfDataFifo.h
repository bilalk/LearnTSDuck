// #*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#* DtDfDataFifo.h *#*#*#*#*#*#*#*# (C) 2018-2021 DekTec
//
// This file is not part of the driver. It can be used as template to create a new
// driver function. Replace "DataFifo" by the driver function name (as in the 
// .FunctionDescriptionsXxx.xml), replace "DATAFIFO" by the driver function short name 
// (all uppercase) and replace "DATAFIFO" by the driver function short name in camel case.
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

#ifndef __DT_DF_DATAFIFO_H
#define __DT_DF_DATAFIFO_H

//.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Include files -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-
#include "DtDf.h"
#include "DtBcDATAFIFO.h"
#include "DtBcDDRFRONT.h"

// Name + short-name for the DATAFIFO function. NOTE: must match names in 
// FunctionDescriptionsXxx.xml
#define DT_DF_DATAFIFO_NAME          "DataFifo"
#define DT_DF_DATAFIFO_SHORTNAME     "DATAFIFO"

// MACRO: to init an driver-function-ID for the DATAFIFO-DF
#define DT_DF_DATAFIFO_INIT_ID(ID, ROLE, INSTANCE, UUID)                                 \
do                                                                                       \
{                                                                                        \
    DT_DF_INIT_ID(ID, DT_DF_DATAFIFO_NAME, DT_DF_DATAFIFO_SHORTNAME, ROLE,               \
                                                                     INSTANCE, UUID);    \
}                                                                                        \
while (0)


//+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
//-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- DtDfDataFifo definitions -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-
//+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=


//-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- DtDfDataFifo -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-
typedef struct  _DtDfDataFifo
{
    // NOTE: common func data must be the first members to allow casting to DtDf
    DT_DF_COMMON_DATA;

    // Parameters
    Int  m_FifoAddr;       // bytes
    Int  m_FifoSize;    // bytes
    Int  m_BurstSize;   // bytes
    Int  m_MaxFifoSize; // bytes
    Int  m_Capabilities;
    Int  m_DataWidth;      // bits
    Int  m_NumBytesPerDataWord;

    // Block controllers
    DtBcDATAFIFO*  m_pBcDataFifo; // Data Fifo block-controller
    DtBcDDRFRONT*  m_pBcDdrFront;     // DDR memory controller

    // Cached values
    Int  m_OperationalMode;         // Operational mode
}  DtDfDataFifo;

//-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Public functions -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-
void  DtDfDataFifo_Close(DtDf*);
DtDfDataFifo*  DtDfDataFifo_Open(DtCore*, DtPt*  pPt, const char*  pRole,
                                             Int  Instance,  Int  Uuid, Bool  CreateStub);
DtStatus  DtDfDataFifo_GetOperationalMode(DtDfDataFifo*, Int*  pOpMode);
DtStatus  DtDfDataFifo_SetOperationalMode(DtDfDataFifo*, Int OpMode);

//+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
//=+=+=+=+=+=+=+=+=+=+=+=+=+=+ DtIoStubDfDataFifo definitions +=+=+=+=+=+=+=+=+=+=+=+=+=+=
//+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=

//.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- DtIoStubDfDataFifo -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
//  Io-control stub for an DATAFIFO Driver-Function
typedef struct _DtIoStubDfDataFifo
{
    // NOTE: common stub data must be the first members to allow casting to DtIoStubDf
    DT_IOSTUB_DF_COMMON_DATA;
}  DtIoStubDfDataFifo;

//-.-.-.-.-.-.-.-.-.-.-.-.- DtIoStubDfDataFifo public functions -.-.-.-.-.-.-.-.-.-.-.-.-.
void  DtIoStubDfDataFifo_Close(DtIoStub*);
DtIoStubDfDataFifo*  DtIoStubDfDataFifo_Open(DtDf*);

#endif  // #ifndef __DT_DF_DATAFIFO_H

