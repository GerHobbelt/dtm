find_package(pybind11 REQUIRED)

pybind11_add_module(_dtmpy SHARED dtmpy.cpp)

target_link_libraries(_dtmpy PRIVATE dtm)
