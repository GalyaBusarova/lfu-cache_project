#pragma once

#include <list>
#include <unordered_map>
#include <cstddef>

// cache element structure
template <typename T, typename KeyT = int> 
struct hash_table_elem
{
    KeyT key;
    int frequency;
};

// cache structure
template <typename T, typename KeyT = int> 
struct cache_t
{
    size_t sz_; // maximum number of elements (cache size)
    cache_t(size_t sz): sz_(sz) {};

    int min_freq; // min frequency of uses elements

    using ListIt = typename std::list<hash_table_elem<T, KeyT> >::iterator;
    std::unordered_map<KeyT, ListIt> hash_of_points;

    std::unordered_map<int, std::list<hash_table_elem<T, KeyT> > > hash_of_freq;

    bool full() const
    {
        return hash_of_points.size() >= sz_;
    }

    bool check_to_hit(KeyT key)
    {
        auto hit = hash_of_points.find(key);

        if (hit == hash_of_points.end()) // if not found
        {
            if (full())
            {
                auto& min_freq_list = hash_of_freq[min_freq];
                if (!min_freq_list.empty())
                {
                    KeyT key_to_remove = min_freq_list.back().key;
                    hash_of_points.erase(key_to_remove);
                    min_freq_list.pop_back();
                }
            }

            hash_table_elem<T, KeyT> new_elem = {key, 0};
            
            hash_of_freq[0].push_front(new_elem);
            hash_of_points[key] = hash_of_freq[0].begin();
            
            min_freq = 0;
            return false;
        }

        auto it = hit->second;
        int old_freq = it->frequency;
        
        auto& old_list = hash_of_freq[old_freq];
        old_list.erase(it);
        
        if (old_freq == min_freq && old_list.empty())
        {
            min_freq++;
        }
        

        hash_table_elem<T, KeyT> upd_elem = {key, old_freq + 1};
        
        hash_of_freq[old_freq + 1].push_front(upd_elem);
        hash_of_points[key] = hash_of_freq[old_freq + 1].begin();
        
        return true;
    }
};