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
 *  Purpose: Contains preprocessor definitions
 *
 */


#ifndef DCMJP2K_DJ2KDEFINE_H
#define DCMJP2K_DJ2KDEFINE_H

#include "dcmtk/config/osconfig.h"

#include "dcmtk/ofstd/ofdefine.h"


#ifdef dcmjp2k_EXPORTS
#define DCMTK_DCMJP2K_EXPORT DCMTK_DECL_EXPORT
#else
#define DCMTK_DCMJP2K_EXPORT DCMTK_DECL_IMPORT
#endif


#endif
