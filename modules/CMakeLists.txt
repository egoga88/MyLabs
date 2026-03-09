add_library(common_mod STATIC)

target_sources(common_mod
    PUBLIC
    FILE_SET CXX_MODULES FILES lab_utils.cppm
)

target_compile_features(common_mod PUBLIC cxx_std_23)
