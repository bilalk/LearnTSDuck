//#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#* DtBcIOSERIN_RegAccess.h *#*#*#*#*#*#*#* (C) 2020 DekTec
//
// Device driver - IoSerialInput v0 (IOSERIN) - Register access functions
//
// The register access functions defined here are elementary inline functions to read
// from and write to registers of BB2.0 building block IoSerialInput.
// These functions should solely be used by the block controller for IoSerialInput.
//
// 2020.07.03 15:51 - AUTOGENERATED BY DtBlock - DO NOT EDIT THIS FILE BY HAND

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
// 1. Getting fields 'DataRate' and 'WidthExtensionMode' from register 'Config':
//      UInt32  Reg_Config, DataRate, WidthExtensionMode;
//      Reg_Config         = IOSERIN_Config_READ(pBc);
//      DataRate           = IOSERIN_Config_GET_DataRate(Reg_Config);
//      WidthExtensionMode = IOSERIN_Config_GET_WidthExtensionMode(Reg_Config);
//
// 2. Single-function shorthand for reading field 'Load' from register 'CdcFifoStatus':
//      UInt32  Load = IOSERIN_CdcFifoStatus_READ_Load(pBc);
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

// IOSERIN_CdcFifoStatus_CLEAR_Overflow
// IOSERIN_CdcFifoStatus_GET_Load
// IOSERIN_CdcFifoStatus_GET_Overflow
// IOSERIN_CdcFifoStatus_READ
// IOSERIN_CdcFifoStatus_READ_Load
// IOSERIN_CdcFifoStatus_READ_Overflow
// IOSERIN_Config_GET_BitDepthIn
// IOSERIN_Config_GET_BitDepthOut
// IOSERIN_Config_GET_DataRate
// IOSERIN_Config_GET_NumChannels
// IOSERIN_Config_GET_WidthExtensionMode
// IOSERIN_Config_READ
// IOSERIN_Config_READ_BitDepthIn
// IOSERIN_Config_READ_BitDepthOut
// IOSERIN_Config_READ_DataRate
// IOSERIN_Config_READ_NumChannels
// IOSERIN_Config_READ_WidthExtensionMode
// IOSERIN_Control_READ
// IOSERIN_Control_SET_BlockEnable
// IOSERIN_Control_SET_OperationalMode
// IOSERIN_Control_WRITE

//+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+ Include Files +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=

#include "DtBc.h"                     // Block controller structs and functions

//+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+ Constant Definitions +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+

// Value map 'BlockEnable'
#define IOSERIN_BLKENA_DISABLED          0x0  // Block is entirely disabled
#define IOSERIN_BLKENA_ENABLED           0x1  // Block is enabled and processes data

// Value map 'DataRate'
#define IOSERIN_DATARATE_SDR             0x1  // Single Data Rate input
#define IOSERIN_DATARATE_DDR             0x2  // Double Data Rate input

// Value map 'OperationalMode'
#define IOSERIN_OPMODE_IDLE              0x0  // Block is inactive
#define IOSERIN_OPMODE_STANDBY           0x1  // Block is partially operational
#define IOSERIN_OPMODE_RUN               0x2  // Block performs its normal function

// Value map 'WidthExtMode'
#define IOSERIN_EXTMODE_ZERO_EXTEND_LSB  0x0  // Add zero's to LSB side
#define IOSERIN_EXTMODE_ZERO_EXTEND_MSB  0x1  // Add zero's to MSB side
#define IOSERIN_EXTMODE_SIGN_EXTEND      0x2  // Sign-bit extension

//+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
//=+=+=+=+=+=+=+=+=+=+=+ REGISTER-ACCESS FUNCTIONS - IMPLEMENTATION +=+=+=+=+=+=+=+=+=+=+=
//+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=

//-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Register 'Config' -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

// Register READ function
static __inline UInt32  IOSERIN_Config_READ(DtBcIOSERIN* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x4);
}

// Field GET functions
static __inline UInt32  IOSERIN_Config_GET_DataRate(UInt32 Config)
{
    return Config & 0x3;
}
static __inline UInt32  IOSERIN_Config_GET_WidthExtensionMode(UInt32 Config)
{
    return (Config & 0xC) >> 2;
}
static __inline UInt32  IOSERIN_Config_GET_NumChannels(UInt32 Config)
{
    return (Config & 0x30) >> 4;
}
static __inline UInt32  IOSERIN_Config_GET_BitDepthIn(UInt32 Config)
{
    return (Config & 0xFF0000) >> 16;
}
static __inline UInt32  IOSERIN_Config_GET_BitDepthOut(UInt32 Config)
{
    return (Config & 0xFF000000) >> 24;
}

// Field READ functions
static __inline UInt32  IOSERIN_Config_READ_DataRate(DtBcIOSERIN* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x4) & 0x3;
}
static __inline UInt32  IOSERIN_Config_READ_WidthExtensionMode(DtBcIOSERIN* pBc)
{
    return (DtBc_RegRead32((DtBc*)pBc, 0x4) & 0xC) >> 2;
}
static __inline UInt32  IOSERIN_Config_READ_NumChannels(DtBcIOSERIN* pBc)
{
    return (DtBc_RegRead32((DtBc*)pBc, 0x4) & 0x30) >> 4;
}
static __inline UInt32  IOSERIN_Config_READ_BitDepthIn(DtBcIOSERIN* pBc)
{
    return (DtBc_RegRead32((DtBc*)pBc, 0x4) & 0xFF0000) >> 16;
}
static __inline UInt32  IOSERIN_Config_READ_BitDepthOut(DtBcIOSERIN* pBc)
{
    return (DtBc_RegRead32((DtBc*)pBc, 0x4) & 0xFF000000) >> 24;
}

//.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Register 'Control' -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

// Register READ function
static __inline UInt32  IOSERIN_Control_READ(DtBcIOSERIN* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x8);
}

// Field SET functions
static __inline UInt32  IOSERIN_Control_SET_BlockEnable(UInt32 Control, UInt32 BlockEnable)
{
    DT_ASSERT((BlockEnable & ~0x1) == 0);
    return (Control & ~0x1) | BlockEnable;
}
static __inline UInt32  IOSERIN_Control_SET_OperationalMode(UInt32 Control, UInt32 OperationalMode)
{
    DT_ASSERT((OperationalMode & ~0x3) == 0);
    return (Control & ~0x6) | (OperationalMode << 1);
}

// Register WRITE function
static __inline void  IOSERIN_Control_WRITE(DtBcIOSERIN* pBc, UInt32 Control)
{
    DtBc_RegWrite32((DtBc*)pBc, 0x8, Control);
}

//-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Register 'CdcFifoStatus' -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-

// Register READ function
static __inline UInt32  IOSERIN_CdcFifoStatus_READ(DtBcIOSERIN* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0xC);
}

// Field GET functions
static __inline UInt32  IOSERIN_CdcFifoStatus_GET_Overflow(UInt32 CdcFifoStatus)
{
    return CdcFifoStatus & 0x1;
}
static __inline UInt32  IOSERIN_CdcFifoStatus_GET_Load(UInt32 CdcFifoStatus)
{
    return (CdcFifoStatus & 0xFF00) >> 8;
}

// Field READ functions
static __inline UInt32  IOSERIN_CdcFifoStatus_READ_Overflow(DtBcIOSERIN* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0xC) & 0x1;
}
static __inline UInt32  IOSERIN_CdcFifoStatus_READ_Load(DtBcIOSERIN* pBc)
{
    return (DtBc_RegRead32((DtBc*)pBc, 0xC) & 0xFF00) >> 8;
}

// Field CLEAR function
static __inline void  IOSERIN_CdcFifoStatus_CLEAR_Overflow(DtBcIOSERIN* pBc)
{
    UInt32  CdcFifoStatus = DtBc_RegRead32((DtBc*)pBc, 0xC);
    DtBc_RegWrite32((DtBc*)pBc, 0xC, CdcFifoStatus | 0x1);
}

