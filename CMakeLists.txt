#------------------------------------------------------------------------
# Copyright (C) <2013> Dirk Van Haerenborgh <vhdirk@gmail.com>
#
# This file is free software; you can redistribute it and/or
# modify it under the terms of the GNU Library General Public
# License as published by the Free Software Foundation; either
# version 3 of the License, or (at your option) any later version.
#
# This file is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Library General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#------------------------------------------------------------------------


cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
#------------------------------------------------------------------------
# project name
#------------------------------------------------------------------------
project(gstmm-issues)

#------------------------------------------------------------------------
# build defenitions (on top for fast access)
#------------------------------------------------------------------------
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE INTERNAL
      "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel."
      FORCE)
endif(NOT CMAKE_BUILD_TYPE)


#------------------------------------------------------------------------
# library dependencies
#------------------------------------------------------------------------
## cmake module path (make sure to pull the cmake subrepository)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake)


find_package(Glibmm 2.4 REQUIRED)
add_definitions(${GLIBMM_DEFINITIONS})

# GStreamer
find_package(GStreamer 1.0 REQUIRED)
add_definitions(${GSTREAMER_DEFINITIONS})


# GTKmm
set(GTKmm_ROOT "/opt/gnome")
find_package(GTKmm 3.0 REQUIRED)

# GStreamermm
set(GStreamermm_ROOT "/opt/gnome")
find_package(GStreamermm 1.0 REQUIRED)
add_definitions(${GSTREAMERMM_DEFINITIONS})


#------------------------------------------------------------------------
# include & link directories
#------------------------------------------------------------------------

## from library dependencies
include_directories(${GSTREAMER_INCLUDE_DIRS}
		            ${GSTREAMERMM_INCLUDE_DIRS}
		            ${GTKMM_INCLUDE_DIRS}
                ${GLIBMM_INCLUDE_DIRS}
)

link_directories( ${GSTREAMER_LIBRARY_DIRS}
                  ${GSTREAMERMM_LIBRARY_DIRS}
                  ${GTKMM_LIBRARY_DIRS}
                  ${GLIBMM_LIBRARY_DIRS}
)


## from this project
include_directories(
    "${PROJECT_SOURCE_DIR}/libs"   
    "${PROJECT_SOURCE_DIR}/include"   
    "${PROJECT_SOURCE_DIR}/src"       
)


#------------------------------------------------------------------------
# build
#------------------------------------------------------------------------


add_executable(gstiterator src/gstiterator.cpp )
target_link_libraries(gstiterator ${GSTREAMER_LIBRARIES}
                                  ${GSTREAMERMM_LIBRARIES}
                                  ${GTKMM_LIBRARIES}
                                  ${GLIBMM_LIBRARIES}
)

add_executable(templatecaps src/templatecaps.cpp )
target_link_libraries(templatecaps ${GSTREAMER_LIBRARIES}
                                   ${GSTREAMERMM_LIBRARIES}
                                   ${GTKMM_LIBRARIES}
                                   ${GLIBMM_LIBRARIES}
)

add_executable(listfactories src/listfactories.cpp )
target_link_libraries(listfactories ${GSTREAMER_LIBRARIES}
                                    ${GSTREAMERMM_LIBRARIES}
                                    ${GTKMM_LIBRARIES}
                                    ${GLIBMM_LIBRARIES}
)



