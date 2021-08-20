find_package(GSL REQUIRED)

set(LIB ${GSL_LIBRARIES})
set(INCLUDES ${GSL_INCLUDE_DIRS} ${PROJECT_SOURCE_DIR}/include/math ${PROJECT_SOURCE_DIR}/include/gslwrap)

# Find all headers in the project include folder
file(GLOB HEADERS CONFIGURE_DEPENDS "*.hpp")
file(GLOB SOURCES "*.cpp")

# Make a static library (tradeoff of memory for better performance)
add_library(dtm SHARED ${SOURCES} ${HEADERS})

target_link_libraries(dtm ${LIB})
