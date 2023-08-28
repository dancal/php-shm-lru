/* php_boost_ipc extension for PHP */

#define nullptr NULL

#ifndef PHP_PHP_BOOST_IPC_H
# define PHP_PHP_BOOST_IPC_H

#include "src/IPCBoostUnorderedMap.h"

extern zend_module_entry php_boost_ipc_module_entry;
# define phpext_php_boost_ipc_ptr &php_boost_ipc_module_entry

# define PHP_PHP_BOOST_IPC_VERSION "0.1.0"

# if defined(ZTS) && defined(COMPILE_DL_PHP_BOOST_IPC)
ZEND_TSRMLS_CACHE_EXTERN()
# endif

static zend_object_handlers zip_object_handlers;

typedef struct {
    IPCBoostUnorderedMap *map;
    //FIXME: hack for alpine...idk
    char align_it[10000];
    zend_object zo;
} ze_php_boost_ipc_object;

static inline ze_php_boost_ipc_object *php_php_boost_ipc_fetch_object(zend_object *obj) {
    return (ze_php_boost_ipc_object *) ((char *) (obj) - XtOffsetOf(ze_php_boost_ipc_object, zo));
}

#define Z_PBIF_P(zv) php_php_boost_ipc_fetch_object(Z_OBJ_P((zv)))

#endif    /* PHP_PHP_BOOST_IPC_H */
