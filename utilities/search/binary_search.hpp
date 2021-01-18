#pragma once

#include <iterator>

namespace utilities::search {

    template <typename iterator, typename Object>
    auto recursive_binary_search(iterator first, iterator last, const Object& value) -> iterator {
        iterator begin = first;
        iterator end = last;

        if (begin != end) {
            auto distance = std::distance(begin, end);
            auto middle = std::next(begin, distance / 2);

            if (*middle == value) {
                return middle;
            }
            // go downward/left
            else if (*middle < value) {
                return recursive_binary_search(std::next(middle), last, value);
            }
            // go upward/right
            else {
                return recursive_binary_search(first, middle, value);
            }
        }

        return last;
    }

    template <typename iterator, typename Object>
    auto binary_search(iterator first, iterator last, const Object& value) -> iterator {
        iterator begin = first;
        iterator end = last;

        while (begin != end) {
            auto distance = std::distance(begin, end);
            auto middle = std::next(begin, distance / 2);
            if (*middle == value) {
                return middle;
            }
            else if (*middle < value) {
                begin = std::next(middle);
            }
            else {
                end = middle;
            }
        }

        return last;
    }

} // namespace utilities::search

