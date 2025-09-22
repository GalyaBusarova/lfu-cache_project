#pragma once

struct LFUTestCase {
    std::string name;
    size_t cache_size;
    std::vector<int> elements;
    int expected_hits;
};

void run_lfu_test(const LFUTestCase& test_case);
void run_all_lfu_tests();