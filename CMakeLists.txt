cmake_minimum_required(VERSION 3.15)
project(LibuvLearn)

aux_source_directory(src soureFiles)
add_executable(${PROJECT_NAME} ${soureFiles})

if(DEFINED USE_PRE_INSTALLED_LIBUV)

if(WIN32)
target_include_directories(${PROJECT_NAME} PUBLIC $ENV{libuv_DIR}/include)
target_link_libraries(${PROJECT_NAME} $ENV{libuv_DIR}/lib/uv_a.lib Ws2_32.lib iphlpapi.lib userenv.lib psapi.lib)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "QCC")

target_include_directories(${PROJECT_NAME} PUBLIC $ENV{libuv_DIR}/include)
target_link_libraries(${PROJECT_NAME} $ENV{libuv_DIR}/lib/libuv_a.a -lsocket)

else()
find_package(libuv REQUIRED)
target_link_libraries(${PROJECT_NAME} uv)
endif()

else()
    add_definitions(-DBUILDING_UV_SHARED=0)
    if(UNIX)

        set(cleanLinkFlag "-ffunction-sections -Wl,--gc-sections")

        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${cleanLinkFlag}")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${cleanLinkFlag}")

    endif()

add_subdirectory(libuv)
target_link_libraries(${PROJECT_NAME} uv_a)

endif()

