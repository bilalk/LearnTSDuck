// #*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#* DtBcXPLL_RegAccess.h *#*#*#*#*#*#*#*#* (C) 2022 DekTec
//
// Device driver - XcvrPll v0 (XPLL) - Register access functions
//
// The register access functions defined here are elementary inline functions to read
// from and write to registers of BB2.0 building block XcvrPll.
// These functions should solely be used by the block controller for XcvrPll.
//
// 2022.06.17 15:40 - AUTOGENERATED BY DtBlock - DO NOT EDIT THIS FILE BY HAND.

// -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- License -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-

// Copyright (C) 2022 DekTec Digital Video B.V.
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

// +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
// =+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+ EXAMPLES +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
// +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
//
// 1. Getting fields 'DeviceFamily' and 'PllType' from register 'Config':
//      UInt32 Reg_Config, DeviceFamily, PllType;
//      Reg_Config   = XPLL_Config_READ(pBc);
//      DeviceFamily = XPLL_Config_GET_DeviceFamily(Reg_Config);
//      PllType      = XPLL_Config_GET_PllType(Reg_Config);
//
// 2. Single-function shorthand for reading field 'PllCalBusy' from register 'Status':
//      UInt32  PllCalBusy = XPLL_Status_READ_PllCalBusy(pBc);
//
// =+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+ NOTES +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
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

// +=+=+=+=+=+=+=+=+=+=+ List of Generated Register-Access Functions +=+=+=+=+=+=+=+=+=+=+

// XPLL_C10A10_PllCore_AvmmArbitration_GET_ArbiterCtrl
// XPLL_C10A10_PllCore_AvmmArbitration_GET_CalDone
// XPLL_C10A10_PllCore_AvmmArbitration_READ
// XPLL_C10A10_PllCore_AvmmArbitration_SET_ArbiterCtrl
// XPLL_C10A10_PllCore_AvmmArbitration_SET_CalDone
// XPLL_C10A10_PllCore_AvmmArbitration_WRITE
// XPLL_C10A10_PllCore_Calibration_GET_AtxEnable
// XPLL_C10A10_PllCore_Calibration_GET_FpllEnable
// XPLL_C10A10_PllCore_Calibration_READ
// XPLL_C10A10_PllCore_Calibration_SET_AtxEnable
// XPLL_C10A10_PllCore_Calibration_SET_FpllEnable
// XPLL_C10A10_PllCore_Calibration_WRITE
// XPLL_C10A10_PllCore_Control_GET_OverridePllPowerdown
// XPLL_C10A10_PllCore_Control_GET_PllPowerdown
// XPLL_C10A10_PllCore_Control_READ
// XPLL_C10A10_PllCore_Control_SET_OverridePllPowerdown
// XPLL_C10A10_PllCore_Control_SET_PllPowerdown
// XPLL_C10A10_PllCore_Control_WRITE
// XPLL_C10A10_PllCore_Status_GET_AvMmBusy
// XPLL_C10A10_PllCore_Status_GET_CalBusy
// XPLL_C10A10_PllCore_Status_GET_Locked
// XPLL_C10A10_PllCore_Status_READ
// XPLL_C10A10_PllCore_Status_READ_AvMmBusy
// XPLL_C10A10_PllCore_Status_READ_CalBusy
// XPLL_C10A10_PllCore_Status_READ_Locked
// XPLL_Config_GET_DeviceFamily
// XPLL_Config_GET_FractMode
// XPLL_Config_GET_McgbEn
// XPLL_Config_GET_PllType
// XPLL_Config_READ
// XPLL_Config_READ_DeviceFamily
// XPLL_Config_READ_FractMode
// XPLL_Config_READ_McgbEn
// XPLL_Config_READ_PllType
// XPLL_Control_READ
// XPLL_Control_SET_BlockEnable
// XPLL_Control_WRITE
// XPLL_Status_CLEAR_AccessTimedout
// XPLL_Status_GET_AccessTimedout
// XPLL_Status_GET_PllCalBusy
// XPLL_Status_GET_PllLocked
// XPLL_Status_READ
// XPLL_Status_READ_AccessTimedout
// XPLL_Status_READ_PllCalBusy
// XPLL_Status_READ_PllLocked

// =+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+ Include Files +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=

#include "DtBc.h"                     // Block controller structs and functions

// =+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+ Constant Definitions +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+

// Value map 'ArbitrationRequest'
#define XPLL_ARBREQ_User       0x0  // Request control of the internal configuration bus
#define XPLL_ARBREQ_PreSICE    0x1  // Pass back control to the PreSICE configuration
                                    // engine

// Value map 'BlockEnable'
#define XPLL_BLKENA_DISABLED   0x0  // Block is entirely disabled
#define XPLL_BLKENA_ENABLED    0x1  // Block is enabled and processes data

// Value map 'BusOwner'
#define XPLL_BUSOWNER_User     0x0  // User has control of the internal configuration bus
#define XPLL_BUSOWNER_PreSICE  0x1  // PreSICE is controlling the internal configuration
                                    // bus

// Value map 'DeviceFamily'
#define XPLL_FAMILY_CV         0x0  // Intel Cyclone V
#define XPLL_FAMILY_C10        0x1  // Intel Cyclone 10
#define XPLL_FAMILY_A10        0x2  // Intel Arria 10

// Value map 'PllType'
#define XPLL_PLLTYPE_FPLL      0x1  // Fractional PLL
#define XPLL_PLLTYPE_ATX       0x2  // Advanced Transmit PLL

// +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
// +=+=+=+=+=+=+=+=+=+=+ REGISTER-ACCESS FUNCTIONS - IMPLEMENTATION +=+=+=+=+=+=+=+=+=+=+=
// +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+

// .-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Register 'Config' -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

// Register READ function
static __inline UInt32 XPLL_Config_READ(DtBcXPLL* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x4);
}

// Field GET functions
static __inline UInt32 XPLL_Config_GET_DeviceFamily(UInt32 Config)
{
    return (Config & 0x3C00) >> 10;
}
static __inline UInt32 XPLL_Config_GET_PllType(UInt32 Config)
{
    return (Config & 0xC000) >> 14;
}
static __inline UInt32 XPLL_Config_GET_FractMode(UInt32 Config)
{
    return (Config & 0x10000) >> 16;
}
static __inline UInt32 XPLL_Config_GET_McgbEn(UInt32 Config)
{
    return (Config & 0x20000) >> 17;
}

// Field READ functions
static __inline UInt32 XPLL_Config_READ_DeviceFamily(DtBcXPLL* pBc)
{
    return (DtBc_RegRead32((DtBc*)pBc, 0x4) & 0x3C00) >> 10;
}
static __inline UInt32 XPLL_Config_READ_PllType(DtBcXPLL* pBc)
{
    return (DtBc_RegRead32((DtBc*)pBc, 0x4) & 0xC000) >> 14;
}
static __inline UInt32 XPLL_Config_READ_FractMode(DtBcXPLL* pBc)
{
    return (DtBc_RegRead32((DtBc*)pBc, 0x4) & 0x10000) >> 16;
}
static __inline UInt32 XPLL_Config_READ_McgbEn(DtBcXPLL* pBc)
{
    return (DtBc_RegRead32((DtBc*)pBc, 0x4) & 0x20000) >> 17;
}

// -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Register 'Control' -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

// Register READ function
static __inline UInt32 XPLL_Control_READ(DtBcXPLL* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x8);
}

// Field SET function
static __inline UInt32 XPLL_Control_SET_BlockEnable(UInt32 Control, UInt32 BlockEnable)
{
    DT_ASSERT((BlockEnable & ~0x1) == 0);
    return (Control & ~0x1) | BlockEnable;
}

// Register WRITE function
static __inline void XPLL_Control_WRITE(DtBcXPLL* pBc, UInt32 Control)
{
    DtBc_RegWrite32((DtBc*)pBc, 0x8, Control);
}

// .-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Register 'Status' -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

// Register READ function
static __inline UInt32 XPLL_Status_READ(DtBcXPLL* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0xC);
}

// Field GET functions
static __inline UInt32 XPLL_Status_GET_AccessTimedout(UInt32 Status)
{
    return Status & 0x1;
}
static __inline UInt32 XPLL_Status_GET_PllLocked(UInt32 Status)
{
    return (Status & 0x2) >> 1;
}
static __inline UInt32 XPLL_Status_GET_PllCalBusy(UInt32 Status)
{
    return (Status & 0x4) >> 2;
}

// Field READ functions
static __inline UInt32 XPLL_Status_READ_AccessTimedout(DtBcXPLL* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0xC) & 0x1;
}
static __inline UInt32 XPLL_Status_READ_PllLocked(DtBcXPLL* pBc)
{
    return (DtBc_RegRead32((DtBc*)pBc, 0xC) & 0x2) >> 1;
}
static __inline UInt32 XPLL_Status_READ_PllCalBusy(DtBcXPLL* pBc)
{
    return (DtBc_RegRead32((DtBc*)pBc, 0xC) & 0x4) >> 2;
}

// Field CLEAR function
static __inline void XPLL_Status_CLEAR_AccessTimedout(DtBcXPLL* pBc)
{
    UInt32  Status = DtBc_RegRead32((DtBc*)pBc, 0xC);
    DtBc_RegWrite32((DtBc*)pBc, 0xC, Status | 0x1);
}

// -.-.-.-.-.-.-.-.-.-.-.-.- Register 'PllCore_AvmmArbitration' -.-.-.-.-.-.-.-.-.-.-.-.-.

// Register READ function
static __inline UInt32 XPLL_C10A10_PllCore_AvmmArbitration_READ(DtBcXPLL* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x10);
}

// Field GET functions
static __inline UInt32 XPLL_C10A10_PllCore_AvmmArbitration_GET_ArbiterCtrl(UInt32 PllCore_AvmmArbitration)
{
    return PllCore_AvmmArbitration & 0x1;
}
static __inline UInt32 XPLL_C10A10_PllCore_AvmmArbitration_GET_CalDone(UInt32 PllCore_AvmmArbitration)
{
    return (PllCore_AvmmArbitration & 0x2) >> 1;
}

// Field SET functions
static __inline UInt32 XPLL_C10A10_PllCore_AvmmArbitration_SET_ArbiterCtrl(UInt32 PllCore_AvmmArbitration, UInt32 ArbiterCtrl)
{
    DT_ASSERT((ArbiterCtrl & ~0x1) == 0);
    return (PllCore_AvmmArbitration & ~0x1) | ArbiterCtrl;
}
static __inline UInt32 XPLL_C10A10_PllCore_AvmmArbitration_SET_CalDone(UInt32 PllCore_AvmmArbitration, UInt32 CalDone)
{
    DT_ASSERT((CalDone & ~0x1) == 0);
    return (PllCore_AvmmArbitration & ~0x2) | (CalDone << 1);
}

// Register WRITE function
static __inline void XPLL_C10A10_PllCore_AvmmArbitration_WRITE(DtBcXPLL* pBc, UInt32 PllCore_AvmmArbitration)
{
    DtBc_RegWrite32((DtBc*)pBc, 0x10, PllCore_AvmmArbitration);
}

// -.-.-.-.-.-.-.-.-.-.-.-.-.- Register 'PllCore_Calibration' -.-.-.-.-.-.-.-.-.-.-.-.-.-.

// Register READ function
static __inline UInt32 XPLL_C10A10_PllCore_Calibration_READ(DtBcXPLL* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x14);
}

// Field GET functions
static __inline UInt32 XPLL_C10A10_PllCore_Calibration_GET_AtxEnable(UInt32 PllCore_Calibration)
{
    return PllCore_Calibration & 0x1;
}
static __inline UInt32 XPLL_C10A10_PllCore_Calibration_GET_FpllEnable(UInt32 PllCore_Calibration)
{
    return (PllCore_Calibration & 0x2) >> 1;
}

// Field SET functions
static __inline UInt32 XPLL_C10A10_PllCore_Calibration_SET_AtxEnable(UInt32 PllCore_Calibration, UInt32 AtxEnable)
{
    DT_ASSERT((AtxEnable & ~0x1) == 0);
    return (PllCore_Calibration & ~0x1) | AtxEnable;
}
static __inline UInt32 XPLL_C10A10_PllCore_Calibration_SET_FpllEnable(UInt32 PllCore_Calibration, UInt32 FpllEnable)
{
    DT_ASSERT((FpllEnable & ~0x1) == 0);
    return (PllCore_Calibration & ~0x2) | (FpllEnable << 1);
}

// Register WRITE function
static __inline void XPLL_C10A10_PllCore_Calibration_WRITE(DtBcXPLL* pBc, UInt32 PllCore_Calibration)
{
    DtBc_RegWrite32((DtBc*)pBc, 0x14, PllCore_Calibration);
}

// .-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Register 'PllCore_Status' -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

// Register READ function
static __inline UInt32 XPLL_C10A10_PllCore_Status_READ(DtBcXPLL* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x18);
}

// Field GET functions
static __inline UInt32 XPLL_C10A10_PllCore_Status_GET_Locked(UInt32 PllCore_Status)
{
    return PllCore_Status & 0x1;
}
static __inline UInt32 XPLL_C10A10_PllCore_Status_GET_CalBusy(UInt32 PllCore_Status)
{
    return (PllCore_Status & 0x2) >> 1;
}
static __inline UInt32 XPLL_C10A10_PllCore_Status_GET_AvMmBusy(UInt32 PllCore_Status)
{
    return (PllCore_Status & 0x4) >> 2;
}

// Field READ functions
static __inline UInt32 XPLL_C10A10_PllCore_Status_READ_Locked(DtBcXPLL* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x18) & 0x1;
}
static __inline UInt32 XPLL_C10A10_PllCore_Status_READ_CalBusy(DtBcXPLL* pBc)
{
    return (DtBc_RegRead32((DtBc*)pBc, 0x18) & 0x2) >> 1;
}
static __inline UInt32 XPLL_C10A10_PllCore_Status_READ_AvMmBusy(DtBcXPLL* pBc)
{
    return (DtBc_RegRead32((DtBc*)pBc, 0x18) & 0x4) >> 2;
}

// -.-.-.-.-.-.-.-.-.-.-.-.-.-.- Register 'PllCore_Control' -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

// Register READ function
static __inline UInt32 XPLL_C10A10_PllCore_Control_READ(DtBcXPLL* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x1C);
}

// Field GET functions
static __inline UInt32 XPLL_C10A10_PllCore_Control_GET_PllPowerdown(UInt32 PllCore_Control)
{
    return PllCore_Control & 0x1;
}
static __inline UInt32 XPLL_C10A10_PllCore_Control_GET_OverridePllPowerdown(UInt32 PllCore_Control)
{
    return (PllCore_Control & 0x2) >> 1;
}

// Field SET functions
static __inline UInt32 XPLL_C10A10_PllCore_Control_SET_PllPowerdown(UInt32 PllCore_Control, UInt32 PllPowerdown)
{
    DT_ASSERT((PllPowerdown & ~0x1) == 0);
    return (PllCore_Control & ~0x1) | PllPowerdown;
}
static __inline UInt32 XPLL_C10A10_PllCore_Control_SET_OverridePllPowerdown(UInt32 PllCore_Control, UInt32 OverridePllPowerdown)
{
    DT_ASSERT((OverridePllPowerdown & ~0x1) == 0);
    return (PllCore_Control & ~0x2) | (OverridePllPowerdown << 1);
}

// Register WRITE function
static __inline void XPLL_C10A10_PllCore_Control_WRITE(DtBcXPLL* pBc, UInt32 PllCore_Control)
{
    DtBc_RegWrite32((DtBc*)pBc, 0x1C, PllCore_Control);
}

