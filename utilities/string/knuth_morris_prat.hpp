#pragma once

// the Knuth Morris Prat string matching algorithm

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
