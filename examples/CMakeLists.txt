
include(CMakeParseArguments)

macro(ADD_ELASTIC_EXAMPLE EXAMPLE_NAME)
  cmake_parse_arguments(THIS "" "" "SOURCES" ${ARGN})

  add_executable("elastic_${EXAMPLE_NAME}" WIN32 ${THIS_SOURCES})
  target_link_libraries("elastic_${EXAMPLE_NAME}" "elastic" "canvas")
  set_property(TARGET "elastic_${EXAMPLE_NAME}" PROPERTY FOLDER "elastic/examples")
endmacro()

add_subdirectory("minimal")
