add_executable(xeyday.log-test)

target_sources(xeyday.log-test
    PRIVATE
    "test.cpp"
)

target_link_libraries(xeyday.log-test
    PRIVATE
    xeyday.log
)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT xeyday.log-test)
