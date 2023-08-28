#include <iostream>
#include <utility>

#include "IPCBoostUnorderedMap.h"


IPCBoostUnorderedMap::IPCBoostUnorderedMap(std::string name, int64_t size) : table_name(std::move(name)) {
    this->segment = ipc::managed_shared_memory(ipc::open_or_create, this->table_name.c_str(), size);

    segment.zero_free_memory();
    void_allocator alloc_inst(this->segment.get_segment_manager());
    this->map = segment.find_or_construct<msm_umap>
            (this->table_name.c_str())(3, boost::hash<char_string>(), std::equal_to<char_string>(),
                                       alloc_inst);
}

std::string IPCBoostUnorderedMap::get(const std::string &key) {
    auto manager = this->segment.get_segment_manager();
    if (manager == nullptr) {
        std::cout << "Error!" << std::endl;
        return "";
    }
    void_allocator alloc_inst(manager);
    char_string key_value(alloc_inst);
    key_value = key.c_str();
    auto pair = this->map->find(key_value);
    if (pair != this->map->end()) {
        return pair->second.c_str();
    } else {
        return "";
    }
}

bool IPCBoostUnorderedMap::set(const std::string &key, const std::string &value) {
    try {
        auto manager = this->segment.get_segment_manager();
        if (manager == nullptr) {
            std::cout << "Error!" << std::endl;
            return true;
        }
        void_allocator alloc_inst(manager);
        char_string key_object(alloc_inst);
        char_string key_value(alloc_inst);
        key_object = key.c_str();
        key_value = value.c_str();
        this->map->insert_or_assign(key_object, key_value);

        return true;
    } catch (std::exception &exception) {
        std::cout << key << ": " << exception.what() << std::endl;
        return false;
    }
}

bool IPCBoostUnorderedMap::unset(const std::string &key) {
    auto manager = this->segment.get_segment_manager();
    if (manager == nullptr) {
        std::cout << "Error!" << std::endl;
        return false;
    }
    void_allocator alloc_inst(manager);
    char_string key_object(alloc_inst);
    key_object = key.c_str();
    this->map->erase(key_object);
    return true;
}

bool IPCBoostUnorderedMap::clear() {
    this->map->clear();
    return true;
}

uint64_t IPCBoostUnorderedMap::getFreeMemory() {
    try {
        return this->segment.get_free_memory();
    } catch (std::exception &exception) {
        std::cout << exception.what() << std::endl;
        return false;
    }
}


bool IPCBoostUnorderedMap::remove(const std::string &name) {
    shared_memory_object::remove(name.c_str());
    return true;
}
