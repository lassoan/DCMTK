# declare additional include directories
include_directories("${dcmjp2k_SOURCE_DIR}/include" "${ofstd_SOURCE_DIR}/include" "${oflog_SOURCE_DIR}/include" "${dcmdata_SOURCE_DIR}/include" "${dcmimgle_SOURCE_DIR}/include" "${dcmimage_SOURCE_DIR}/include" ${ZLIB_INCDIR})

if(DCMTK_WITH_OPENJPEG)
  include_directories(${OPENJPEG_INCLUDE_DIRS})
endif()

# create library from source files
DCMTK_ADD_LIBRARY(dcmjp2k
  dj2kparam.cc
  dj2kdecode.cc
  dj2kcodecd.cc
  dj2kutils.cc
)

DCMTK_TARGET_LINK_MODULES(dcmjp2k ofstd oflog dcmdata dcmimgle dcmimage)

if(DCMTK_WITH_OPENJPEG)
  # Link against OpenJPEG library
  # OPENJPEG_LIBS is set by DCMTK's 3rdparty.cmake for Windows support libraries
  if(OPENJPEG_LIBS)
    target_link_libraries(dcmjp2k ${OPENJPEG_LIBS})
    # Also set interface link libraries for consumers
    set_property(TARGET dcmjp2k APPEND PROPERTY INTERFACE_LINK_LIBRARIES ${OPENJPEG_LIBS})
  elseif(TARGET openjp2)
    # When using CMake config package, openjp2 is an imported target
    target_link_libraries(dcmjp2k openjp2)
    # Also set interface link libraries for consumers
    set_property(TARGET dcmjp2k APPEND PROPERTY INTERFACE_LINK_LIBRARIES openjp2)
  elseif(OPENJPEG_LIBRARIES)
    target_link_libraries(dcmjp2k ${OPENJPEG_LIBRARIES})
    # Also set interface link libraries for consumers
    set_property(TARGET dcmjp2k APPEND PROPERTY INTERFACE_LINK_LIBRARIES ${OPENJPEG_LIBRARIES})
  endif()
endif()
