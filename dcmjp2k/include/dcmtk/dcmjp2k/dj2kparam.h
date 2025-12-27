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

#ifndef DCMJP2K_DJ2KPARAM_H
#define DCMJP2K_DJ2KPARAM_H

#include "dcmtk/config/osconfig.h"
#include "dcmtk/dcmdata/dccodec.h" /* for DcmCodecParameter */
#include "dcmtk/dcmjp2k/dj2kutil.h" /* for enums */

/** codec parameter for JPEG 2000 codecs
 */
class DCMTK_DCMJP2K_EXPORT DJ2KCodecParameter: public DcmCodecParameter
{
public:

  /** constructor, for use with decoders.
   *  @param uidCreation                 mode for SOP Instance UID creation
   *  @param planarConfiguration         flag describing how planar configuration of decompressed color images should be handled
   *  @param ignoreOffsetTable           flag indicating whether to ignore the offset table when decompressing multiframe images
   *  @param forceSingleFragmentPerFrame while decompressing a multiframe image, assume one fragment per frame even if the JPEG
   *                                     data for some frame is incomplete
   */
  DJ2KCodecParameter(
    J2K_UIDCreation uidCreation = EJ2KUC_default,
    J2K_PlanarConfiguration planarConfiguration = EJ2KPC_restore,
    OFBool ignoreOffsetTable = OFFalse,
    OFBool forceSingleFragmentPerFrame = OFFalse);

  /// copy constructor
  DJ2KCodecParameter(const DJ2KCodecParameter& arg);

  /// destructor
  virtual ~DJ2KCodecParameter();

  /** this methods creates a copy of type DcmCodecParameter *
   *  it must be overwritten in every subclass.
   *  @return copy of this object
   */
  virtual DcmCodecParameter *clone() const;

  /** returns the class name as string.
   *  can be used as poor man's RTTI replacement.
   */
  virtual const char *className() const;

  /** returns mode for SOP Instance UID creation
   *  @return mode for SOP Instance UID creation
   */
  J2K_UIDCreation getUIDCreation() const
  {
    return uidCreation_;
  }

  /** returns mode for handling planar configuration
   *  @return mode for handling planar configuration
   */
  J2K_PlanarConfiguration getPlanarConfiguration() const
  {
    return planarConfiguration_;
  }

  /** returns true if the offset table should be ignored when decompressing multiframe images
   *  @return true if the offset table should be ignored when decompressing multiframe images
   */
  OFBool ignoreOffsetTable() const
  {
    return ignoreOffsetTable_;
  }

  /** returns flag indicating whether one fragment per frame should be enforced while decoding
   *  @return flag indicating whether one fragment per frame should be enforced while decoding
   */
  OFBool getForceSingleFragmentPerFrame() const
  {
    return forceSingleFragmentPerFrame_;
  }

private:

  /// private undefined copy assignment operator
  DJ2KCodecParameter& operator=(const DJ2KCodecParameter&);

  /// mode for SOP Instance UID creation (used both for encoding and decoding)
  J2K_UIDCreation uidCreation_;

  /// flag describing how planar configuration of decompressed color images should be handled
  J2K_PlanarConfiguration planarConfiguration_;

  /// flag indicating if the offset table should be ignored when decompressing multiframe images
  OFBool ignoreOffsetTable_;

  /** while decompressing a multiframe image,
   *  assume one fragment per frame even if the JPEG data for some frame is incomplete
   */
  OFBool forceSingleFragmentPerFrame_;

};


#endif
