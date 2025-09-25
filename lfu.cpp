#include <cassert>
#include <iostream>
#include <vector>

#include "hash.h"
#include "ideal_cache.h"

using namespace std;

int main()
{
    int sum_elem;
    size_t size_cache;
    cin >> size_cache >> sum_elem;

    typedef int elem_t;

    cache_t<elem_t> cache(size_cache);

    std::vector<elem_t> future_req; 

    int hits = 0;

    for (int i = 0; i < sum_elem; i++)
    {
        hash_table_elem<elem_t> elem;
        cin >> elem.key;
        
        assert(cin.good());

        future_req.push_back(elem.key);

        if (cache.check_to_hit(elem.key))
        {
            hits++;
        }
    }

    // идеальное кэширование
    ideal_cache<elem_t> id_cache(size_cache, future_req);

    int id_hits = do_ideal_cache(id_cache);

    cout << "Идеальное кэширование: " << id_hits << std::endl;
    cout << "LFU-кэширование: " << hits << "\n";
}


