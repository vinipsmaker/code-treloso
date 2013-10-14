set(GLTOOLS_INCLUDE_DIRS
  "${CMAKE_CURRENT_SOURCE_DIR}/include"
  "${CMAKE_CURRENT_SOURCE_DIR}/include/GL"
  CACHE INTERNAL "GLTools's include dir"
)

add_subdirectory(src)
