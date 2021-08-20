find_package(pybind11 REQUIRED)

# set_target_properties(dtm PROPERTIES POSITION_INDEPENDENT_CODE TRUE)

pybind11_add_module(dtmpy SHARED dtmpy.cpp)

target_link_libraries(dtmpy PRIVATE dtm)
