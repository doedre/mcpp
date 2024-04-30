add_executable(core.func.function core/func/function.cpp)

target_link_libraries(core.func.function PRIVATE mcpp::core)
set_target_properties(core.func.function
  PROPERTIES
    CXX_STANDARD 23
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)

add_executable(core.refl.refl core/refl/refl.cpp)

target_link_libraries(core.refl.refl PRIVATE mcpp::core)
set_target_properties(core.refl.refl
  PROPERTIES
    CXX_STANDARD 23
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)

add_test(core.func.function core.func.function)
add_test(core.refl.refl core.refl.refl)

