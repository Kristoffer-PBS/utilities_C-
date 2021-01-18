
#include <cassert>
#include <iostream>
#include <string>
#include <string_view>

#include "rabin_karp.hpp"

using namespace std;


auto main() -> int {

    auto text    = string { "I do not like seventy sev but seventy seven" };
    auto pattern = string { "seventy seven" };

    /* for (std::size_t i = 0; i < 50; i += 1) { */
    /*     cout << "i = " << i << "\n"; */
    /* } */

    if (utilities::string::match::rabin_karp(pattern, text)) {
        cout << "match!" << endl;
    } else {
        cout << "no match :(" << endl;
    }

    return 0;
}
