#========================================================================================
# @file CMakeLists.txt
# @brief
# @author Narange
# @copyright ©Narange
#========================================================================================
cmake_minimum_required (VERSION 3.8)

# MSVC Compiler Hotreload enable
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("OpenGL-Tutorial")

#========================================================================================
# program
set(PROGRAM_DIR ${CMAKE_CURRENT_SOURCE_DIR}/program)
message("> PROGRAM_DIR: ${PROGRAM_DIR}")

# lib
set(LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib)
message("> LIB_DIR: ${LIB_DIR}")

# glad
set(GLAD_DIR ${LIB_DIR}/glad)
include_directories(${GLAD_DIR}/include)
add_subdirectory(${GLAD_DIR})
message("> GLAD_DIR: ${GLAD_DIR}")

# glfw
set(GLFW_DIR ${LIB_DIR}/glfw-3.4)
include_directories(${GLFW_DIR}/include)
add_subdirectory(${GLFW_DIR})
message("> GLFW_DIR: ${GLFW_DIR}")

# glew
set(GLEW_DIR ${LIB_DIR}/glew)
include_directories(${GLEW_DIR}/include)
set(GLEW_LIB_DIR ${GLEW_DIR}/lib/glew32d.lib)
message("> GLEW_DIR: ${GLEW_DIR}")

# imgui
set(IMGUI_DIR ${LIB_DIR}/imgui-1.90.4)
add_library(imgui ${IMGUI_DIR}/imgui.cpp
        ${IMGUI_DIR}/imgui_demo.cpp
        ${IMGUI_DIR}/imgui_draw.cpp
        ${IMGUI_DIR}/imgui_tables.cpp
        ${IMGUI_DIR}/imgui_widgets.cpp
        ${IMGUI_DIR}/backends/imgui_impl_glfw.cpp
        ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp)
message("> IMGUI_DIR: ${IMGUI_DIR}")

#========================================================================================

add_executable (OpenGL-Tutorial "OpenGL-Tutorial.cpp" "OpenGL-Tutorial.h" ${PROGRAM_DIR})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET OpenGL-Tutorial PROPERTY CXX_STANDARD 20)
endif()

target_include_directories(imgui PRIVATE ${IMGUI_DIR})
target_include_directories(${PROJECT_NAME} PRIVATE ${IMGUI_DIR})

target_link_libraries(${PROJECT_NAME} glad glfw imgui ${GLEW_LIB_DIR} ${CMAKE_DL_LIBS})
