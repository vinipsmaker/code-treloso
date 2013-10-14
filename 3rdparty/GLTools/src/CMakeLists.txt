set(gltools_src
  GLBatch.cpp
  glew.c
  GLShaderManager.cpp
  GLTools.cpp
  GLTriangleBatch.cpp
  math3d.cpp
)

include_directories(${GLTOOLS_INCLUDE_DIRS})

add_library(gltools
  ${gltools_src}
)
