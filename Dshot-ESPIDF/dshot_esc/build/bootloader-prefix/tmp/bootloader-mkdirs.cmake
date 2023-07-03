# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/jimmywu/esp/esp-idf/components/bootloader/subproject"
  "/Users/jimmywu/Documents/GitHub/VRSketch/Dshot-ESPIDF/dshot_esc/build/bootloader"
  "/Users/jimmywu/Documents/GitHub/VRSketch/Dshot-ESPIDF/dshot_esc/build/bootloader-prefix"
  "/Users/jimmywu/Documents/GitHub/VRSketch/Dshot-ESPIDF/dshot_esc/build/bootloader-prefix/tmp"
  "/Users/jimmywu/Documents/GitHub/VRSketch/Dshot-ESPIDF/dshot_esc/build/bootloader-prefix/src/bootloader-stamp"
  "/Users/jimmywu/Documents/GitHub/VRSketch/Dshot-ESPIDF/dshot_esc/build/bootloader-prefix/src"
  "/Users/jimmywu/Documents/GitHub/VRSketch/Dshot-ESPIDF/dshot_esc/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/jimmywu/Documents/GitHub/VRSketch/Dshot-ESPIDF/dshot_esc/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/jimmywu/Documents/GitHub/VRSketch/Dshot-ESPIDF/dshot_esc/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
