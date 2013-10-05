# Configura uma versão mínima necessária para o CMake
cmake_minimum_required(VERSION 2.8)

# Configura o nome do projeto
project(code_treloso)

# No CMake, uma variável é referenciada assim:
#   ${VARIAVEL}

# Adiciona uma nova pasta para o CMake pesquisar por módulos
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/modules" ${CMAKE_MODULE_PATH})

# Requisita o uso da SDL2. Não há informação de como encontrar a SDL2 entre os
# módulos oficiais do CMake, mas o módulo disponível em
# "${CMAKE_SOURCE_DIR}/cmake/modules/FindSDL2.cmake" fornece essa informação
find_package(SDL2 REQUIRED)

# Requisita o uso da OpenGL
find_package(OpenGL REQUIRED)

# Informa ao compilador onde os cabeçalhos da SDL e da OpenGL podem ser
# encontrados. Isso afeta as flags -I do GCC. As variáveis referenciadas são
# definidas pelos módulos de CMake OpenGL e SDL2.
include_directories(${OPENGL_INCLUDE_DIRS}
  ${SDL2_INCLUDE_DIR}
)

# Configura uma nova variável, source, que contém uma lista dos nomes dos
# arquivos de código-fonte.
set(source
  main.cpp
)

# Define um novo aplicativo, cujo nome é o mesmo do nome do projeto.
add_executable(${PROJECT_NAME}
  ${source}
)

# Linka o executável com as bibliotecas SDL2 e OpenGL. As variáveis de SDL2 e OpenGL foram
# definidas pelos módulos de CMake OpenGL e SDL2.
target_link_libraries(${PROJECT_NAME}
  ${OPENGL_LIBRARIES}
  ${SDL2_LIBRARY}
)
