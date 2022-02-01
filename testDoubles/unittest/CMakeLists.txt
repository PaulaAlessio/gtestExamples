add_executable(DoublesUnitTestMain
   SecurityMockUnitTest.cpp
   DBStubAndSpyUnitTest.cpp
   DBDummyUnitTest.cpp
   DBFakeUnitTest.cpp
   DoublesUnitTestMain.cpp
)

target_include_directories(DoublesUnitTestMain PRIVATE
        "/opt/googletest/googletest/include/"
        "/opt/googletest/googlemock/include/"
)

target_link_libraries(DoublesUnitTestMain PRIVATE
        "/opt/googletest/googlemock/build/libgmock.so"
        "/opt/googletest/googletest/build/libgtest.so"
        pthread
)


