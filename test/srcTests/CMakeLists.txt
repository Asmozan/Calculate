file(GLOB SRCS *.cpp)

ADD_EXECUTABLE(runTests ${SRCS} RpnTests/RpnShould.cpp RpnTests/RpnShould.hpp RpnTests/HelpersShould.cpp)

TARGET_LINK_LIBRARIES(runTests
    libsrc
    GTest::Main
)

add_test(NAME runTests
         COMMAND runTests)
