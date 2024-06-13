# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/apple/Desktop/v5.1-rc2/esp-idf/components/bootloader/subproject"
  "/Users/apple/workspace/esp32_app/build/bootloader"
  "/Users/apple/workspace/esp32_app/build/bootloader-prefix"
  "/Users/apple/workspace/esp32_app/build/bootloader-prefix/tmp"
  "/Users/apple/workspace/esp32_app/build/bootloader-prefix/src/bootloader-stamp"
  "/Users/apple/workspace/esp32_app/build/bootloader-prefix/src"
  "/Users/apple/workspace/esp32_app/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/apple/workspace/esp32_app/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/apple/workspace/esp32_app/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
