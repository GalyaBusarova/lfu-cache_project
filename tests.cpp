#include <iostream>
#include <vector>
#include <cassert>

#include "hash.h"
#include "tests.h"

void run_lfu_test(const LFUTestCase& test_case) {
    std::cout << test_case.name << " ";
    
    cache_t<int> cache(test_case.cache_size);
    int hits = 0;
    
    for (int elem : test_case.elements) {
        hits += cache.check_to_hit(elem) ? 1 : 0;
    }
    
    assert(hits == test_case.expected_hits);
    std::cout << "is OK!" << std::endl;
}

void run_all_lfu_tests() {
    std::vector<LFUTestCase> test_cases = {
        {"test 1:", 2, {1, 2, 1, 2, 1, 2}, 4},
        {"test 2:", 3, {1, 2, 3, 4, 5}, 0},
        {"test 3:", 2, {1, 1, 1, 1, 1}, 4},
        {"test 4:", 1, {1, 2, 1, 2, 1, 2, 1, 2}, 0},
        {"test 5:", 1, {10}, 0},
        {"test 6:", 3, {1, 2, 3, 1, 2, 4, 5}, 2}
    };
    
    for (const auto& test_case : test_cases) {
        run_lfu_test(test_case);
    }
}