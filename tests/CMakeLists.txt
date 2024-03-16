add_executable(core.func.function core/func/function.cpp)

target_link_libraries(core.func.function PRIVATE mcpp::core)
set_target_properties(core.func.function
  PROPERTIES
    CXX_STANDARD 23
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)

add_test(core.func.function core.func.function)

