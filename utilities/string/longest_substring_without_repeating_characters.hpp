#pragma once

#include <algorithm>
#include <iostream>
#include <set>
#include <string>

#include "../types.hpp"

namespace utilities::string {
    using namespace utilities::types;
    using std::size_t;

    // NOTE the algorithm is functionally correct, but not very effective with regards
    // space and time complexity.
    // TODO make more efficient
    u32 length_of_longest_substring_without_repeating_characters(std::string_view sv) {
        u32 longest = 0;

        for (size_t i = 0; i < sv.length(); i++) {
            std::set<char> set{};

            for (size_t j = i; j < sv.length(); j++) {
                bool result = set.insert(sv[j]).second;
                if (!result) {
                    /* longest = longest > set.size() ? longest : set.size(); */
                    break;
                }
            }

            longest = longest > set.size() ? longest : set.size();
        }

        return longest;
    }

} // namespace utilities::string

