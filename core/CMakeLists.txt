add_library(core)
target_sources(core
  PUBLIC
    FILE_SET CXX_MODULES FILES
      func/func.cppm
      func/function.cppm
)

add_library(mcpp::core ALIAS core)

set_target_properties(core
  PROPERTIES
    CXX_STANDARD 23
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)

