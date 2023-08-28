cmake_minimum_required(VERSION 3.16)
project(php_boost_ipc CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS_DEBUG "-O3 -s")

set(CMAKE_C_STANDARD 14)

SET(PHPCPP_ARCH "x86_64")
SET(PHPCPP_PHP_PATH "/usr/include/php/20210902")

INCLUDE_DIRECTORIES(
        "${PHPCPP_PHP_PATH}/"
        "${PHPCPP_PHP_PATH}/main"
        "${PHPCPP_PHP_PATH}/Zend"
        "${PHPCPP_PHP_PATH}/TSRM"
        "${PHPCPP_PHP_PATH}/ext"
        "${PHPCPP_PHP_PATH}/build/main"
        "${PHPCPP_PHP_PATH}/build/Zend"
)

include_directories(.)
SET(PHP_LIBS "php")
SET(PHP_LIB_PATH "")

IF (${PHPCPP_ARCH} STREQUAL "x86_64")
    SET(PHP_LIB_PATH "x64/")
ENDIF()

IF(CMAKE_BUILD_TYPE MATCHES DEBUG)
    IF (PHPCPP_COMPILE_TS)
        SET(PHP_LIBS      ${PHP_LIBS} "php7ts_debug")
        SET(PHP_LIB_PATH  "${PHP_LIB_PATH}Debug_TS")
    ELSE()
        SET(PHP_LIBS      ${PHP_LIBS} "php7_debug")
        SET(PHP_LIB_PATH  "${PHP_LIB_PATH}Debug")
    ENDIF()
ELSE()
    IF (PHPCPP_COMPILE_TS)
        SET(PHP_LIBS      ${PHP_LIBS} "php7ts")
        SET(PHP_LIB_PATH  "${PHP_LIB_PATH}Release_TS")
    ELSE()
        SET(PHP_LIBS      ${PHP_LIBS} "php7")
        SET(PHP_LIB_PATH  "${PHP_LIB_PATH}Release")
    ENDIF()
ENDIF()

LINK_DIRECTORIES(${PHP_LIB_PATH})

add_library(php_boost_ipc SHARED
        php_boost_ipc_arginfo.h
        php_boost_ipc.cpp
        php_php_boost_ipc.h src/IPCBoostUnorderedMap.cpp src/IPCBoostUnorderedMap.h)
