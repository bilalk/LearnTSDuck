//*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#* DtBcASITXSER_RegAccess.h *#*#*#*#*#*#*#* (C) 2019 DekTec
//
// Device driver - AsiTxSer v0 (ASITXSER) - Register access functions
//
// The register access functions defined here are elementary inline functions to read
// from and write to registers of BB2.0 building block AsiTxSer.
// These functions should solely be used by the block controller for AsiTxSer.
//
// 2019.03.06 11:21 - AUTOGENERATED BY DtBlock - DO NOT EDIT THIS FILE BY HAND

//.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- License -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-

// Copyright (C) 2019 DekTec Digital Video B.V.
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

//+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
//+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+ EXAMPLES +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
//+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
//
// 1. Getting fields 'Underflow' and 'Load' from register 'CdcFifoStatus':
//      UInt32  Reg_CdcFifoStatus, Underflow, Load;
//      Reg_CdcFifoStatus = ASITXSER_CdcFifoStatus_READ(pBc);
//      Underflow         = ASITXSER_CdcFifoStatus_GET_Underflow(Reg_CdcFifoStatus);
//      Load              = ASITXSER_CdcFifoStatus_GET_Load(Reg_CdcFifoStatus);
//
// 2. Single-function shorthand for reading field 'Load' from register 'CdcFifoStatus':
//      UInt32  Load = ASITXSER_CdcFifoStatus_READ_Load(pBc);
//
//+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+ NOTES +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
//
// A) No automatic caching is provided, the user has to manage a 'cache' of 32-bit
// register values himself. The number of register reads and writes shall be minimized,
// as these are extremely slow (hundreds of CPU cycles for PCIe bus and orders of
// magnitude longer for USB).
//
// B) To read a field, the register shall first be read into an UInt32 using a READ
// function, followed by getting the field from the UInt32 value with a GET function.
// Field READ functions (a combination of the register READ- and field GET function) are
// provided for convenience, but these should only be used if the register value is just
// needed once for getting a single field.
//
// C) No register-access functions are generated for the BlockId register at address 0,
// nor for interrupt-status registers. The driver has generic (BB-independent) functions
// available for accessing these registers.

//=+=+=+=+=+=+=+=+=+=+=+ List of Generated Register-Access Functions +=+=+=+=+=+=+=+=+=+=+

// ASITXSER_CdcFifoStatus_CLEAR_Underflow
// ASITXSER_CdcFifoStatus_GET_Load
// ASITXSER_CdcFifoStatus_GET_Underflow
// ASITXSER_CdcFifoStatus_READ
// ASITXSER_CdcFifoStatus_READ_Load
// ASITXSER_CdcFifoStatus_READ_Underflow
// ASITXSER_Control_READ
// ASITXSER_Control_SET_BlockEnable
// ASITXSER_Control_SET_OperationalMode
// ASITXSER_Control_WRITE

//+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+ Include Files +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=

#include "DtBc.h"                     // Block controller structs and functions

//+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+ Constant Definitions +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+

// Value map 'BlockEnable'
#define ASITXSER_BLKENA_DISABLED  0x0  // Block is entirely disabled
#define ASITXSER_BLKENA_ENABLED   0x1  // Block is enabled and processes data

// Value map 'OperationalMode'
#define ASITXSER_OPMODE_IDLE      0x0  // Block is inactive
#define ASITXSER_OPMODE_STANDBY   0x1  // Block is partially operational
#define ASITXSER_OPMODE_RUN       0x2  // Block performs its normal function

//+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
//=+=+=+=+=+=+=+=+=+=+=+ REGISTER-ACCESS FUNCTIONS - IMPLEMENTATION +=+=+=+=+=+=+=+=+=+=+=
//+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=

//.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Register 'Control' -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

// Register READ function
static __inline UInt32  ASITXSER_Control_READ(DtBcASITXSER* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x4);
}

// Field SET functions
static __inline UInt32  ASITXSER_Control_SET_BlockEnable(UInt32 Control, UInt32 BlockEnable)
{
    DT_ASSERT((BlockEnable & ~0x1) == 0);
    return (Control & ~0x1) | BlockEnable;
}
static __inline UInt32  ASITXSER_Control_SET_OperationalMode(UInt32 Control, UInt32 OperationalMode)
{
    DT_ASSERT((OperationalMode & ~0x3) == 0);
    return (Control & ~0x6) | (OperationalMode << 1);
}

// Register WRITE function
static __inline void  ASITXSER_Control_WRITE(DtBcASITXSER* pBc, UInt32 Control)
{
    DtBc_RegWrite32((DtBc*)pBc, 0x4, Control);
}

//-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Register 'CdcFifoStatus' -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-

// Register READ function
static __inline UInt32  ASITXSER_CdcFifoStatus_READ(DtBcASITXSER* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x8);
}

// Field GET functions
static __inline UInt32  ASITXSER_CdcFifoStatus_GET_Underflow(UInt32 CdcFifoStatus)
{
    return CdcFifoStatus & 0x1;
}
static __inline UInt32  ASITXSER_CdcFifoStatus_GET_Load(UInt32 CdcFifoStatus)
{
    return (CdcFifoStatus & 0xF0) >> 4;
}

// Field READ functions
static __inline UInt32  ASITXSER_CdcFifoStatus_READ_Underflow(DtBcASITXSER* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x8) & 0x1;
}
static __inline UInt32  ASITXSER_CdcFifoStatus_READ_Load(DtBcASITXSER* pBc)
{
    return (DtBc_RegRead32((DtBc*)pBc, 0x8) & 0xF0) >> 4;
}

// Field CLEAR function
static __inline void  ASITXSER_CdcFifoStatus_CLEAR_Underflow(DtBcASITXSER* pBc)
{
    UInt32  CdcFifoStatus = DtBc_RegRead32((DtBc*)pBc, 0x8);
    DtBc_RegWrite32((DtBc*)pBc, 0x8, CdcFifoStatus | 0x1);
}

