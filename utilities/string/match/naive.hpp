#pragma once

#include <string>
#include <string_view>

namespace utilities::string::match {

    /// The worst-case complexity is (N - M + 1)M = O(NM) = O(N^2) due to nested loops.
    auto naive_match(std::string_view pattern, std::string_view text) -> bool {
        using std::size_t;
        size_t n = text.length();
        size_t m = pattern.length();

        for (size_t i = 0; i <= n - m; i += 1) {  // try all potential starting indices

            bool found = true;

            for (size_t j = 0; j < m && found; j += 1) {
                if (pattern[j] != text[i + j]) {
                    found = false;  // abort this, shift starting index i by +1
                }
            }

            if (found) return true; // if pattern[0..m - 1] == text[i..i + m - 1]
        }

        return false;
    }

} // namespace utilities::string::match
