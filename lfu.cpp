#include <iostream>
#include <assert.h>

#include "hash.h"
#include "tests.h"

using namespace std;

int main()
{
    int sum_elem;
    size_t size_cache;
    cin >> size_cache >> sum_elem;

    typedef int elem_t;

    cache_t<elem_t> cache(size_cache);

    int hits = 0;

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

    cout << hits << "\n";

    test1_lfu();
    test2_lfu();
    test3_lfu();
    test4_lfu();
    test5_lfu();
    test6_lfu();
}

