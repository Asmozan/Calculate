set(libsrc_SRCS
        Example.hpp
        Rpn/Rpn.cpp Rpn/Rpn.hpp Rpn/Helpers.cpp Rpn/Helpers.hpp Rpn/Operations.cpp Rpn/Operations.hpp)

# Declare the library
add_library(libsrc STATIC
    ${libsrc_SRCS}
)

# Specify here the include directories exported
# by this library
target_include_directories(libsrc PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
