#include <iostream>
#include <vector>
#include <cassert>

#include "hash.h"
#include "tests.h"
#include "ideal_cache.h"

void run_lfu_test(const TestCase& test_case) {
    std::cout << test_case.name << " ";
    
    cache_t<int> cache(test_case.cache_size);
    int hits = 0;
    
    for (int elem : test_case.elements) {
        hits += cache.check_to_hit(elem) ? 1 : 0;
    }
    
    assert(hits == test_case.expected_hits);
    std::cout << "is OK!" << std::endl;
}

void run_id_test(const TestCase& test_case)
{
    std::cout << test_case.name << " ";

    ideal_cache<int> id_cache(test_case.cache_size, test_case.elements);

    int hits = do_ideal_cache(id_cache);

    assert(hits == test_case.expected_hits);
    std::cout << "is OK!" << std::endl;
}

void run_all_lfu_tests() {
    std::vector<TestCase> test_cases = {
        {"test 1 LFU:", 2, {1, 2, 1, 2, 1, 2}, 4},
        {"test 2 LFU:", 3, {1, 2, 3, 4, 5}, 0},
        {"test 3 LFU:", 2, {1, 1, 1, 1, 1}, 4},
        {"test 4 LFU:", 1, {1, 2, 1, 2, 1, 2, 1, 2}, 0},
        {"test 5 LFU:", 1, {10}, 0},
        {"test 6 LFU:", 3, {1, 2, 3, 1, 2, 4, 5}, 2}
    };
    
    for (const auto& test_case : test_cases) {
        run_lfu_test(test_case);
    }
}

void run_all_ideal_tests()
{
    std::vector<TestCase> test_cases = {
        {"test 1 ideal:", 4, {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5}, 6},
        {"test 2 ideal:", 3, {1, 2, 3, 1, 2, 3, 1, 2, 3}, 6},
        {"test 3 ideal:", 3, {1, 2, 3, 4, 5, 6, 7, 8}, 0},
        {"test 4 ideal:", 3, {1, 2, 3, 4, 1}, 1},
        {"test 5 ideal:", 2, {1, 2, 1, 2, 1, 2}, 4},
        {"test 6 ideal:", 5, {3, 1, 4, 1, 5, 9, 2, 6, 5}, 2}
    };

    for (const auto& test_case : test_cases) {
        run_id_test(test_case);
    }
}

int main()
{
    run_all_lfu_tests();
    run_all_ideal_tests();
}