find_package(Qt6 6.2 REQUIRED COMPONENTS Core Qml)

add_library(QtDuration SHARED
    qduration.cpp
    qduration.h
    qduration_global.h
    # plugin.cpp
)

target_compile_definitions(QtDuration PRIVATE QDURATION_LIBRARY)
target_link_libraries(QtDuration PRIVATE Qt6::Core Qt6::Qml)

target_include_directories(QtDuration PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>
)

# Install for system use
install(TARGETS QtDuration
    EXPORT QtDurationTargets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)

install(FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/qduration.h
    ${CMAKE_CURRENT_SOURCE_DIR}/QDuration
    DESTINATION include/QtDuration
)

