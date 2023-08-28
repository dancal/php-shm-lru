#ifndef PHP_BOOST_IPC_IPCBOOSTUNORDEREDMAP_H
#define PHP_BOOST_IPC_IPCBOOSTUNORDEREDMAP_H

#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/allocators/allocator.hpp>
#include <boost/interprocess/containers/string.hpp>
#include <boost/unordered_map.hpp>
#include <unordered_map>
#include <functional>
#include <boost/functional/hash.hpp>
#include <scoped_allocator>
#include <string>


using namespace boost::interprocess;
namespace ipc = boost::interprocess;

typedef managed_shared_memory::segment_manager segment_manager_t;
typedef allocator<char, segment_manager_t> char_allocator;
typedef allocator<void, segment_manager_t> void_allocator;
typedef basic_string<char, std::char_traits<char>, char_allocator> char_string;
typedef boost::unordered_map<char_string, char_string, boost::hash<char_string>, std::equal_to<char_string>, char_allocator> msm_umap;


class IPCBoostUnorderedMap {
public:
    explicit IPCBoostUnorderedMap(std::string, int64_t);

    std::string get(const std::string &);

    bool set(const std::string &, const std::string &);

    bool unset(const std::string &);

    bool clear();

    uint64_t getFreeMemory();

    static bool remove(const std::string &);

private:
    std::string table_name;
    ipc::managed_shared_memory segment;
    msm_umap *map;

};


#endif //PHP_BOOST_IPC_IPCBOOSTUNORDEREDMAP_H
