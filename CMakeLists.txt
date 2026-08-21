# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required(VERSION 4.2)
set(CMAKE_CXX_STANDARD 20)

project(Rutherford LANGUAGES CXX)

# Include sub-projects.

add_executable(Rutherford
        # LAUNCHER
        src/Rutherford/main.cpp
        include/Rutherford/Config.h

        # MANAGER
        include/Rutherford/Application.h
        src/Rutherford/Application.cpp


        # RENDERING
        include/Rutherford/RenderManager.h
        src/Rutherford/RenderManager.cpp


        # MATHEMATICS
        src/Rutherford/Integrator.cpp
        include/Rutherford/Integrator.h

        # PHYSICS
        include/Rutherford/Simulation.h
        src/Rutherford/Simulation.cpp

        include/Rutherford/ForceCalculator.h

        # DATA STRUCTS
        include/Rutherford/Particle.h
)

find_package(glad CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

include(FetchContent)

FetchContent_Declare(
        VaosRenderer
        GIT_REPOSITORY https://github.com/Corvaos/Vaos-Renderer.git
        GIT_TAG de02b809b0664eddeaf28167ea88c704a248d524
)

FetchContent_MakeAvailable(VaosRenderer)

target_link_libraries(Rutherford PRIVATE
        glfw
        glad::glad
        VaosRenderer::VaosRenderer
)

target_include_directories(Rutherford PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)