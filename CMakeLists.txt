# Copyright 2011-2020 Free Software Foundation, Inc.
#
# This file was generated by gr_modtool, a tool from the GNU Radio framework
# This file is a part of gr-dpd
#
# SPDX-License-Identifier: GPL-3.0-or-later
#

# Select the release build type by default to get optimization flags.
# This has to come before project() which otherwise initializes it.
# Build type can still be overridden by setting -DCMAKE_BUILD_TYPE=
set(CMAKE_BUILD_TYPE
    "Release"
    CACHE STRING "")

########################################################################
# Project setup
########################################################################
cmake_minimum_required(VERSION 3.8)
project(gr-dpd CXX C)
enable_testing()

# Install to PyBOMBS target prefix if defined
if(DEFINED ENV{PYBOMBS_PREFIX})
    set(CMAKE_INSTALL_PREFIX
        $ENV{PYBOMBS_PREFIX}
        CACHE PATH "")
    message(
        STATUS
            "PyBOMBS installed GNU Radio. Defaulting CMAKE_INSTALL_PREFIX to $ENV{PYBOMBS_PREFIX}"
    )
endif()

# Make sure our local CMake Modules path comes first
list(INSERT CMAKE_MODULE_PATH 0 ${PROJECT_SOURCE_DIR}/cmake/Modules)
# Find gnuradio to get access to the cmake modules
find_package(Gnuradio "3.10" REQUIRED)

# Set the version information here
# cmake-format: off
set(VERSION_MAJOR 1)
set(VERSION_API   0)
set(VERSION_ABI   0)
set(VERSION_PATCH 0)
# cmake-format: on

cmake_policy(SET CMP0011 NEW)

# Enable generation of compile_commands.json for code completion engines
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

########################################################################
# Minimum Version Requirements
########################################################################

include(GrMinReq)

########################################################################
# Compiler settings
########################################################################

include(GrCompilerSettings)

########################################################################
# Install directories
########################################################################
include(GrVersion)

include(GrPlatform) #define LIB_SUFFIX

if(NOT CMAKE_MODULES_DIR)
    set(CMAKE_MODULES_DIR lib${LIB_SUFFIX}/cmake)
endif(NOT CMAKE_MODULES_DIR)

set(GR_INCLUDE_DIR include/gnuradio/dpd)
set(GR_CMAKE_DIR ${CMAKE_MODULES_DIR}/gnuradio-dpd)
set(GR_PKG_DATA_DIR ${GR_DATA_DIR}/${CMAKE_PROJECT_NAME})
set(GR_PKG_DOC_DIR ${GR_DOC_DIR}/${CMAKE_PROJECT_NAME})
set(GR_PKG_CONF_DIR ${GR_CONF_DIR}/${CMAKE_PROJECT_NAME}/conf.d)
set(GR_PKG_LIBEXEC_DIR ${GR_LIBEXEC_DIR}/${CMAKE_PROJECT_NAME})

########################################################################
# On Apple only, set install name and use rpath correctly, if not already set
########################################################################
if(APPLE)
    if(NOT CMAKE_INSTALL_NAME_DIR)
        set(CMAKE_INSTALL_NAME_DIR
            ${CMAKE_INSTALL_PREFIX}/${GR_LIBRARY_DIR}
            CACHE PATH "Library Install Name Destination Directory" FORCE)
    endif(NOT CMAKE_INSTALL_NAME_DIR)
    if(NOT CMAKE_INSTALL_RPATH)
        set(CMAKE_INSTALL_RPATH
            ${CMAKE_INSTALL_PREFIX}/${GR_LIBRARY_DIR}
            CACHE PATH "Library Install RPath" FORCE)
    endif(NOT CMAKE_INSTALL_RPATH)
    if(NOT CMAKE_BUILD_WITH_INSTALL_RPATH)
        set(CMAKE_BUILD_WITH_INSTALL_RPATH
            ON
            CACHE BOOL "Do Build Using Library Install RPath" FORCE)
    endif(NOT CMAKE_BUILD_WITH_INSTALL_RPATH)
endif(APPLE)

########################################################################
# Find gnuradio build dependencies
########################################################################
find_package(Doxygen)
find_package(Armadillo REQUIRED)

########################################################################
# Setup doxygen option
########################################################################
if(DOXYGEN_FOUND)
    option(ENABLE_DOXYGEN "Build docs using Doxygen" ON)
else(DOXYGEN_FOUND)
    option(ENABLE_DOXYGEN "Build docs using Doxygen" OFF)
endif(DOXYGEN_FOUND)

########################################################################
# Create uninstall target
########################################################################
configure_file(${PROJECT_SOURCE_DIR}/cmake/cmake_uninstall.cmake.in
               ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake @ONLY)

add_custom_target(uninstall ${CMAKE_COMMAND} -P
                            ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake)

########################################################################
# Add subdirectories
########################################################################
add_subdirectory(include/gnuradio/dpd)
add_subdirectory(lib)
add_subdirectory(apps)
add_subdirectory(docs)
# NOTE: manually update below to use GRC to generate C++ flowgraphs w/o python
if(ENABLE_PYTHON)
    message(STATUS "PYTHON and GRC components are enabled")
    add_subdirectory(python/dpd)
    add_subdirectory(grc)
else(ENABLE_PYTHON)
    message(STATUS "PYTHON and GRC components are disabled")
endif(ENABLE_PYTHON)

########################################################################
# Install cmake search helper for this library
########################################################################

install(FILES cmake/Modules/gnuradio-dpdConfig.cmake DESTINATION ${GR_CMAKE_DIR})

include(CMakePackageConfigHelpers)
configure_package_config_file(
    ${PROJECT_SOURCE_DIR}/cmake/Modules/targetConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/cmake/Modules/${target}Config.cmake
    INSTALL_DESTINATION ${GR_CMAKE_DIR})
