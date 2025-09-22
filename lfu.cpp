#include <cassert>
#include <iostream>

#include "hash.h"
#include "tests.h"


using namespace std;

int main()
{
    int sum_elem;
    size_t size_cache;
    cout << "Enter the cache size: ";
    cin >> size_cache;

    cout << "Enter the sum of the elements: ";
    cin >> sum_elem;

    typedef int elem_t;

    cache_t<elem_t> cache(size_cache);

    int hits = 0;

    cout << "Enter the elements: ";

    for (int i = 0; i < sum_elem; i++)
    {
        hash_table_elem<elem_t> elem;
        cin >> elem.key;
        
        assert(cin.good());

        if (cache.check_to_hit(elem.key))
        {
            hits++;
        }
    }

    cout << "LFU - кэширование: " << hits << "попадания" << "\n";

    run_all_lfu_tests();
}

