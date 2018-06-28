set(LIBRARY_TARGET_NAME twosum)

set(${LIBRARY_TARGET_NAME}_SRC
    two_sum.cpp
)

set(${LIBRARY_TARGET_NAME}_HDR
    ${CMAKE_CURRENT_SOURCE_DIR}/two_sum.h
)

add_library(${LIBRARY_TARGET_NAME} "")
set_target_properties(${LIBRARY_TARGET_NAME} 
    PROPERTIES VERSION       ${${PROJECT_NAME}_VERSION}
)

target_sources(
    twosum
    PRIVATE
        ${${LIBRARY_TARGET_NAME}_SRC}
    PUBLIC
        ${${LIBRARY_TARGET_NAME}_HDR}
    )

target_include_directories(${LIBRARY_TARGET_NAME} 
    PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
           "$<INSTALL_INTERFACE:$<INSTALL_PREFIX>/${CMAKE_INSTALL_INCLUDEDIR}>")

# Specify installation targets, typology and destination folders.
install(TARGETS ${LIBRARY_TARGET_NAME}
    EXPORT        ${PROJECT_NAME}
    LIBRARY       DESTINATION "${CMAKE_INSTALL_LIBDIR}"                            COMPONENT lib
    ARCHIVE       DESTINATION "${CMAKE_INSTALL_LIBDIR}"                            COMPONENT lib
    RUNTIME       DESTINATION "${CMAKE_INSTALL_BINDIR}"                            COMPONENT bin
    PUBLIC_HEADER DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/${LIBRARY_TARGET_NAME}" COMPONENT dev)

set_property(GLOBAL APPEND PROPERTY ${PROJECT_NAME}_TARGETS ${LIBRARY_TARGET_NAME})

