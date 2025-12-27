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
 *  Purpose: enumerations, error constants and helper functions for dcmjp2k
 *
 */

#include "dcmtk/config/osconfig.h"
#include "dcmtk/dcmjp2k/dj2kutil.h"
#include "dcmtk/dcmdata/dcerror.h" /* for OFM_dcmjp2k module identifier */

OFLogger DCM_dcmjp2kLogger = OFLog::getLogger("dcmtk.dcmjp2k");

// error conditions
makeOFConditionConst(EC_J2KUncompressedBufferTooSmall,   OFM_dcmjp2k, 1, OF_error, "Uncompressed pixel data too large for buffer");
makeOFConditionConst(EC_J2KCompressedBufferTooSmall,     OFM_dcmjp2k, 2, OF_error, "Compressed pixel data too large for buffer");
makeOFConditionConst(EC_J2KCodecUnsupportedImageType,    OFM_dcmjp2k, 3, OF_error, "Unsupported type of image for JPEG 2000 codec");
makeOFConditionConst(EC_J2KCodecInvalidParameters,       OFM_dcmjp2k, 4, OF_error, "Invalid codec parameters");
makeOFConditionConst(EC_J2KCodecUnsupportedValue,        OFM_dcmjp2k, 5, OF_error, "Unsupported value in JPEG 2000 codec");
makeOFConditionConst(EC_J2KInvalidCompressedData,        OFM_dcmjp2k, 6, OF_error, "Invalid JPEG 2000 compressed data");
makeOFConditionConst(EC_J2KUnsupportedBitDepth,          OFM_dcmjp2k, 7, OF_error, "Unsupported bit depth for JPEG 2000");
makeOFConditionConst(EC_J2KCannotComputeNumberOfFragments, OFM_dcmjp2k, 8, OF_error, "Cannot compute number of fragments for JPEG 2000 frame");
makeOFConditionConst(EC_J2KImageDataMismatch,            OFM_dcmjp2k, 9, OF_error, "Image data mismatch between DICOM header and JPEG 2000 bitstream");
makeOFConditionConst(EC_J2KUnsupportedPhotometricInterpretation, OFM_dcmjp2k, 10, OF_error, "Unsupported photometric interpretation for JPEG 2000");
makeOFConditionConst(EC_J2KUnsupportedPixelRepresentation, OFM_dcmjp2k, 11, OF_error, "Unsupported pixel representation for JPEG 2000");
makeOFConditionConst(EC_J2KUnsupportedImageType,         OFM_dcmjp2k, 12, OF_error, "Unsupported image type for JPEG 2000");
makeOFConditionConst(EC_J2KOpenJPEGNotAvailable,         OFM_dcmjp2k, 13, OF_error, "OpenJPEG library not available");
