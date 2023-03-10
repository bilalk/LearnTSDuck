//#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#* DtBcIO_2116_RegAccess.h *#*#*#*#*#*#*#* (C) 2021 DekTec
//
// Device driver - Gpio2116 v-1 (IO_2116) - Register access functions
//
// The register access functions defined here are elementary inline functions to read
// from and write to registers of BB2.0 building block Gpio2116.
// These functions should solely be used by the block controller for Gpio2116.
//
// 2021.08.04 6:57 - AUTOGENERATED BY DtBlock - DO NOT EDIT THIS FILE BY HAND

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
// 1. Single-function shorthand for reading field 'DacIrq' from register 'DacCtrl':
//      UInt32  DacIrq = IO_2116_DacCtrl_READ_DacIrq(pBc);
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

// IO_2116_CalibCtrl_READ
// IO_2116_CalibCtrl_SET_CalibSw1
// IO_2116_CalibCtrl_SET_CalibSw2
// IO_2116_CalibCtrl_WRITE
// IO_2116_ClkGenCtrl_GET_Status
// IO_2116_ClkGenCtrl_READ
// IO_2116_ClkGenCtrl_READ_Status
// IO_2116_ClkGenCtrl_SET_ClkSelect
// IO_2116_ClkGenCtrl_SET_ShutDown
// IO_2116_ClkGenCtrl_WRITE
// IO_2116_DacCtrl_GET_DacIrq
// IO_2116_DacCtrl_READ
// IO_2116_DacCtrl_READ_DacIrq
// IO_2116_DacCtrl_SET_Resetn
// IO_2116_DacCtrl_SET_TxEnable
// IO_2116_DacCtrl_WRITE
// IO_2116_OnePpsCtrl_READ
// IO_2116_OnePpsCtrl_SET_OnePpsTermEn
// IO_2116_OnePpsCtrl_WRITE

//+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+ Include Files +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=

#include "DtBc.h"                     // Block controller structs and functions

//+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+ Constant Definitions +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+

// Value map 'ClkSelect'
#define IO_2116_CLKSELECT_INTERNAL  0x0  // Internal 10Mhz
#define IO_2116_CLKSELECT_EXTERNAL  0x1  // External 10Mhz

//+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
//=+=+=+=+=+=+=+=+=+=+=+ REGISTER-ACCESS FUNCTIONS - IMPLEMENTATION +=+=+=+=+=+=+=+=+=+=+=
//+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=

//-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Register 'CalibCtrl' -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-

// Register READ function
static __inline UInt32 IO_2116_CalibCtrl_READ(DtBcIO_2116* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x4);
}

// Field SET functions
static __inline UInt32 IO_2116_CalibCtrl_SET_CalibSw1(UInt32 CalibCtrl, UInt32 CalibSw1)
{
    DT_ASSERT((CalibSw1 & ~0x1) == 0);
    return (CalibCtrl & ~0x1) | CalibSw1;
}
static __inline UInt32 IO_2116_CalibCtrl_SET_CalibSw2(UInt32 CalibCtrl, UInt32 CalibSw2)
{
    DT_ASSERT((CalibSw2 & ~0x1) == 0);
    return (CalibCtrl & ~0x2) | (CalibSw2 << 1);
}

// Register WRITE function
static __inline void IO_2116_CalibCtrl_WRITE(DtBcIO_2116* pBc, UInt32 CalibCtrl)
{
    DtBc_RegWrite32((DtBc*)pBc, 0x4, CalibCtrl);
}

//-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Register 'ClkGenCtrl' -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

// Register READ function
static __inline UInt32 IO_2116_ClkGenCtrl_READ(DtBcIO_2116* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x8);
}

// Field GET function
static __inline UInt32 IO_2116_ClkGenCtrl_GET_Status(UInt32 ClkGenCtrl)
{
    return ClkGenCtrl & 0x1;
}

// Field READ function
static __inline UInt32 IO_2116_ClkGenCtrl_READ_Status(DtBcIO_2116* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x8) & 0x1;
}

// Field SET functions
static __inline UInt32 IO_2116_ClkGenCtrl_SET_ShutDown(UInt32 ClkGenCtrl, UInt32 ShutDown)
{
    DT_ASSERT((ShutDown & ~0x1) == 0);
    return (ClkGenCtrl & ~0x2) | (ShutDown << 1);
}
static __inline UInt32 IO_2116_ClkGenCtrl_SET_ClkSelect(UInt32 ClkGenCtrl, UInt32 ClkSelect)
{
    DT_ASSERT((ClkSelect & ~0x1) == 0);
    return (ClkGenCtrl & ~0x4) | (ClkSelect << 2);
}

// Register WRITE function
static __inline void IO_2116_ClkGenCtrl_WRITE(DtBcIO_2116* pBc, UInt32 ClkGenCtrl)
{
    DtBc_RegWrite32((DtBc*)pBc, 0x8, ClkGenCtrl);
}

//.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Register 'DacCtrl' -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

// Register READ function
static __inline UInt32 IO_2116_DacCtrl_READ(DtBcIO_2116* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0xC);
}

// Field GET function
static __inline UInt32 IO_2116_DacCtrl_GET_DacIrq(UInt32 DacCtrl)
{
    return (DacCtrl & 0x4) >> 2;
}

// Field READ function
static __inline UInt32 IO_2116_DacCtrl_READ_DacIrq(DtBcIO_2116* pBc)
{
    return (DtBc_RegRead32((DtBc*)pBc, 0xC) & 0x4) >> 2;
}

// Field SET functions
static __inline UInt32 IO_2116_DacCtrl_SET_Resetn(UInt32 DacCtrl, UInt32 Resetn)
{
    DT_ASSERT((Resetn & ~0x1) == 0);
    return (DacCtrl & ~0x1) | Resetn;
}
static __inline UInt32 IO_2116_DacCtrl_SET_TxEnable(UInt32 DacCtrl, UInt32 TxEnable)
{
    DT_ASSERT((TxEnable & ~0x1) == 0);
    return (DacCtrl & ~0x2) | (TxEnable << 1);
}

// Register WRITE function
static __inline void IO_2116_DacCtrl_WRITE(DtBcIO_2116* pBc, UInt32 DacCtrl)
{
    DtBc_RegWrite32((DtBc*)pBc, 0xC, DacCtrl);
}

//-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Register 'OnePpsCtrl' -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

// Register READ function
static __inline UInt32 IO_2116_OnePpsCtrl_READ(DtBcIO_2116* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x10);
}

// Field SET function
static __inline UInt32 IO_2116_OnePpsCtrl_SET_OnePpsTermEn(UInt32 OnePpsCtrl, UInt32 OnePpsTermEn)
{
    DT_ASSERT((OnePpsTermEn & ~0x1) == 0);
    return (OnePpsCtrl & ~0x1) | OnePpsTermEn;
}

// Register WRITE function
static __inline void IO_2116_OnePpsCtrl_WRITE(DtBcIO_2116* pBc, UInt32 OnePpsCtrl)
{
    DtBc_RegWrite32((DtBc*)pBc, 0x10, OnePpsCtrl);
}

