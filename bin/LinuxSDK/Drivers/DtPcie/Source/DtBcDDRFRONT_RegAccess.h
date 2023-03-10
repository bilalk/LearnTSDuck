//*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#* DtBcDDRFRONT_RegAccess.h *#*#*#*#*#*#*#* (C) 2022 DekTec
//
// Device driver - DdrFrontEnd v0 (DDRFRONT) - Register access functions
//
// The register access functions defined here are elementary inline functions to read
// from and write to registers of BB2.0 building block DdrFrontEnd.
// These functions should solely be used by the block controller for DdrFrontEnd.
//
// 2022.05.18 15:21 - AUTOGENERATED BY DtBlock - DO NOT EDIT THIS FILE BY HAND.

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
// 1. Getting fields 'MemorySize' and 'WordSize' from register 'Config':
//      UInt32  Reg_Config, MemorySize, WordSize;
//      Reg_Config = DDRFRONT_Config_READ(pBc);
//      MemorySize = DDRFRONT_Config_GET_MemorySize(Reg_Config);
//      WordSize   = DDRFRONT_Config_GET_WordSize(Reg_Config);
//
// 2. Single-function shorthand for reading field 'DdrLocalCalFail' from register
//    'Status':
//      UInt32  DdrLocalCalFail = DDRFRONT_Status_READ_DdrLocalCalFail(pBc);
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

// DDRFRONT_Config_GET_MemorySize
// DDRFRONT_Config_GET_NumMemRwInterfaces
// DDRFRONT_Config_GET_WordSize
// DDRFRONT_Config_READ
// DDRFRONT_Config_READ_MemorySize
// DDRFRONT_Config_READ_NumMemRwInterfaces
// DDRFRONT_Config_READ_WordSize
// DDRFRONT_Control_READ
// DDRFRONT_Control_SET_BlockEnable
// DDRFRONT_Control_WRITE
// DDRFRONT_ReadAddress_WRITE
// DDRFRONT_ReadData_READ
// DDRFRONT_Status_GET_DdrLocalCalFail
// DDRFRONT_Status_GET_DdrLocalCalSuccess
// DDRFRONT_Status_GET_IsReadBusy
// DDRFRONT_Status_GET_IsWriteBusy
// DDRFRONT_Status_READ
// DDRFRONT_Status_READ_DdrLocalCalFail
// DDRFRONT_Status_READ_DdrLocalCalSuccess
// DDRFRONT_Status_READ_IsReadBusy
// DDRFRONT_Status_READ_IsWriteBusy
// DDRFRONT_WriteAddress_WRITE
// DDRFRONT_WriteData_WRITE

//+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+ Include Files +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=

#include "DtBc.h"                     // Block controller structs and functions

//+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+ Constant Definitions +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+

// Value map 'BlockEnable'
#define DDRFRONT_BLKENA_DISABLED  0x0  // Block is entirely disabled
#define DDRFRONT_BLKENA_ENABLED   0x1  // Block is enabled and processes data

//+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
//=+=+=+=+=+=+=+=+=+=+=+ REGISTER-ACCESS FUNCTIONS - IMPLEMENTATION +=+=+=+=+=+=+=+=+=+=+=
//+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=

//-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Register 'Config' -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

// Register READ function
static __inline UInt32 DDRFRONT_Config_READ(DtBcDDRFRONT* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x4);
}

// Field GET functions
static __inline UInt32 DDRFRONT_Config_GET_MemorySize(UInt32 Config)
{
    return Config & 0xFF;
}
static __inline UInt32 DDRFRONT_Config_GET_WordSize(UInt32 Config)
{
    return (Config & 0xFFF00) >> 8;
}
static __inline UInt32 DDRFRONT_Config_GET_NumMemRwInterfaces(UInt32 Config)
{
    return (Config & 0xF8000000) >> 27;
}

// Field READ functions
static __inline UInt32 DDRFRONT_Config_READ_MemorySize(DtBcDDRFRONT* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x4) & 0xFF;
}
static __inline UInt32 DDRFRONT_Config_READ_WordSize(DtBcDDRFRONT* pBc)
{
    return (DtBc_RegRead32((DtBc*)pBc, 0x4) & 0xFFF00) >> 8;
}
static __inline UInt32 DDRFRONT_Config_READ_NumMemRwInterfaces(DtBcDDRFRONT* pBc)
{
    return (DtBc_RegRead32((DtBc*)pBc, 0x4) & 0xF8000000) >> 27;
}

//.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Register 'Control' -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

// Register READ function
static __inline UInt32 DDRFRONT_Control_READ(DtBcDDRFRONT* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x8);
}

// Field SET function
static __inline UInt32 DDRFRONT_Control_SET_BlockEnable(UInt32 Control, UInt32 BlockEnable)
{
    DT_ASSERT((BlockEnable & ~0x1) == 0);
    return (Control & ~0x1) | BlockEnable;
}

// Register WRITE function
static __inline void DDRFRONT_Control_WRITE(DtBcDDRFRONT* pBc, UInt32 Control)
{
    DtBc_RegWrite32((DtBc*)pBc, 0x8, Control);
}

//-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Register 'Status' -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

// Register READ function
static __inline UInt32 DDRFRONT_Status_READ(DtBcDDRFRONT* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0xC);
}

// Field GET functions
static __inline UInt32 DDRFRONT_Status_GET_IsWriteBusy(UInt32 Status)
{
    return Status & 0x1;
}
static __inline UInt32 DDRFRONT_Status_GET_IsReadBusy(UInt32 Status)
{
    return (Status & 0x2) >> 1;
}
static __inline UInt32 DDRFRONT_Status_GET_DdrLocalCalSuccess(UInt32 Status)
{
    return (Status & 0x40000000) >> 30;
}
static __inline UInt32 DDRFRONT_Status_GET_DdrLocalCalFail(UInt32 Status)
{
    return (Status & 0x80000000) >> 31;
}

// Field READ functions
static __inline UInt32 DDRFRONT_Status_READ_IsWriteBusy(DtBcDDRFRONT* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0xC) & 0x1;
}
static __inline UInt32 DDRFRONT_Status_READ_IsReadBusy(DtBcDDRFRONT* pBc)
{
    return (DtBc_RegRead32((DtBc*)pBc, 0xC) & 0x2) >> 1;
}
static __inline UInt32 DDRFRONT_Status_READ_DdrLocalCalSuccess(DtBcDDRFRONT* pBc)
{
    return (DtBc_RegRead32((DtBc*)pBc, 0xC) & 0x40000000) >> 30;
}
static __inline UInt32 DDRFRONT_Status_READ_DdrLocalCalFail(DtBcDDRFRONT* pBc)
{
    return (DtBc_RegRead32((DtBc*)pBc, 0xC) & 0x80000000) >> 31;
}

//.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Register 'ReadAddress' -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

// Field WRITE function
static __inline void DDRFRONT_ReadAddress_WRITE(DtBcDDRFRONT* pBc, UInt32 ReadAddress)
{
    DtBc_RegWrite32((DtBc*)pBc, 0x10, ReadAddress);
}

//.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Register 'ReadData' -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-

// Field READ function
static __inline UInt32 DDRFRONT_ReadData_READ(DtBcDDRFRONT* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x14);
}

//.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Register 'WriteAddress' -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-

// Field WRITE function
static __inline void DDRFRONT_WriteAddress_WRITE(DtBcDDRFRONT* pBc, UInt32 WriteAddress)
{
    DtBc_RegWrite32((DtBc*)pBc, 0x18, WriteAddress);
}

//-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Register 'WriteData' -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-

// Field WRITE function
static __inline void DDRFRONT_WriteData_WRITE(DtBcDDRFRONT* pBc, UInt32 WriteData)
{
    DtBc_RegWrite32((DtBc*)pBc, 0x1C, WriteData);
}

