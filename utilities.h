#ifndef COLOR_PRINT_H
#define COLOR_PRINT_H

#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

string print_red(const string& str);
string print_green(const string& str);
string print_yellow(const string& str);
string print_blue(const string& str);
string print_magenta(const string& str);
string print_cyan(const string& str);

void clear_screen();
void print_at_cursor(const string& str, unsigned int x, unsigned int y);

#endif // COLOR_PRINT_H
