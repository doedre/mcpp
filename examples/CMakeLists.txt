add_executable(module_usage_example main.cpp)

target_link_libraries(module_usage_example PRIVATE mcpp::core)

set_target_properties(module_usage_example
  PROPERTIES
    CXX_STANDARD 23
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)

