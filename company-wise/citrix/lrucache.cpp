/*
146. LRU Cache
Medium

Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

The cache is initialized with a positive capacity.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache( 2

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
*/
class LRUCache {
   int cache_capacity;
   list<pair<int,int>> l1;
   unordered_map<int,list<pair<int,int>>::iterator> um1;     
public:
    LRUCache(int capacity) {
            cache_capacity = capacity;
        
    }
    
    int get(int key) {
            if(um1.find(key)==um1.end())
            {
                return -1;    
            }
            
            else
            {
                    auto it = um1[key];
                    int value = it->second;
                    l1.erase(it);
                    l1.push_front({key,value});
                    um1[key] = l1.begin();
                    return value;
                    
            }
        
    }
    
    void put(int key, int value) {
            if(um1.find(key)!=um1.end())
            {
                    auto it = um1[key];
                    l1.erase(it);
            }
            
            else
            {
                    if(um1.size()==cache_capacity)
                    {
                            auto rev_it = l1.rbegin();
                            um1.erase(rev_it->first);
                            l1.pop_back();
                    }
            }
            
            l1.push_front({key,value});
            um1[key] = l1.begin();
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */