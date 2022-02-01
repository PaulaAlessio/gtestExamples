add_executable(AppUnitTestMain
               AppUnitTestMain.cpp
        OperationsTypeParamUnitTest.cpp
        OperationsValueParamUnitTest.cpp)

target_include_directories(AppUnitTestMain PRIVATE
        "/opt/googletest/googletest/include/"
        "/opt/googletest/googlemock/include/"
)

target_link_libraries( AppUnitTestMain PRIVATE
        "/opt/googletest/googlemock/build/libgmock.so"
        "/opt/googletest/googletest/build/libgtest.so"
)

