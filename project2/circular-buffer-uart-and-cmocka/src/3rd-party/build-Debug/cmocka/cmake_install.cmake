# Install script for directory: /home/vikrant/Desktop/project2clone/ecen5013/tutorials/unit_tests/3rd-party/cmocka

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/vikrant/Desktop/project2clone/ecen5013/tutorials/unit_tests/3rd-party/build-Debug")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "pkgconfig" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/vikrant/Desktop/project2clone/ecen5013/tutorials/unit_tests/3rd-party/build-Debug/lib/pkgconfig/cmocka.pc")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/vikrant/Desktop/project2clone/ecen5013/tutorials/unit_tests/3rd-party/build-Debug/lib/pkgconfig" TYPE FILE FILES "/home/vikrant/Desktop/project2clone/ecen5013/tutorials/unit_tests/3rd-party/build-Debug/cmocka/cmocka.pc")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "devel" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/vikrant/Desktop/project2clone/ecen5013/tutorials/unit_tests/3rd-party/build-Debug/lib/cmake/cmocka/cmocka-config.cmake;/home/vikrant/Desktop/project2clone/ecen5013/tutorials/unit_tests/3rd-party/build-Debug/lib/cmake/cmocka/cmocka-config-version.cmake")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/vikrant/Desktop/project2clone/ecen5013/tutorials/unit_tests/3rd-party/build-Debug/lib/cmake/cmocka" TYPE FILE FILES
    "/home/vikrant/Desktop/project2clone/ecen5013/tutorials/unit_tests/3rd-party/build-Debug/cmocka/cmocka-config.cmake"
    "/home/vikrant/Desktop/project2clone/ecen5013/tutorials/unit_tests/3rd-party/build-Debug/cmocka/cmocka-config-version.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/vikrant/Desktop/project2clone/ecen5013/tutorials/unit_tests/3rd-party/build-Debug/cmocka/doc/cmake_install.cmake")
  include("/home/vikrant/Desktop/project2clone/ecen5013/tutorials/unit_tests/3rd-party/build-Debug/cmocka/include/cmake_install.cmake")
  include("/home/vikrant/Desktop/project2clone/ecen5013/tutorials/unit_tests/3rd-party/build-Debug/cmocka/src/cmake_install.cmake")
  include("/home/vikrant/Desktop/project2clone/ecen5013/tutorials/unit_tests/3rd-party/build-Debug/cmocka/example/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/vikrant/Desktop/project2clone/ecen5013/tutorials/unit_tests/3rd-party/build-Debug/cmocka/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
