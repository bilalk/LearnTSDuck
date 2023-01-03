//#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#* DtBcIQFIR_2132.h *#*#*#*#*#*#*#*#*# (C) 2018 DekTec
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

#ifndef __DT_BC_IQFIR_2132_H
#define __DT_BC_IQFIR_2132_H

//.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Include files -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-
#include "DtBc.h"

// Name and short-name of the IqFirFilter block (must match block ID)
#define DT_BC_IQFIR_2132_NAME        "IqFirFilter"
#define DT_BC_IQFIR_2132_SHORTNAME   "IQFIR"

// MACRO: to init an block-controller-ID for the IQFIR_2132-BC
#define DT_BC_IQFIR_2132_INIT_ID(ID, ROLE, INSTANCE, UUID)                               \
do                                                                                       \
{                                                                                        \
    DT_BC_INIT_ID(ID, DT_BC_IQFIR_2132_NAME, DT_BC_IQFIR_2132_SHORTNAME,  ROLE,          \
                                                                       INSTANCE, UUID);  \
}                                                                                        \
while (0)


//+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
//=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+ DtBcIQFIR_2132 definitions +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
//+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=

//-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- DtBcIQFIR_2132 -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-
typedef  struct _DtBcIQFIR_2132
{
    // NOTE: common block data must be the first members to allow casting to DtBc
    DT_BC_COMMON_DATA;

    DtFastMutex  m_AccessMutex;     // Access protection for the filter
    // Cached config
    Int  m_NumberCoefficients;      // Number of coefficients
    Int  m_CoefficientSize;         // Size of the Coefficients (number of bits)

}  DtBcIQFIR_2132;

//-.-.-.-.-.-.-.-.-.-.-.-.-.- DtBcIQFIR_2132 public functions -.-.-.-.-.-.-.-.-.-.-.-.-.-.
void  DtBcIQFIR_2132_Close(DtBc*);
DtBcIQFIR_2132*  DtBcIQFIR_2132_Open(Int  Address, DtCore*, DtPt*  pPt, 
                          const char*  pRole, Int  Instance, Int  Uuid, Bool  CreateStub);
DtStatus  DtBcIQFIR_2132_GetConfig(DtBcIQFIR_2132* pBc, Int* pNumCoefs, Int* pCoefSize);
DtStatus  DtBcIQFIR_2132_GetCoefficients(DtBcIQFIR_2132*, Int* pCoeffs, Int NumToGet);
DtStatus  DtBcIQFIR_2132_SetCoefficients(DtBcIQFIR_2132*, const Int* pCoeffs, Int NumToSet);


//+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
//+=+=+=+=+=+=+=+=+=+=+=+=+=+ DtIoStubBcIQFIR_2132 definitions +=+=+=+=+=+=+=+=+=+=+=+=+=+
//+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=

//.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- DtIoStubBcIQFIR_2132 -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
//  Io-control stub for an IQFIR_2132 Block
typedef struct _DtIoStubBcIQFIR_2132
{
    // NOTE: common stub data must be the first members to allow casting to 
    // DtBcIoCtl
    DT_IOSTUB_BC_COMMON_DATA;
}  DtIoStubBcIQFIR_2132;


//-.-.-.-.-.-.-.-.-.-.-.- DtIoStubBcIQFIR_2132 public functions -.-.-.-.-.-.-.-.-.-.-.-.
void  DtIoStubBcIQFIR_2132_Close(DtIoStub*);
DtIoStubBcIQFIR_2132*  DtIoStubBcIQFIR_2132_Open(DtBc*);


#endif  // #ifndef __DT_BC_IQFIR_2132_H