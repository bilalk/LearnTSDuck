//----------------------------------------------------------------------------
//
// TSDuck - The MPEG Transport Stream Toolkit
// Copyright (c) 2005-2022, Thierry Lelegard
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
// THE POSSIBILITY OF SUCH DAMAGE.
//
//----------------------------------------------------------------------------
//!
//!  @file
//!  Abstract representation of a preferred_name_identifier_descriptor
//!  for different private data specifiers.
//!
//----------------------------------------------------------------------------

#pragma once
#include "tsAbstractDescriptor.h"

namespace ts {
    //!
    //! Abstract representation of a preferred_name_identifier_descriptor for different private data specifiers.
    //! @ingroup descriptor
    //!
    class TSDUCKDLL AbstractPreferredNameIdentifierDescriptor : public AbstractDescriptor
    {
    public:
        // AbstractPreferredNameIdentifierDescriptor public members:
        uint8_t name_id;  //!< Service name id from an EacemPreferredNameListDescriptor.

        // Inherited methods
        DeclareDisplayDescriptor();

    protected:
        //!
        //! Default constructor.
        //! @param [in] name_id Service name id from an EacemPreferredNameListDescriptor.
        //! @param [in] tag Descriptor tag.
        //! @param [in] xml_name Descriptor name, as used in XML structures.
        //! @param [in] standards A bit mask of standards which define this structure.
        //! @param [in] pds Required private data specifier if this is a private descriptor.
        //! @param [in] xml_legacy_name Table or descriptor legacy XML name. Ignored if null pointer.
        //!
        AbstractPreferredNameIdentifierDescriptor(uint8_t name_id, DID tag, const UChar* xml_name, Standards standards, PDS pds, const UChar* xml_legacy_name = nullptr);

        //!
        //! Constructor from a binary descriptor
        //! @param [in,out] duck TSDuck execution context.
        //! @param [in] bin A binary descriptor to deserialize.
        //! @param [in] tag Descriptor tag.
        //! @param [in] xml_name Descriptor name, as used in XML structures.
        //! @param [in] standards A bit mask of standards which define this structure.
        //! @param [in] pds Required private data specifier if this is a private descriptor.
        //! @param [in] xml_legacy_name Table or descriptor legacy XML name. Ignored if null pointer.
        //!
        AbstractPreferredNameIdentifierDescriptor(DuckContext& duck, const Descriptor& bin, DID tag, const UChar* xml_name, Standards standards, PDS pds, const UChar* xml_legacy_name = nullptr);

        // Inherited methods
        virtual void clearContent() override;
        virtual void serializePayload(PSIBuffer&) const override;
        virtual void deserializePayload(PSIBuffer&) override;
        virtual void buildXML(DuckContext&, xml::Element*) const override;
        virtual bool analyzeXML(DuckContext&, const xml::Element*) override;

    private:
        AbstractPreferredNameIdentifierDescriptor() = delete;
    };
}
