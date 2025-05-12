add_library(linal SHARED
    utils.c
    point.c
    vector.c
    matrix.c
)

target_link_libraries(linal m)

install(TARGETS linal DESTINATION lib)

install(FILES
    point.h
    vector.h
    utils.h
    matrix.h
    DESTINATION include/linal
)