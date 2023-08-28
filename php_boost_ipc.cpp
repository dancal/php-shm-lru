/* php_boost_ipc extension for PHP */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif
extern "C" {
#include "php.h"
#include "ext/standard/info.h"
#include "Zend/zend_exceptions.h"
#include "ext/spl/spl_exceptions.h"
}

#include "php_php_boost_ipc.h"
#include "php_boost_ipc_arginfo.h"

#include <iostream>

/* For compatibility with older PHP versions */
#ifndef ZEND_PARSE_PARAMETERS_NONE
#define ZEND_PARSE_PARAMETERS_NONE() \
    ZEND_PARSE_PARAMETERS_START(0, 0) \
    ZEND_PARSE_PARAMETERS_END()
#endif


PHP_METHOD (IPCBoostUnorderedMap, __construct) {
    zval *self = getThis();
    ze_php_boost_ipc_object *ze_obj = nullptr;
    if (self) {
        zend_string *name;
        zend_long *size;
        if (zend_parse_parameters_ex(ZEND_PARSE_PARAMS_QUIET, ZEND_NUM_ARGS(), "Sl",
                                     &name, &size) != SUCCESS) {
            zend_throw_exception_ex(spl_ce_InvalidArgumentException, 0, "Invalid arguments");
            RETURN_BOOL(false);
        }
        ze_obj = Z_PBIF_P(self);
        ze_obj->map = new IPCBoostUnorderedMap(name->val, (int64_t)size);
    }

}

PHP_METHOD (IPCBoostUnorderedMap, set) {
    zval *self = getThis();
    ze_php_boost_ipc_object *ze_obj = nullptr;
    if (self) {
        zend_string *key;
        zend_string *value;
        if (zend_parse_parameters_ex(ZEND_PARSE_PARAMS_QUIET, ZEND_NUM_ARGS(), "SS",
                                     &key, &value) != SUCCESS) {
            zend_throw_exception_ex(spl_ce_InvalidArgumentException, 0, "Invalid arguments");
            RETURN_BOOL(false);
        }

        ze_obj = Z_PBIF_P(self);
        RETURN_BOOL(ze_obj->map->set(key->val, value->val));
    }
}

PHP_METHOD (IPCBoostUnorderedMap, get) {
    zval *self = getThis();
    ze_php_boost_ipc_object *ze_obj = nullptr;
    if (self) {
        zend_string *key;
        if (zend_parse_parameters_ex(ZEND_PARSE_PARAMS_QUIET, ZEND_NUM_ARGS(), "S",
                                     &key) != SUCCESS) {
            zend_throw_exception_ex(spl_ce_InvalidArgumentException, 0, "Invalid arguments");
            RETURN_BOOL(false);
        }
        ze_obj = Z_PBIF_P(self);

        RETURN_STRING(ze_obj->map->get(key->val).c_str());
    }

}

PHP_METHOD (IPCBoostUnorderedMap, unset) {
    zval *self = getThis();
    ze_php_boost_ipc_object *ze_obj = nullptr;
    if (self) {
        zend_string *key;
        if (zend_parse_parameters_ex(ZEND_PARSE_PARAMS_QUIET, ZEND_NUM_ARGS(), "S",
                                     &key) != SUCCESS) {
            zend_throw_exception_ex(spl_ce_InvalidArgumentException, 0, "Invalid arguments");
            RETURN_BOOL(false);
        }
        ze_obj = Z_PBIF_P(self);
        RETURN_BOOL(ze_obj->map->unset(key->val));
    }
}

PHP_METHOD (IPCBoostUnorderedMap, clear) {
    zval *self = getThis();
    ze_php_boost_ipc_object *ze_obj = nullptr;
    if (self) {
        ze_obj = Z_PBIF_P(self);
        RETURN_BOOL(ze_obj->map->clear());
    }
}

PHP_METHOD (IPCBoostUnorderedMap, getFreeMemory) {
    zval *self = getThis();
    ze_php_boost_ipc_object *ze_obj = nullptr;
    if (self) {
        ze_obj = Z_PBIF_P(self);
        RETURN_LONG(ze_obj->map->getFreeMemory());
    }
}

PHP_METHOD (IPCBoostUnorderedMap, remove) {
    zend_string *name;
    if (zend_parse_parameters_ex(ZEND_PARSE_PARAMS_QUIET, ZEND_NUM_ARGS(), "S",
                                 &name) != SUCCESS) {
        zend_throw_exception_ex(spl_ce_InvalidArgumentException, 0, "Invalid arguments");
    }
    RETURN_BOOL(IPCBoostUnorderedMap::remove(name->val));
}

PHP_MINFO_FUNCTION (php_boost_ipc) {
    php_info_print_table_start();
    php_info_print_table_header(2, "php_boost_ipc support", "enabled");
    php_info_print_table_end();
}

PHP_MINIT_FUNCTION (php_boost_ipc) {
    register_class_IPCBoostUnorderedMap();
    zip_object_handlers.offset = XtOffsetOf(ze_php_boost_ipc_object, zo);

    return SUCCESS;
}

zend_module_entry php_boost_ipc_module_entry = {
        STANDARD_MODULE_HEADER,
        "php_boost_ipc",                    /* Extension name */
        nullptr,                    /* zend_function_entry */
        PHP_MINIT(php_boost_ipc),                            /* PHP_MINIT - Module initialization */
        nullptr,                            /* PHP_MSHUTDOWN - Module shutdown */
        nullptr,            /* PHP_RINIT - Request initialization */
        nullptr,                            /* PHP_RSHUTDOWN - Request shutdown */
        PHP_MINFO(php_boost_ipc),            /* PHP_MINFO - Module info */
        PHP_PHP_BOOST_IPC_VERSION,        /* Version */
        STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_PHP_BOOST_IPC
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(php_boost_ipc)
#endif
