add_library(xeyday.log STATIC)

target_sources(xeyday.log
    PUBLIC
    FILE_SET CXX_MODULES FILES
    "log.ixx"
)

target_include_directories(xeyday.log
    PRIVATE
    "${XEYDAY_LOG_DEPENDECIES_DIR}/fixed_string/include"
)
