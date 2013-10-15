set(gltools_src
  GLBatch.cpp
  glew.c
  GLShaderManager.cpp
  GLTools.cpp
  GLTriangleBatch.cpp
  math3d.cpp
)

include_directories(${OPENGL_INCLUDE_DIRS}
  ${GLUT_INCLUDE_DIRS}
  ${GLEW_INCLUDE_DIRS}
  ${GLTOOLS_INCLUDE_DIRS}
)

add_library(gltools
  ${gltools_src}
)
