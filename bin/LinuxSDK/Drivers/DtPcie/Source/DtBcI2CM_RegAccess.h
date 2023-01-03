//*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#* DtBcI2CM_RegAccess.h *#*#*#*#*#*#*#*#* (C) 2019 DekTec
//
// Device driver - I2cMaster v0 (I2CM) - Register access functions
//
// The register access functions defined here are elementary inline functions to read
// from and write to registers of BB2.0 building block I2cMaster.
// These functions should solely be used by the block controller for I2cMaster.
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
// 1. Getting fields 'I2cRate' and 'FifoSize' from register 'Config2':
//      UInt32  Reg_Config2, I2cRate, FifoSize;
//      Reg_Config2 = I2CM_Config2_READ(pBc);
//      I2cRate     = I2CM_Config2_GET_I2cRate(Reg_Config2);
//      FifoSize    = I2CM_Config2_GET_FifoSize(Reg_Config2);
//
// 2. Single-function shorthand for reading field 'Timeout' from register 'Status':
//      UInt32  Timeout = I2CM_Status_READ_Timeout(pBc);
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

// I2CM_Config1_READ_DeviceId
// I2CM_Config2_GET_FifoSize
// I2CM_Config2_GET_I2cRate
// I2CM_Config2_READ
// I2CM_Config2_READ_FifoSize
// I2CM_Config2_READ_I2cRate
// I2CM_Control1_READ
// I2CM_Control1_SET_Command
// I2CM_Control1_SET_SlaveAddress
// I2CM_Control1_WRITE
// I2CM_Control2_READ
// I2CM_Control2_SET_ReadCount
// I2CM_Control2_SET_WriteCount
// I2CM_Control2_WRITE
// I2CM_ReadData_READ
// I2CM_Status_GET_AddressNack
// I2CM_Status_GET_IsBusy
// I2CM_Status_GET_Timeout
// I2CM_Status_GET_WriteDataNack
// I2CM_Status_READ
// I2CM_Status_READ_AddressNack
// I2CM_Status_READ_IsBusy
// I2CM_Status_READ_Timeout
// I2CM_Status_READ_WriteDataNack
// I2CM_WriteData_WRITE

//+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+ Include Files +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=

#include "DtBc.h"                     // Block controller structs and functions

//+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+ Constant Definitions +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+

// Value map 'I2cDevice'
#define I2CM_I2CDVC_GEN_100KHZ  0x64   // Multiple devices on single bus, rate 100kHz
#define I2CM_I2CDVC_GEN_400KHZ  0x190  // Multiple devices on single bus, rate 400kHz
#define I2CM_I2CDVC_MAX2121     0x849  // Maxim Integrated MAX2121 L-band Tuner

// Value map 'I2cCommand'
#define I2CM_CMD_NOP            0x0    // No operation
#define I2CM_CMD_RESET          0x1    // Reset I2C by toggling the I2C SCL 9 times
#define I2CM_CMD_WRITE          0x2    // I2C Write only command
#define I2CM_CMD_READ           0x3    // I2C read only command
#define I2CM_CMD_WRITE_READ     0x4    // I2C Write first then read

//+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
//=+=+=+=+=+=+=+=+=+=+=+ REGISTER-ACCESS FUNCTIONS - IMPLEMENTATION +=+=+=+=+=+=+=+=+=+=+=
//+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=

//.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Register 'Config1' -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

// Field READ function
static __inline UInt32  I2CM_Config1_READ_DeviceId(DtBcI2CM* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x8);
}

//.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Register 'Config2' -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

// Register READ function
static __inline UInt32  I2CM_Config2_READ(DtBcI2CM* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0xC);
}

// Field GET functions
static __inline UInt32  I2CM_Config2_GET_I2cRate(UInt32 Config2)
{
    return Config2 & 0xFFFFF;
}
static __inline UInt32  I2CM_Config2_GET_FifoSize(UInt32 Config2)
{
    return (Config2 & 0x3FF00000) >> 20;
}

// Field READ functions
static __inline UInt32  I2CM_Config2_READ_I2cRate(DtBcI2CM* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0xC) & 0xFFFFF;
}
static __inline UInt32  I2CM_Config2_READ_FifoSize(DtBcI2CM* pBc)
{
    return (DtBc_RegRead32((DtBc*)pBc, 0xC) & 0x3FF00000) >> 20;
}

//.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Register 'Control1' -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-

// Register READ function
static __inline UInt32  I2CM_Control1_READ(DtBcI2CM* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x10);
}

// Field SET functions
static __inline UInt32  I2CM_Control1_SET_Command(UInt32 Control1, UInt32 Command)
{
    DT_ASSERT((Command & ~0x7) == 0);
    return (Control1 & ~0x7) | Command;
}
static __inline UInt32  I2CM_Control1_SET_SlaveAddress(UInt32 Control1, UInt32 SlaveAddress)
{
    DT_ASSERT((SlaveAddress & ~0x7F) == 0);
    return (Control1 & ~0x7F0000) | (SlaveAddress << 16);
}

// Register WRITE function
static __inline void  I2CM_Control1_WRITE(DtBcI2CM* pBc, UInt32 Control1)
{
    DtBc_RegWrite32((DtBc*)pBc, 0x10, Control1);
}

//.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Register 'Control2' -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-

// Register READ function
static __inline UInt32  I2CM_Control2_READ(DtBcI2CM* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x14);
}

// Field SET functions
static __inline UInt32  I2CM_Control2_SET_WriteCount(UInt32 Control2, UInt32 WriteCount)
{
    DT_ASSERT((WriteCount & ~0x3FF) == 0);
    return (Control2 & ~0x3FF) | WriteCount;
}
static __inline UInt32  I2CM_Control2_SET_ReadCount(UInt32 Control2, UInt32 ReadCount)
{
    DT_ASSERT((ReadCount & ~0x3FF) == 0);
    return (Control2 & ~0x3FF0000) | (ReadCount << 16);
}

// Register WRITE function
static __inline void  I2CM_Control2_WRITE(DtBcI2CM* pBc, UInt32 Control2)
{
    DtBc_RegWrite32((DtBc*)pBc, 0x14, Control2);
}

//-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Register 'Status' -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

// Register READ function
static __inline UInt32  I2CM_Status_READ(DtBcI2CM* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x18);
}

// Field GET functions
static __inline UInt32  I2CM_Status_GET_IsBusy(UInt32 Status)
{
    return Status & 0x1;
}
static __inline UInt32  I2CM_Status_GET_AddressNack(UInt32 Status)
{
    return (Status & 0x2) >> 1;
}
static __inline UInt32  I2CM_Status_GET_WriteDataNack(UInt32 Status)
{
    return (Status & 0x4) >> 2;
}
static __inline UInt32  I2CM_Status_GET_Timeout(UInt32 Status)
{
    return (Status & 0x8) >> 3;
}

// Field READ functions
static __inline UInt32  I2CM_Status_READ_IsBusy(DtBcI2CM* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x18) & 0x1;
}
static __inline UInt32  I2CM_Status_READ_AddressNack(DtBcI2CM* pBc)
{
    return (DtBc_RegRead32((DtBc*)pBc, 0x18) & 0x2) >> 1;
}
static __inline UInt32  I2CM_Status_READ_WriteDataNack(DtBcI2CM* pBc)
{
    return (DtBc_RegRead32((DtBc*)pBc, 0x18) & 0x4) >> 2;
}
static __inline UInt32  I2CM_Status_READ_Timeout(DtBcI2CM* pBc)
{
    return (DtBc_RegRead32((DtBc*)pBc, 0x18) & 0x8) >> 3;
}

//.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Register 'ReadData' -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-

// Field READ function
static __inline UInt32  I2CM_ReadData_READ(DtBcI2CM* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x1C);
}

//-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Register 'WriteData' -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-

// Field WRITE function
static __inline void  I2CM_WriteData_WRITE(DtBcI2CM* pBc, UInt32 WriteData)
{
    DtBc_RegWrite32((DtBc*)pBc, 0x20, WriteData);
}

