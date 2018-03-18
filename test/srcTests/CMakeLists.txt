file(GLOB SRCS *.cpp)

ADD_EXECUTABLE(runTests ${SRCS} RpnTests/CalculatorShould.cpp RpnTests/CalculatorShould.hpp RpnTests/HelpersShould.cpp RpnTests/OperationsShould.cpp IntegralTests/CalculateShould.cpp)

TARGET_LINK_LIBRARIES(runTests
    libsrc
    GTest::Main
)

add_test(NAME runTests
         COMMAND runTests)
