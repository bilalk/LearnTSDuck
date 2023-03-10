//*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#* DtBcSDITXPLL_RegAccess.h *#*#*#*#*#*#*#* (C) 2022 DekTec
//
// Device driver - SdiTxPll v6 (SDITXPLL) - Register access functions
//
// The register access functions defined here are elementary inline functions to read
// from and write to registers of BB2.0 building block SdiTxPll.
// These functions should solely be used by the block controller for SdiTxPll.
//
// 2022.01.26 13:31 - AUTOGENERATED BY DtBlock - DO NOT EDIT THIS FILE BY HAND.

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
// 1. Getting fields 'PllId' and 'DeviceFamily' from register 'Config':
//      UInt32  Reg_Config, PllId, DeviceFamily;
//      Reg_Config   = SDITXPLL_Config_READ(pBc);
//      PllId        = SDITXPLL_Config_GET_PllId(Reg_Config);
//      DeviceFamily = SDITXPLL_Config_GET_DeviceFamily(Reg_Config);
//
// 2. Single-function shorthand for reading field 'AccessTimedout' from register 'Status':
//      UInt32  AccessTimedout = SDITXPLL_Status_READ_AccessTimedout(pBc);
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

// SDITXPLL_C10A10_PllCalibrationControl_GET_Operation
// SDITXPLL_C10A10_PllCalibrationControl_READ
// SDITXPLL_C10A10_PllCalibrationControl_SET_Operation
// SDITXPLL_C10A10_PllCalibrationControl_WRITE
// SDITXPLL_C10A10_PllCalibrationEnable_GET_Atx
// SDITXPLL_C10A10_PllCalibrationEnable_GET_Fpll
// SDITXPLL_C10A10_PllCalibrationEnable_GET_Reserved
// SDITXPLL_C10A10_PllCalibrationEnable_READ
// SDITXPLL_C10A10_PllCalibrationEnable_SET_Atx
// SDITXPLL_C10A10_PllCalibrationEnable_SET_Fpll
// SDITXPLL_C10A10_PllCalibrationEnable_SET_Reserved
// SDITXPLL_C10A10_PllCalibrationEnable_WRITE
// SDITXPLL_C10A10_PllCalibrationStatus_GET_Busy
// SDITXPLL_C10A10_PllCalibrationStatus_GET_ConfigBusBusy
// SDITXPLL_C10A10_PllCalibrationStatus_READ
// SDITXPLL_C10A10_PllCalibrationStatus_READ_Busy
// SDITXPLL_C10A10_PllCalibrationStatus_READ_ConfigBusBusy
// SDITXPLL_Config_GET_DeviceFamily
// SDITXPLL_Config_GET_PllId
// SDITXPLL_Config_GET_PllType
// SDITXPLL_Config_READ
// SDITXPLL_Config_READ_DeviceFamily
// SDITXPLL_Config_READ_PllId
// SDITXPLL_Config_READ_PllType
// SDITXPLL_Control_READ
// SDITXPLL_Control_SET_Enable
// SDITXPLL_Control_SET_Reset
// SDITXPLL_Control_WRITE
// SDITXPLL_Status_CLEAR_AccessTimedout
// SDITXPLL_Status_GET_AccessTimedout
// SDITXPLL_Status_GET_CalBusy
// SDITXPLL_Status_GET_Locked
// SDITXPLL_Status_GET_WaitRequest
// SDITXPLL_Status_READ
// SDITXPLL_Status_READ_AccessTimedout
// SDITXPLL_Status_READ_CalBusy
// SDITXPLL_Status_READ_Locked
// SDITXPLL_Status_READ_WaitRequest

//+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+ Include Files +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=

#include "DtBc.h"                     // Block controller structs and functions

//+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+ Constant Definitions +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+

// Value map 'DeviceFamily'
#define SDITXPLL_FAMILY_CV     0x0  // Intel Cyclone V
#define SDITXPLL_FAMILY_C10    0x1  // Intel Cyclone 10
#define SDITXPLL_FAMILY_A10    0x2  // Intel Arria 10

// Value map 'Operation'
#define SDITXPLL_OP_CAL        0x1  // Request PreSICE control of the internal config bus
                                    // and start cal
#define SDITXPLL_OP_USER       0x2  // Request user control of the internal config bus

// Value map 'PllType'
#define SDITXPLL_PLLTYPE_CMU   0x0  // Clock Multiplier Unit PLL or Channel PLL
#define SDITXPLL_PLLTYPE_FPLL  0x1  // Fractional PLL
#define SDITXPLL_PLLTYPE_ATX   0x2  // Advanced Transmit PLL

//+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
//=+=+=+=+=+=+=+=+=+=+=+ REGISTER-ACCESS FUNCTIONS - IMPLEMENTATION +=+=+=+=+=+=+=+=+=+=+=
//+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=

//-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Register 'Config' -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

// Register READ function
static __inline UInt32 SDITXPLL_Config_READ(DtBcSDITXPLL* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x4);
}

// Field GET functions
static __inline UInt32 SDITXPLL_Config_GET_PllId(UInt32 Config)
{
    return Config & 0x3FF;
}
static __inline UInt32 SDITXPLL_Config_GET_DeviceFamily(UInt32 Config)
{
    return (Config & 0x3C00) >> 10;
}
static __inline UInt32 SDITXPLL_Config_GET_PllType(UInt32 Config)
{
    return (Config & 0xC000) >> 14;
}

// Field READ functions
static __inline UInt32 SDITXPLL_Config_READ_PllId(DtBcSDITXPLL* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x4) & 0x3FF;
}
static __inline UInt32 SDITXPLL_Config_READ_DeviceFamily(DtBcSDITXPLL* pBc)
{
    return (DtBc_RegRead32((DtBc*)pBc, 0x4) & 0x3C00) >> 10;
}
static __inline UInt32 SDITXPLL_Config_READ_PllType(DtBcSDITXPLL* pBc)
{
    return (DtBc_RegRead32((DtBc*)pBc, 0x4) & 0xC000) >> 14;
}

//.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Register 'Control' -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

// Register READ function
static __inline UInt32 SDITXPLL_Control_READ(DtBcSDITXPLL* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x8);
}

// Field SET functions
static __inline UInt32 SDITXPLL_Control_SET_Enable(UInt32 Control, UInt32 Enable)
{
    DT_ASSERT((Enable & ~0x1) == 0);
    return (Control & ~0x1) | Enable;
}
static __inline UInt32 SDITXPLL_Control_SET_Reset(UInt32 Control, UInt32 Reset)
{
    DT_ASSERT((Reset & ~0x1) == 0);
    return (Control & ~0x2) | (Reset << 1);
}

// Register WRITE function
static __inline void SDITXPLL_Control_WRITE(DtBcSDITXPLL* pBc, UInt32 Control)
{
    DtBc_RegWrite32((DtBc*)pBc, 0x8, Control);
}

//-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Register 'Status' -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

// Register READ function
static __inline UInt32 SDITXPLL_Status_READ(DtBcSDITXPLL* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0xC);
}

// Field GET functions
static __inline UInt32 SDITXPLL_Status_GET_Locked(UInt32 Status)
{
    return Status & 0x1;
}
static __inline UInt32 SDITXPLL_Status_GET_CalBusy(UInt32 Status)
{
    return (Status & 0x2) >> 1;
}
static __inline UInt32 SDITXPLL_Status_GET_WaitRequest(UInt32 Status)
{
    return (Status & 0x4) >> 2;
}
static __inline UInt32 SDITXPLL_Status_GET_AccessTimedout(UInt32 Status)
{
    return (Status & 0x10) >> 4;
}

// Field READ functions
static __inline UInt32 SDITXPLL_Status_READ_Locked(DtBcSDITXPLL* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0xC) & 0x1;
}
static __inline UInt32 SDITXPLL_Status_READ_CalBusy(DtBcSDITXPLL* pBc)
{
    return (DtBc_RegRead32((DtBc*)pBc, 0xC) & 0x2) >> 1;
}
static __inline UInt32 SDITXPLL_Status_READ_WaitRequest(DtBcSDITXPLL* pBc)
{
    return (DtBc_RegRead32((DtBc*)pBc, 0xC) & 0x4) >> 2;
}
static __inline UInt32 SDITXPLL_Status_READ_AccessTimedout(DtBcSDITXPLL* pBc)
{
    return (DtBc_RegRead32((DtBc*)pBc, 0xC) & 0x10) >> 4;
}

// Field CLEAR function
static __inline void SDITXPLL_Status_CLEAR_AccessTimedout(DtBcSDITXPLL* pBc)
{
    UInt32  Status = DtBc_RegRead32((DtBc*)pBc, 0xC);
    DtBc_RegWrite32((DtBc*)pBc, 0xC, Status | 0x10);
}

//-.-.-.-.-.-.-.-.-.-.-.-.-.- Register 'PllCalibrationControl' -.-.-.-.-.-.-.-.-.-.-.-.-.-

// Register READ function
static __inline UInt32 SDITXPLL_C10A10_PllCalibrationControl_READ(DtBcSDITXPLL* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x20);
}

// Field GET function
static __inline UInt32 SDITXPLL_C10A10_PllCalibrationControl_GET_Operation(UInt32 PllCalibrationControl)
{
    return PllCalibrationControl & 0x3;
}

// Field SET function
static __inline UInt32 SDITXPLL_C10A10_PllCalibrationControl_SET_Operation(UInt32 PllCalibrationControl, UInt32 Operation)
{
    DT_ASSERT((Operation & ~0x3) == 0);
    return (PllCalibrationControl & ~0x3) | Operation;
}

// Register WRITE function
static __inline void SDITXPLL_C10A10_PllCalibrationControl_WRITE(DtBcSDITXPLL* pBc, UInt32 PllCalibrationControl)
{
    DtBc_RegWrite32((DtBc*)pBc, 0x20, PllCalibrationControl);
}

//.-.-.-.-.-.-.-.-.-.-.-.-.-.- Register 'PllCalibrationEnable' -.-.-.-.-.-.-.-.-.-.-.-.-.-

// Register READ function
static __inline UInt32 SDITXPLL_C10A10_PllCalibrationEnable_READ(DtBcSDITXPLL* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x24);
}

// Field GET functions
static __inline UInt32 SDITXPLL_C10A10_PllCalibrationEnable_GET_Atx(UInt32 PllCalibrationEnable)
{
    return PllCalibrationEnable & 0x1;
}
static __inline UInt32 SDITXPLL_C10A10_PllCalibrationEnable_GET_Fpll(UInt32 PllCalibrationEnable)
{
    return (PllCalibrationEnable & 0x2) >> 1;
}
static __inline UInt32 SDITXPLL_C10A10_PllCalibrationEnable_GET_Reserved(UInt32 PllCalibrationEnable)
{
    return (PllCalibrationEnable & 0xFC) >> 2;
}

// Field SET functions
static __inline UInt32 SDITXPLL_C10A10_PllCalibrationEnable_SET_Atx(UInt32 PllCalibrationEnable, UInt32 Atx)
{
    DT_ASSERT((Atx & ~0x1) == 0);
    return (PllCalibrationEnable & ~0x1) | Atx;
}
static __inline UInt32 SDITXPLL_C10A10_PllCalibrationEnable_SET_Fpll(UInt32 PllCalibrationEnable, UInt32 Fpll)
{
    DT_ASSERT((Fpll & ~0x1) == 0);
    return (PllCalibrationEnable & ~0x2) | (Fpll << 1);
}
static __inline UInt32 SDITXPLL_C10A10_PllCalibrationEnable_SET_Reserved(UInt32 PllCalibrationEnable, UInt32 Reserved)
{
    DT_ASSERT((Reserved & ~0x3F) == 0);
    return (PllCalibrationEnable & ~0xFC) | (Reserved << 2);
}

// Register WRITE function
static __inline void SDITXPLL_C10A10_PllCalibrationEnable_WRITE(DtBcSDITXPLL* pBc, UInt32 PllCalibrationEnable)
{
    DtBc_RegWrite32((DtBc*)pBc, 0x24, PllCalibrationEnable);
}

//.-.-.-.-.-.-.-.-.-.-.-.-.-.- Register 'PllCalibrationStatus' -.-.-.-.-.-.-.-.-.-.-.-.-.-

// Register READ function
static __inline UInt32 SDITXPLL_C10A10_PllCalibrationStatus_READ(DtBcSDITXPLL* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x28);
}

// Field GET functions
static __inline UInt32 SDITXPLL_C10A10_PllCalibrationStatus_GET_Busy(UInt32 PllCalibrationStatus)
{
    return (PllCalibrationStatus & 0x2) >> 1;
}
static __inline UInt32 SDITXPLL_C10A10_PllCalibrationStatus_GET_ConfigBusBusy(UInt32 PllCalibrationStatus)
{
    return (PllCalibrationStatus & 0x4) >> 2;
}

// Field READ functions
static __inline UInt32 SDITXPLL_C10A10_PllCalibrationStatus_READ_Busy(DtBcSDITXPLL* pBc)
{
    return (DtBc_RegRead32((DtBc*)pBc, 0x28) & 0x2) >> 1;
}
static __inline UInt32 SDITXPLL_C10A10_PllCalibrationStatus_READ_ConfigBusBusy(DtBcSDITXPLL* pBc)
{
    return (DtBc_RegRead32((DtBc*)pBc, 0x28) & 0x4) >> 2;
}

