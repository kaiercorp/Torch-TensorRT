set(lib_name "core_plugins")
add_library(${lib_name} OBJECT)

target_sources(${lib_name} 
    PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/impl/interpolate_plugin.cpp"
            "${CMAKE_CURRENT_SOURCE_DIR}/impl/normalize_plugin.cpp"
            "${CMAKE_CURRENT_SOURCE_DIR}/register_plugins.cpp"
    PUBLIC  $<TARGET_OBJECTS:core_util>
)

set(HEADER_FILES 
    "${CMAKE_CURRENT_SOURCE_DIR}/plugins.h"
)

target_include_directories(${lib_name} 
    PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>"
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>" # _export.h
)

target_link_libraries(${lib_name} 
    PUBLIC
        TensorRT::nvinfer
        TensorRT::nvinfer_plugin
        torch 
        core_util
    PRIVATE
        Threads::Threads
)

if(MSVC)
    target_compile_definitions(${lib_name} PRIVATE "HINT_MSVC_LINKER_INCLUDE_SYMBOL")
endif()

include("GenerateExportHeader")
generate_export_header(${lib_name})

# Install headers
install(FILES ${HEADER_FILES} DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/torch_tensorrt/")
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${lib_name}_export.h DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}")
install(
    FILES
        "${CMAKE_CURRENT_SOURCE_DIR}/impl/interpolate_plugin.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/impl/normalize_plugin.h"
    DESTINATION
        "${CMAKE_INSTALL_INCLUDEDIR}/torch_tensorrt/core/plugins/impl"
)
