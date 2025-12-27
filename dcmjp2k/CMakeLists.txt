# declare project
project(dcmjp2k)

# recurse into subdirectories
foreach(SUBDIR libsrc include)
  add_subdirectory(${SUBDIR})
endforeach()
