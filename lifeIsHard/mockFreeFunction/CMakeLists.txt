add_executable(MockFreeFunctionUnitTestMain
        CaesarDeciphering.cpp
        mockFreeFunctionUnitTest.cpp
    )

target_include_directories(MockFreeFunctionUnitTestMain PRIVATE
        "/opt/googletest/googletest/include/"
        "/opt/googletest/googlemock/include/"
)

target_link_libraries(MockFreeFunctionUnitTestMain PRIVATE
        "/opt/googletest/googlemock/build/libgmock.so"
        "/opt/googletest/googletest/build/libgtest.so"
        pthread
)


