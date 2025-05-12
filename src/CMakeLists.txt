add_library(linal SHARED
    utils.c
    point.c
    vector.c
    matrix.c
)

target_link_libraries(linal m)

install(TARGETS linal DESTINATION lib)

install(FILES
    ${CMAKE_SOURCE_DIR}/include/point.h
    ${CMAKE_SOURCE_DIR}/include/vector.h
    ${CMAKE_SOURCE_DIR}/include/utils.h
    ${CMAKE_SOURCE_DIR}/include/matrix.h
    DESTINATION include/linal
)

target_include_directories(linal PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)