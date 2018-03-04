set(Main_SRCS
    main.cpp
)

add_executable(Calculate
    ${Main_SRCS}
)

# Specify here the libraries this program depends on
target_link_libraries(Calculate
    libsrc
)

install(TARGETS Calculate DESTINATION bin)
