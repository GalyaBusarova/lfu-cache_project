#pragma once

#include <string>
#include <vector>
#include <cstddef>

struct TestCase {
    std::string name;
    size_t cache_size;
    std::vector<int> elements;
    int expected_hits;
};

void run_lfu_test(const TestCase& test_case);
void run_all_lfu_tests();
void run_id_test(const TestCase& test_case);
void run_all_ideal_tests();