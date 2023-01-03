//#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#* DtBcSDIRXP_RegAccess.h *#*#*#*#*#*#*#*# (C) 2019 DekTec
//
// Device driver - SdiRxProtocol v1 (SDIRXP) - Register access functions
//
// The register access functions defined here are elementary inline functions to read
// from and write to registers of BB2.0 building block SdiRxProtocol.
// These functions should solely be used by the block controller for SdiRxProtocol.
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
// 1. Getting fields 'SdiLock' and 'LineLockRaw' from register 'Status':
//      UInt32  Reg_Status, SdiLock, LineLockRaw;
//      Reg_Status  = SDIRXP_Status_READ(pBc);
//      SdiLock     = SDIRXP_Status_GET_SdiLock(Reg_Status);
//      LineLockRaw = SDIRXP_Status_GET_LineLockRaw(Reg_Status);
//
// 2. Single-function shorthand for reading field 'FrameCnt' from register 'SdiStatus4':
//      UInt32  FrameCnt = SDIRXP_SdiStatus4_READ_FrameCnt(pBc);
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

// SDIRXP_Config_GET_MaxSdiRate
// SDIRXP_Config_READ
// SDIRXP_Config_READ_MaxSdiRate
// SDIRXP_Control_READ
// SDIRXP_Control_SET_BlockEnable
// SDIRXP_Control_SET_OperationalMode
// SDIRXP_Control_SET_SdiRate
// SDIRXP_Control_WRITE
// SDIRXP_CrcErrorCnt_READ
// SDIRXP_SdiStatus1_GET_FrameCnt
// SDIRXP_SdiStatus1_GET_LevelAorB
// SDIRXP_SdiStatus1_GET_NumSymHanc
// SDIRXP_SdiStatus1_GET_NumSymVideo
// SDIRXP_SdiStatus1_GET_Valid
// SDIRXP_SdiStatus1_READ
// SDIRXP_SdiStatus1_READ_FrameCnt
// SDIRXP_SdiStatus1_READ_LevelAorB
// SDIRXP_SdiStatus1_READ_NumSymHanc
// SDIRXP_SdiStatus1_READ_NumSymVideo
// SDIRXP_SdiStatus1_READ_Valid
// SDIRXP_SdiStatus2_GET_FrameCnt
// SDIRXP_SdiStatus2_GET_NumLinesField1
// SDIRXP_SdiStatus2_GET_NumLinesField2
// SDIRXP_SdiStatus2_READ
// SDIRXP_SdiStatus2_READ_FrameCnt
// SDIRXP_SdiStatus2_READ_NumLinesField1
// SDIRXP_SdiStatus2_READ_NumLinesField2
// SDIRXP_SdiStatus3_GET_FrameCnt
// SDIRXP_SdiStatus3_GET_PayloadIdLow
// SDIRXP_SdiStatus3_READ
// SDIRXP_SdiStatus3_READ_FrameCnt
// SDIRXP_SdiStatus3_READ_PayloadIdLow
// SDIRXP_SdiStatus4_GET_FrameCnt
// SDIRXP_SdiStatus4_GET_PayloadIdHigh
// SDIRXP_SdiStatus4_READ
// SDIRXP_SdiStatus4_READ_FrameCnt
// SDIRXP_SdiStatus4_READ_PayloadIdHigh
// SDIRXP_Status_GET_LineLock
// SDIRXP_Status_GET_LineLockRaw
// SDIRXP_Status_GET_SdiLock
// SDIRXP_Status_READ
// SDIRXP_Status_READ_LineLock
// SDIRXP_Status_READ_LineLockRaw
// SDIRXP_Status_READ_SdiLock
// SDIRXP_SymbolCnt_READ

//+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+ Include Files +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=

#include "DtBc.h"                     // Block controller structs and functions

//+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+ Constant Definitions +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+

// Value map 'LevelAorB'
#define SDIRXP_SDILEVEL_LEVEL_A  0x0  // 3G-SDI level A
#define SDIRXP_SDILEVEL_LEVEL_B  0x1  // 3G-SDI level B

// Value map 'SdiRate'
#define SDIRXP_SDIMODE_SD        0x0  // SDI mode is SD-SDI
#define SDIRXP_SDIMODE_HD        0x1  // SDI mode is HD-SDI
#define SDIRXP_SDIMODE_3G        0x2  // SDI mode is 3G-SDI
#define SDIRXP_SDIMODE_6G        0x3  // SDI mode is 6G-SDI
#define SDIRXP_SDIMODE_12G       0x4  // SDI mode is 12G-SDI

// Value map 'OperationalMode'
#define SDIRXP_OPMODE_IDLE       0x0  // Block is inactive
#define SDIRXP_OPMODE_STANDBY    0x1  // Block is partially operational
#define SDIRXP_OPMODE_RUN        0x2  // Block performs its normal function

// Value map 'BlockEnable'
#define SDIRXP_BLKENA_DISABLED   0x0  // Block is entirely disabled
#define SDIRXP_BLKENA_ENABLED    0x1  // Block is enabled and processes data

//+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
//=+=+=+=+=+=+=+=+=+=+=+ REGISTER-ACCESS FUNCTIONS - IMPLEMENTATION +=+=+=+=+=+=+=+=+=+=+=
//+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=

//-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Register 'Config' -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

// Register READ function
static __inline UInt32  SDIRXP_Config_READ(DtBcSDIRXP* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x4);
}

// Field GET function
static __inline UInt32  SDIRXP_Config_GET_MaxSdiRate(UInt32 Config)
{
    return Config & 0x7;
}

// Field READ function
static __inline UInt32  SDIRXP_Config_READ_MaxSdiRate(DtBcSDIRXP* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x4) & 0x7;
}

//.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Register 'Control' -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

// Register READ function
static __inline UInt32  SDIRXP_Control_READ(DtBcSDIRXP* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x8);
}

// Field SET functions
static __inline UInt32  SDIRXP_Control_SET_BlockEnable(UInt32 Control, UInt32 BlockEnable)
{
    DT_ASSERT((BlockEnable & ~0x1) == 0);
    return (Control & ~0x1) | BlockEnable;
}
static __inline UInt32  SDIRXP_Control_SET_OperationalMode(UInt32 Control, UInt32 OperationalMode)
{
    DT_ASSERT((OperationalMode & ~0x3) == 0);
    return (Control & ~0x6) | (OperationalMode << 1);
}
static __inline UInt32  SDIRXP_Control_SET_SdiRate(UInt32 Control, UInt32 SdiRate)
{
    DT_ASSERT((SdiRate & ~0x7) == 0);
    return (Control & ~0x70) | (SdiRate << 4);
}

// Register WRITE function
static __inline void  SDIRXP_Control_WRITE(DtBcSDIRXP* pBc, UInt32 Control)
{
    DtBc_RegWrite32((DtBc*)pBc, 0x8, Control);
}

//-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Register 'Status' -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

// Register READ function
static __inline UInt32  SDIRXP_Status_READ(DtBcSDIRXP* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0xC);
}

// Field GET functions
static __inline UInt32  SDIRXP_Status_GET_SdiLock(UInt32 Status)
{
    return Status & 0x1;
}
static __inline UInt32  SDIRXP_Status_GET_LineLockRaw(UInt32 Status)
{
    return (Status & 0x2) >> 1;
}
static __inline UInt32  SDIRXP_Status_GET_LineLock(UInt32 Status)
{
    return (Status & 0x4) >> 2;
}

// Field READ functions
static __inline UInt32  SDIRXP_Status_READ_SdiLock(DtBcSDIRXP* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0xC) & 0x1;
}
static __inline UInt32  SDIRXP_Status_READ_LineLockRaw(DtBcSDIRXP* pBc)
{
    return (DtBc_RegRead32((DtBc*)pBc, 0xC) & 0x2) >> 1;
}
static __inline UInt32  SDIRXP_Status_READ_LineLock(DtBcSDIRXP* pBc)
{
    return (DtBc_RegRead32((DtBc*)pBc, 0xC) & 0x4) >> 2;
}

//-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Register 'SdiStatus1' -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

// Register READ function
static __inline UInt32  SDIRXP_SdiStatus1_READ(DtBcSDIRXP* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x10);
}

// Field GET functions
static __inline UInt32  SDIRXP_SdiStatus1_GET_Valid(UInt32 SdiStatus1)
{
    return SdiStatus1 & 0x1;
}
static __inline UInt32  SDIRXP_SdiStatus1_GET_NumSymHanc(UInt32 SdiStatus1)
{
    return (SdiStatus1 & 0x3FFE) >> 1;
}
static __inline UInt32  SDIRXP_SdiStatus1_GET_NumSymVideo(UInt32 SdiStatus1)
{
    return (SdiStatus1 & 0x7FFC000) >> 14;
}
static __inline UInt32  SDIRXP_SdiStatus1_GET_LevelAorB(UInt32 SdiStatus1)
{
    return (SdiStatus1 & 0x8000000) >> 27;
}
static __inline UInt32  SDIRXP_SdiStatus1_GET_FrameCnt(UInt32 SdiStatus1)
{
    return (SdiStatus1 & 0xF0000000) >> 28;
}

// Field READ functions
static __inline UInt32  SDIRXP_SdiStatus1_READ_Valid(DtBcSDIRXP* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x10) & 0x1;
}
static __inline UInt32  SDIRXP_SdiStatus1_READ_NumSymHanc(DtBcSDIRXP* pBc)
{
    return (DtBc_RegRead32((DtBc*)pBc, 0x10) & 0x3FFE) >> 1;
}
static __inline UInt32  SDIRXP_SdiStatus1_READ_NumSymVideo(DtBcSDIRXP* pBc)
{
    return (DtBc_RegRead32((DtBc*)pBc, 0x10) & 0x7FFC000) >> 14;
}
static __inline UInt32  SDIRXP_SdiStatus1_READ_LevelAorB(DtBcSDIRXP* pBc)
{
    return (DtBc_RegRead32((DtBc*)pBc, 0x10) & 0x8000000) >> 27;
}
static __inline UInt32  SDIRXP_SdiStatus1_READ_FrameCnt(DtBcSDIRXP* pBc)
{
    return (DtBc_RegRead32((DtBc*)pBc, 0x10) & 0xF0000000) >> 28;
}

//-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Register 'SdiStatus2' -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

// Register READ function
static __inline UInt32  SDIRXP_SdiStatus2_READ(DtBcSDIRXP* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x14);
}

// Field GET functions
static __inline UInt32  SDIRXP_SdiStatus2_GET_NumLinesField1(UInt32 SdiStatus2)
{
    return SdiStatus2 & 0x3FFF;
}
static __inline UInt32  SDIRXP_SdiStatus2_GET_NumLinesField2(UInt32 SdiStatus2)
{
    return (SdiStatus2 & 0xFFFC000) >> 14;
}
static __inline UInt32  SDIRXP_SdiStatus2_GET_FrameCnt(UInt32 SdiStatus2)
{
    return (SdiStatus2 & 0xF0000000) >> 28;
}

// Field READ functions
static __inline UInt32  SDIRXP_SdiStatus2_READ_NumLinesField1(DtBcSDIRXP* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x14) & 0x3FFF;
}
static __inline UInt32  SDIRXP_SdiStatus2_READ_NumLinesField2(DtBcSDIRXP* pBc)
{
    return (DtBc_RegRead32((DtBc*)pBc, 0x14) & 0xFFFC000) >> 14;
}
static __inline UInt32  SDIRXP_SdiStatus2_READ_FrameCnt(DtBcSDIRXP* pBc)
{
    return (DtBc_RegRead32((DtBc*)pBc, 0x14) & 0xF0000000) >> 28;
}

//-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Register 'SdiStatus3' -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

// Register READ function
static __inline UInt32  SDIRXP_SdiStatus3_READ(DtBcSDIRXP* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x18);
}

// Field GET functions
static __inline UInt32  SDIRXP_SdiStatus3_GET_PayloadIdLow(UInt32 SdiStatus3)
{
    return SdiStatus3 & 0xFFFF;
}
static __inline UInt32  SDIRXP_SdiStatus3_GET_FrameCnt(UInt32 SdiStatus3)
{
    return (SdiStatus3 & 0xF0000000) >> 28;
}

// Field READ functions
static __inline UInt32  SDIRXP_SdiStatus3_READ_PayloadIdLow(DtBcSDIRXP* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x18) & 0xFFFF;
}
static __inline UInt32  SDIRXP_SdiStatus3_READ_FrameCnt(DtBcSDIRXP* pBc)
{
    return (DtBc_RegRead32((DtBc*)pBc, 0x18) & 0xF0000000) >> 28;
}

//-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Register 'SdiStatus4' -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

// Register READ function
static __inline UInt32  SDIRXP_SdiStatus4_READ(DtBcSDIRXP* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x1C);
}

// Field GET functions
static __inline UInt32  SDIRXP_SdiStatus4_GET_PayloadIdHigh(UInt32 SdiStatus4)
{
    return SdiStatus4 & 0xFFFF;
}
static __inline UInt32  SDIRXP_SdiStatus4_GET_FrameCnt(UInt32 SdiStatus4)
{
    return (SdiStatus4 & 0xF0000000) >> 28;
}

// Field READ functions
static __inline UInt32  SDIRXP_SdiStatus4_READ_PayloadIdHigh(DtBcSDIRXP* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x1C) & 0xFFFF;
}
static __inline UInt32  SDIRXP_SdiStatus4_READ_FrameCnt(DtBcSDIRXP* pBc)
{
    return (DtBc_RegRead32((DtBc*)pBc, 0x1C) & 0xF0000000) >> 28;
}

//-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Register 'SymbolCnt' -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-

// Field READ function
static __inline UInt32  SDIRXP_SymbolCnt_READ(DtBcSDIRXP* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x20);
}

//.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Register 'CrcErrorCnt' -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

// Field READ function
static __inline UInt32  SDIRXP_CrcErrorCnt_READ(DtBcSDIRXP* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x24);
}
