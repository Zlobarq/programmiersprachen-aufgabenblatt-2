# Build example
add_executable(example
  circle.cpp
  rectangle.cpp
  color.cpp
  mat2.cpp
  Vec2.cpp
  window.cpp
  glew.c
  example.cpp)
target_link_libraries(example
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES})
add_dependencies(example glfw nanovg ${COPY_BINARY})

# Build tests
add_executable(tests
  window.cpp
  glew.c
  circle.cpp
  rectangle.cpp
  color.cpp
  mat2.cpp
  Vec2.cpp
  tests.cpp)
target_link_libraries(tests
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES})

# Build clock
add_executable(clock
  window.cpp
  glew.c
  clock.cpp
  Vec2.cpp
  mat2.cpp
  color.cpp
  circle.cpp
  )
target_link_libraries(clock
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES})
add_dependencies(clock glfw nanovg ${COPY_BINARY})

