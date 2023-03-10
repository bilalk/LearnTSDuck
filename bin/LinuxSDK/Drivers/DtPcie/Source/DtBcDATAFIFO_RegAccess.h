//*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#* DtBcDATAFIFO_RegAccess.h *#*#*#*#*#*#*#* (C) 2022 DekTec
//
// Device driver - DataDdrFifo v0 (DATAFIFO) - Register access functions
//
// The register access functions defined here are elementary inline functions to read
// from and write to registers of BB2.0 building block DataDdrFifo.
// These functions should solely be used by the block controller for DataDdrFifo.
//
// 2022.04.13 15:35 - AUTOGENERATED BY DtBlock - DO NOT EDIT THIS FILE BY HAND.

//.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- License -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-

// Copyright (C) 2020 DekTec Digital Video B.V.
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
// IN No EVENT SHALL DEKTEC DIGITAL VIDEO BV, ITS AGENTS OR ITS EMPLOYEES BE LIABLE FOR
// ANY DIRECT, INDIRECT, CONSEQUENTIAL, INCIDENTAL, OR OTHER DAMAGES (INCLUDING DAMAGES
// FOR THE LOSS OF USE, INFORMATION, GOODWILL, PROFIT, WORK STOPPAGE, DATA, BUSINESS OR
// REVENUE) UNDER ANY CIRCUMSTANCES, OR UNDER ANY LEGAL THEORY, WHETHER IN CONTRACT, IN
// TORT, IN NEGLIGENCE, OR OTHERWISE, ARISING FROM THE USE OF, OR INABILITY TO USE THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.

//+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
//+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+ EXAMPLES +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
//+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
//
// 1. Getting fields 'MaxFifoSize' and 'BurstSize' from register 'Config':
//      UInt32  Reg_Config, MaxFifoSize, BurstSize;
//      Reg_Config  = DATAFIFO_Config_READ(pBc);
//      MaxFifoSize = DATAFIFO_Config_GET_MaxFifoSize(Reg_Config);
//      BurstSize   = DATAFIFO_Config_GET_BurstSize(Reg_Config);
//
// 2. Single-function shorthand for reading field 'Maximum' from register 'FreeSpaceMax':
//      UInt32  Maximum = DATAFIFO_FreeSpaceMax_READ_Maximum(pBc);
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

// DATAFIFO_Config_GET_BurstSize
// DATAFIFO_Config_GET_MaxFifoSize
// DATAFIFO_Config_GET_MemDataWidth
// DATAFIFO_Config_READ
// DATAFIFO_Config_READ_BurstSize
// DATAFIFO_Config_READ_MaxFifoSize
// DATAFIFO_Config_READ_MemDataWidth
// DATAFIFO_Control_READ
// DATAFIFO_Control_SET_BlockEnable
// DATAFIFO_Control_SET_OperationalMode
// DATAFIFO_Control_WRITE
// DATAFIFO_FifoAddr_WRITE
// DATAFIFO_FifoLoad_READ
// DATAFIFO_FifoSize_WRITE
// DATAFIFO_FreeSpaceMax_GET_Maximum
// DATAFIFO_FreeSpaceMax_READ
// DATAFIFO_FreeSpaceMax_READ_Maximum
// DATAFIFO_FreeSpaceMax_SET_Clear
// DATAFIFO_FreeSpaceMax_WRITE
// DATAFIFO_LoadMax_GET_Maximum
// DATAFIFO_LoadMax_READ
// DATAFIFO_LoadMax_READ_Maximum
// DATAFIFO_LoadMax_SET_Clear
// DATAFIFO_LoadMax_WRITE
// DATAFIFO_OverflowCnt_READ
// DATAFIFO_UnderflowCnt_READ

//+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+ Include Files +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=

#include "DtBc.h"                     // Block controller structs and functions

//+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+ Constant Definitions +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+

// Value map 'BlockEnable'
#define DATAFIFO_BLKENA_DISABLED  0x0  // Block is entirely disabled
#define DATAFIFO_BLKENA_ENABLED   0x1  // Block is enabled and processes data

// Value map 'OperationalMode'
#define DATAFIFO_OPMODE_IDLE      0x0  // Block is inactive
#define DATAFIFO_OPMODE_STANDBY   0x1  // Block is partially operational
#define DATAFIFO_OPMODE_RUN       0x2  // Block performs its normal function

//+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
//=+=+=+=+=+=+=+=+=+=+=+ REGISTER-ACCESS FUNCTIONS - IMPLEMENTATION +=+=+=+=+=+=+=+=+=+=+=
//+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=

//-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Register 'Config' -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

// Register READ function
static __inline UInt32 DATAFIFO_Config_READ(DtBcDATAFIFO* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x4);
}

// Field GET functions
static __inline UInt32 DATAFIFO_Config_GET_MaxFifoSize(UInt32 Config)
{
    return Config & 0x1F;
}
static __inline UInt32 DATAFIFO_Config_GET_BurstSize(UInt32 Config)
{
    return (Config & 0x1E0) >> 5;
}
static __inline UInt32 DATAFIFO_Config_GET_MemDataWidth(UInt32 Config)
{
    return (Config & 0xFFC00000) >> 22;
}

// Field READ functions
static __inline UInt32 DATAFIFO_Config_READ_MaxFifoSize(DtBcDATAFIFO* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x4) & 0x1F;
}
static __inline UInt32 DATAFIFO_Config_READ_BurstSize(DtBcDATAFIFO* pBc)
{
    return (DtBc_RegRead32((DtBc*)pBc, 0x4) & 0x1E0) >> 5;
}
static __inline UInt32 DATAFIFO_Config_READ_MemDataWidth(DtBcDATAFIFO* pBc)
{
    return (DtBc_RegRead32((DtBc*)pBc, 0x4) & 0xFFC00000) >> 22;
}

//.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Register 'Control' -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

// Register READ function
static __inline UInt32 DATAFIFO_Control_READ(DtBcDATAFIFO* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x8);
}

// Field SET functions
static __inline UInt32 DATAFIFO_Control_SET_BlockEnable(UInt32 Control, UInt32 BlockEnable)
{
    DT_ASSERT((BlockEnable & ~0x1) == 0);
    return (Control & ~0x1) | BlockEnable;
}
static __inline UInt32 DATAFIFO_Control_SET_OperationalMode(UInt32 Control, UInt32 OperationalMode)
{
    DT_ASSERT((OperationalMode & ~0x3) == 0);
    return (Control & ~0x6) | (OperationalMode << 1);
}

// Register WRITE function
static __inline void DATAFIFO_Control_WRITE(DtBcDATAFIFO* pBc, UInt32 Control)
{
    DtBc_RegWrite32((DtBc*)pBc, 0x8, Control);
}

//.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Register 'FifoAddr' -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-

// Field WRITE function
static __inline void DATAFIFO_FifoAddr_WRITE(DtBcDATAFIFO* pBc, UInt32 FifoAddr)
{
    DtBc_RegWrite32((DtBc*)pBc, 0xC, FifoAddr);
}

//.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Register 'FifoSize' -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-

// Field WRITE function
static __inline void DATAFIFO_FifoSize_WRITE(DtBcDATAFIFO* pBc, UInt32 FifoSize)
{
    DtBc_RegWrite32((DtBc*)pBc, 0x10, FifoSize);
}

//.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Register 'FifoLoad' -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-

// Field READ function
static __inline UInt32 DATAFIFO_FifoLoad_READ(DtBcDATAFIFO* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x14) & 0x7FFFFFFF;
}

//.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Register 'LoadMax' -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

// Register READ function
static __inline UInt32 DATAFIFO_LoadMax_READ(DtBcDATAFIFO* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x18);
}

// Field GET function
static __inline UInt32 DATAFIFO_LoadMax_GET_Maximum(UInt32 LoadMax)
{
    return LoadMax & 0x7FFFFFFF;
}

// Field READ function
static __inline UInt32 DATAFIFO_LoadMax_READ_Maximum(DtBcDATAFIFO* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x18) & 0x7FFFFFFF;
}

// Field SET function
static __inline UInt32 DATAFIFO_LoadMax_SET_Clear(UInt32 LoadMax, UInt32 Clear)
{
    DT_ASSERT((Clear & ~0x1) == 0);
    return (LoadMax & ~0x80000000) | (Clear << 31);
}

// Register WRITE function
static __inline void DATAFIFO_LoadMax_WRITE(DtBcDATAFIFO* pBc, UInt32 LoadMax)
{
    DtBc_RegWrite32((DtBc*)pBc, 0x18, LoadMax);
}

//.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Register 'FreeSpaceMax' -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-

// Register READ function
static __inline UInt32 DATAFIFO_FreeSpaceMax_READ(DtBcDATAFIFO* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x1C);
}

// Field GET function
static __inline UInt32 DATAFIFO_FreeSpaceMax_GET_Maximum(UInt32 FreeSpaceMax)
{
    return FreeSpaceMax & 0x7FFFFFFF;
}

// Field READ function
static __inline UInt32 DATAFIFO_FreeSpaceMax_READ_Maximum(DtBcDATAFIFO* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x1C) & 0x7FFFFFFF;
}

// Field SET function
static __inline UInt32 DATAFIFO_FreeSpaceMax_SET_Clear(UInt32 FreeSpaceMax, UInt32 Clear)
{
    DT_ASSERT((Clear & ~0x1) == 0);
    return (FreeSpaceMax & ~0x80000000) | (Clear << 31);
}

// Register WRITE function
static __inline void DATAFIFO_FreeSpaceMax_WRITE(DtBcDATAFIFO* pBc, UInt32 FreeSpaceMax)
{
    DtBc_RegWrite32((DtBc*)pBc, 0x1C, FreeSpaceMax);
}

//.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Register 'OverflowCnt' -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

// Field READ function
static __inline UInt32 DATAFIFO_OverflowCnt_READ(DtBcDATAFIFO* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x20);
}

//.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Register 'UnderflowCnt' -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-

// Field READ function
static __inline UInt32 DATAFIFO_UnderflowCnt_READ(DtBcDATAFIFO* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x24);
}

