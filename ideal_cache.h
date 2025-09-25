#pragma once

#include <unordered_map>
#include <vector>
#include <list>
#include <cstddef>
#include <climits>
#include <algorithm>


template <typename T, typename KeyT = int>
class ideal_cache 
{
    size_t size_cache;
    std::unordered_map<T, typename std::list<T>::iterator> hash_of_elem;

    std::vector<T> future_req; 

    std::unordered_map<KeyT, std::vector<T> > future_index;

public:
    //ctor
    ideal_cache(size_t size, const std::vector<KeyT> &req): size_cache(size), future_req(req)
    {
        for (int i = 0; i < future_req.size(); i++)
        {
            future_index[future_req[i]].push_back(i);
        }
    }

    // check if cache is full
    bool full() const
    {
        return hash_of_elem.size() >= size_cache;
    }

    KeyT get_next_index(const KeyT key, const int now_pos) const
    {
        auto it = future_index.find(key); 
        if (it == future_index.end())
        {
            return INT_MAX; 
        }

        const auto& index_arr = it->second; 

        auto next_ind = std::upper_bound(index_arr.begin(), index_arr.end(), now_pos);

        if (next_ind == index_arr.end())
        {
            return INT_MAX;
        }

        return *next_ind;
    }

    // геттеры
    size_t get_size_cache() const
    {
        return size_cache;
    }
    const std::vector<T>& get_requests() const
    {
        return future_req;
    }
    const std::unordered_map<KeyT, std::vector<T> >& get_indexes() const
    {
        return future_index;
    }
};


template <typename T, typename KeyT = int>
int do_ideal_cache(const ideal_cache<T, KeyT>& id_cache)
{
    const auto& future_requests = id_cache.get_requests();
    
    int id_hits = 0;
    std::unordered_map<T, int> cache; 

    for (int i = 0; i < static_cast<int>(future_requests.size()); i++)
    {
        T cur_req = future_requests[i];

        if (cache.find(cur_req) != cache.end())
        {
            cache[cur_req] = id_cache.get_next_index(cur_req, i);
            id_hits++;
            continue;
        }

        if (cache.size() < id_cache.get_size_cache())
        {
            cache[cur_req] = id_cache.get_next_index(cur_req, i);
        }
        else
        {
            T key_to_remove = cur_req; 
            int farthest_ind = -1;

            for (const auto& [page, next_use] : cache)
            {
                if (next_use > farthest_ind)
                {
                    farthest_ind = next_use;
                    key_to_remove = page;
                }
            }

            cache.erase(key_to_remove);
            cache[cur_req] = id_cache.get_next_index(cur_req, i);
        }
    }

    return id_hits;
}