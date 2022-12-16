# CMakeList.txt: projeto de CMake para HydroEstimator, incluir origem e definir
# lógica específica a um projeto aqui.
#
cmake_minimum_required (VERSION 3.8)

project ("HydroEstimator")


# Adicione a origem ao executável deste projeto.
add_executable (HydroEstimator "HydroEstimator.cpp" "HydroEstimator.h" "SimpleKalmanFilter.cpp" "SimpleKalmanFilter.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET HydroEstimator PROPERTY CXX_STANDARD 20)
endif()

# TODO: Adicione testes e instale destinos, se necessário.
find_package(Eigen3 CONFIG REQUIRED PATHS "H:/vcpkg/vcpkg/packages/eigen3_x86-windows/share/eigen3") # hard-coded solve this later
    target_link_libraries(HydroEstimator PRIVATE Eigen3::Eigen)

