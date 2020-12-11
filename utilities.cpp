#include "utilities.h"

string print_red(const string& str) {
    return "\x1b[35;5;31m" + str + "\033[0m";
}

string print_green(const string& str) {
    return "\x1b[35;5;32m" + str + "\033[0m";
}

string print_yellow(const string& str) {
    return "\x1b[35;5;33m" + str + "\033[0m";
}

string print_blue(const string& str) {
    return "\x1b[35;5;34m" + str + "\033[0m";
}

string print_magenta(const string& str) {
    return "\x1b[35;5;35m" + str + "\033[0m";
}
string print_cyan(const string& str) {
    return "\x1b[35;5;36m" + str + "\033[0m";
}

void clear_screen() {
    std::cout << "\033[2j\033[1;1H";
}

void print_at_cursor(const string& str, unsigned int x, unsigned int y) {
    // std::printf("\033[%d;%dH", x, y);
    // std::printf("%s", str.c_str());
    std::cout << "\033[10;10HThis is some text" << std::endl;
    // std::cout << "\033[" + to_string(x) + ";" + to_string(y) + "H" + str;

    // fflush(stdout);
}