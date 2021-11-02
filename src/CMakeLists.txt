
# Define a macro for adding all subdirs of this dir (src).
############################
MACRO(SUBDIRLIST result curdir)
  FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)
  SET(dirlist "")
  FOREACH(child ${children})
    IF(IS_DIRECTORY ${curdir}/${child})
      LIST(APPEND dirlist ${child})
    ENDIF()
  ENDFOREACH()
  SET(${result} ${dirlist})
ENDMACRO()
############################



cmake_minimum_required (VERSION 3.8)

SUBDIRLIST(SUBDIRS .)

FOREACH(subdir ${SUBDIRS})
  ADD_SUBDIRECTORY(${subdir})
ENDFOREACH()

# Add source to this project's executable.
add_executable (DungeonCrawler "main.cpp")