#pragma once
// #include <cstdio>
#include <iostream>
#include <string>
#include <string_view>

namespace utilities::terminal {

    using std::cout;
    using std::string;
    // using std::string_view;

    // TODO test if you can use string_view like this
    string red(std::string s) {
        return "\x1b[35;5;31m" + s + "\033[0m";
    }

    string red(const string& str) {
        return "\x1b[35;5;31m" + str + "\033[0m";
    }

    string green(const string& str) {
        return "\x1b[35;5;32m" + str + "\033[0m";
    }

    string yellow(const string& str) {
        return "\x1b[35;5;33m" + str + "\033[0m";
    }

    string blue(const string& str) {
        return "\x1b[35;5;34m" + str + "\033[0m";
    }

    string magenta(const string& str) {
        return "\x1b[35;5;35m" + str + "\033[0m";
    }

    string cyan(const string& str) {
        return "\x1b[35;5;36m" + str + "\033[0m";
    }

    void clear_screen() {
        cout << "\033[2j\033[1;1H";
    }

}  // namespace utilities::terminal
