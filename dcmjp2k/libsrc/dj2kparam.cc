/*
 *
 *  Copyright (C) 2024, OFFIS e.V.
 *  All rights reserved.  See COPYRIGHT file for details.
 *
 *  This software and supporting documentation were developed by
 *
 *    OFFIS e.V.
 *    R&D Division Health
 *    Escherweg 2
 *    D-26121 Oldenburg, Germany
 *
 *
 *  Module:  dcmjp2k
 *
 *  Author:  DCMTK Team
 *
 *  Purpose: codec parameter class for JPEG 2000 codecs
 *
 */

#include "dcmtk/config/osconfig.h"
#include "dcmtk/dcmjp2k/dj2kparam.h"

DJ2KCodecParameter::DJ2KCodecParameter(
    J2K_UIDCreation uidCreation,
    J2K_PlanarConfiguration planarConfiguration,
    OFBool ignoreOffsetTable,
    OFBool forceSingleFragmentPerFrame)
: DcmCodecParameter()
, uidCreation_(uidCreation)
, planarConfiguration_(planarConfiguration)
, ignoreOffsetTable_(ignoreOffsetTable)
, forceSingleFragmentPerFrame_(forceSingleFragmentPerFrame)
{
}

DJ2KCodecParameter::DJ2KCodecParameter(const DJ2KCodecParameter& arg)
: DcmCodecParameter(arg)
, uidCreation_(arg.uidCreation_)
, planarConfiguration_(arg.planarConfiguration_)
, ignoreOffsetTable_(arg.ignoreOffsetTable_)
, forceSingleFragmentPerFrame_(arg.forceSingleFragmentPerFrame_)
{
}

DJ2KCodecParameter::~DJ2KCodecParameter()
{
}

DcmCodecParameter *DJ2KCodecParameter::clone() const
{
  return new DJ2KCodecParameter(*this);
}

const char *DJ2KCodecParameter::className() const
{
  return "DJ2KCodecParameter";
}
