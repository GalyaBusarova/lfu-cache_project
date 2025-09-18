#include <iostream>
#include <assert.h>

#include "hash.h"
#include "tests.h"

void test1_lfu()
{
    std::cout << "Test №1 ";
    size_t size_cache = 2;

    cache_t<int> cache(size_cache);

    std::vector<int> list_of_elems = {1, 2, 1, 2, 1, 2};

    int hits = 0;

    for (int elem: list_of_elems)
    {
        if (cache.check_to_hit(elem))
        {
            hits++;
        }
    }

    assert(hits == 4);
    std::cout << "is OK!" << std::endl;
}

void test2_lfu()
{
    std::cout << "Test №2 ";
    int sum_elem = 5;
    size_t size_cache = 3;

    cache_t<int> cache(size_cache);

    std::vector <int> list_of_elems = {1, 2, 3, 4, 5};

    int hits = 0;

    for (int i = 0; i < sum_elem; i++)
    {
        hits += cache.check_to_hit(list_of_elems[i]) ? 1 : 0;
    }

    assert(hits == 0);
    std::cout << "is OK!" << std::endl;
}

void test3_lfu()
{
    std::cout << "Test №3 ";
    int sum_elem = 5;
    size_t size_cache = 2;

    cache_t<int> cache(size_cache);

    std::vector <int> list_of_elems = {1, 1, 1, 1, 1};

    int hits = 0;

    for (int i = 0; i < sum_elem; i++)
    {
        hits += cache.check_to_hit(list_of_elems[i]) ? 1 : 0;
    }

    assert(hits == 4);
    std::cout << "is OK!" << std::endl;
}

void test4_lfu()
{
    std::cout << "Test №4 ";
    int sum_elem = 8;
    size_t size_cache = 1;

    cache_t<int> cache(size_cache);

    std::vector <int> list_of_elems = {1, 2, 1, 2, 1, 2, 1, 2};

    int hits = 0;

    for (int i = 0; i < sum_elem; i++)
    {
        hits += cache.check_to_hit(list_of_elems[i]) ? 1 : 0;
    }

    assert(hits == 0);
    std::cout << "is OK!" << std::endl;
}

void test5_lfu()
{
    std::cout << "Test №5 ";
    int sum_elem = 1;
    size_t size_cache = 1;

    cache_t<int> cache(size_cache);

    std::vector <int> list_of_elems = {10};

    int hits = 0;

    for (int i = 0; i < sum_elem; i++)
    {
        hits += cache.check_to_hit(list_of_elems[i]) ? 1 : 0;
    }

    assert(hits == 0);
    std::cout << "is OK!" << std::endl;
}

void test6_lfu()
{
    std::cout << "Test №6 ";
    int sum_elem = 7;
    size_t size_cache = 3;

    cache_t<int> cache(size_cache);

    std::vector <int> list_of_elems = {1, 2, 3, 1, 2, 4, 5};

    int hits = 0;

    for (int i = 0; i < sum_elem; i++)
    {
        hits += cache.check_to_hit(list_of_elems[i]) ? 1 : 0;
    }

    assert(hits == 2);
    std::cout << "is OK!" << std::endl;
}



