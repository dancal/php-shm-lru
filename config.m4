PHP_ARG_ENABLE([php_boost_ipc],
  [whether to enable php_boost_ipc support],
  [AS_HELP_STRING([--enable-php_boost_ipc],
    [Enable php_boost_ipc support])],
  [no])

if test "$PHP_PHP_BOOST_IPC" != "no"; then

  AC_DEFINE(HAVE_PHP_BOOST_IPC, 1, [ Have php_boost_ipc support ])


  PHP_BOOST_IPC_COMMON_FLAGS="-std=c++11 -Wno-write-strings -D__STDC_LIMIT_MACROS -D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1"

  EXTERNAL_LIB="rt"
  LIB_LINK_CMD="-L/usr/lib32 -l$EXTERNAL_LIB"
  PHP_ADD_LIBRARY_WITH_PATH(rt, LIB_LINK_CMD , PHP_BOOST_IPC_SHARED_LIBADD)


  PHP_REQUIRE_CXX()
  PHP_CXX_COMPILE_STDCXX(14, mandatory, PHP_PHP_BOOST_IPC_STDCXX)
  PHP_PHP_BOOST_IPC_CXX_FLAGS="$PHP_BOOST_IPC_COMMON_FLAGS $PHP_PHP_BOOST_IPC_STDCXX"
  PHP_ADD_SOURCES_X(PHP_EXT_DIR(php_boost_ipc), php_boost_ipc.cpp src/IPCBoostUnorderedMap.cpp, $PHP_PHP_BOOST_IPC_CXX_FLAGS, shared_objects_php_boost_ipc, yes)

  PHP_SUBST(PHP_BOOST_IPC_SHARED_LIBADD)
  PHP_NEW_EXTENSION(php_boost_ipc, , $ext_shared,,PHP_BOOST_IPC_COMMON_FLAGS,cxx)
  
fi
