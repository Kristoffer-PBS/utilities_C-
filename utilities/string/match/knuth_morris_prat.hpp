#pragma once

#include <string>
#include <string_view>
#include <vector>

namespace utilities::string::match {
/// @brief
///
/// @param str
/// @return std::vector<std::size_t>

/// table[i] = where to start matching in pattern after a mismatch at i + 1.
auto prefix_table(std::string_view str) -> std::vector<std::size_t> {
  auto table = std::vector<size_t>(str.length(), 0);

  for (size_t i = 1; i < str.length(); i += 1) {
    size_t j = table[i - 1];
    while (j > 0 and str[i] != str[j]) {
      j = table[j - 1];
    }
    if (str[i] == str[j]) {
      j += 1;
    }
    table[i] = j;
  }

  return table;
}

// assert(prefix_table("dsgwadsgz") == std::vector<std::size_t> { 0, 0, 0, 0, 0,
// 1, 2, 3, 0 });

} // namespace utilities::string::match

// the Knuth Morris Prat string matching algorithm
// n = len(s)
// m = len(p)
// **build table:** time: O(m)    space: O(m)
// **matching traversal** time: O(n)     space O(1)
// **overall complexity** time: O(m + n)     space O(m)

// bool knuth_morris_prat(const std::string& pattern, const std::string& text) {
//     int i = 0, j = 0; // starting values
//     size_t n = text.length();
//     size_t m = pattern.length();

//     while (i <= n) {  // search through text string
//         while(j >= 0 && text[i] != pattern[j]) {
//             j = b[j];  // if different, reset j using b
//         }
//         i += 1;
//         j += 1;  // if same advance both pointers
//         if (j == m) {  // a match found when a == m
//             j = b[j];  // prepare j for the next possible match
//             return true;
//         }
//     }
//     return false;
// }
