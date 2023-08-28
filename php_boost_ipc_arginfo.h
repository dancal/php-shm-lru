/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 852ef7e55ba6dc92bacd78acb96eab9fd080552f */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_IPCBoostUnorderedMap___construct, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, size, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_IPCBoostUnorderedMap_get, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_IPCBoostUnorderedMap_set, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_IPCBoostUnorderedMap_unset, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_IPCBoostUnorderedMap_clear, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_IPCBoostUnorderedMap_getFreeMemory, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_IPCBoostUnorderedMap_remove arginfo_class_IPCBoostUnorderedMap_unset


ZEND_METHOD(IPCBoostUnorderedMap, __construct);
ZEND_METHOD(IPCBoostUnorderedMap, get);
ZEND_METHOD(IPCBoostUnorderedMap, set);
ZEND_METHOD(IPCBoostUnorderedMap, unset);
ZEND_METHOD(IPCBoostUnorderedMap, clear);
ZEND_METHOD(IPCBoostUnorderedMap, getFreeMemory);
ZEND_METHOD(IPCBoostUnorderedMap, remove);


static const zend_function_entry class_IPCBoostUnorderedMap_methods[] = {
	ZEND_ME(IPCBoostUnorderedMap, __construct, arginfo_class_IPCBoostUnorderedMap___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(IPCBoostUnorderedMap, get, arginfo_class_IPCBoostUnorderedMap_get, ZEND_ACC_PUBLIC)
	ZEND_ME(IPCBoostUnorderedMap, set, arginfo_class_IPCBoostUnorderedMap_set, ZEND_ACC_PUBLIC)
	ZEND_ME(IPCBoostUnorderedMap, unset, arginfo_class_IPCBoostUnorderedMap_unset, ZEND_ACC_PUBLIC)
	ZEND_ME(IPCBoostUnorderedMap, clear, arginfo_class_IPCBoostUnorderedMap_clear, ZEND_ACC_PUBLIC)
	ZEND_ME(IPCBoostUnorderedMap, getFreeMemory, arginfo_class_IPCBoostUnorderedMap_getFreeMemory, ZEND_ACC_PUBLIC)
	ZEND_ME(IPCBoostUnorderedMap, remove, arginfo_class_IPCBoostUnorderedMap_remove, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_IPCBoostUnorderedMap(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "IPCBoostUnorderedMap", class_IPCBoostUnorderedMap_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);

	return class_entry;
}
