
#include <cassert>
#include <iostream>

#include "../../utilities/string/longest_substring_without_repeating_characters.hpp"
#include "../../utilities/types.hpp"
#include "../../utilities/terminal.hpp"

int main() {
    using namespace utilities::terminal;
    using utilities::string::length_of_longest_substring_without_repeating_characters;
    
    assert(3 == length_of_longest_substring_without_repeating_characters("abcabcbb"));
    assert(1 == length_of_longest_substring_without_repeating_characters("bbbbb"));
    assert(3 == length_of_longest_substring_without_repeating_characters("pwwkew"));
    assert(0 == length_of_longest_substring_without_repeating_characters(""));
    assert(1 == length_of_longest_substring_without_repeating_characters(" "));

    assert(6 == length_of_longest_substring_without_repeating_characters("abcdef"));

    std::cout << green("All test passsed :D") << std::endl;
    

    return 0;
}
