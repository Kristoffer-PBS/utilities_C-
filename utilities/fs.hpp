#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
#include <fstream>

namespace utilities::fs {

    std::vector<std::string> read_lines(std::string path) {
        std::ifstream file(path);

        if (!file.is_open()) {
            throw std::invalid_argument("the file:\t" + path + "\t does not exist.\n");
        }

        std::string line{};
        std::vector<std::string> lines{};

        while (std::getline(file, line)) {
            lines.push_back(line);
        }

        return lines;
    }

    std::string read_to_string(const std::string& path) {

        std::ifstream file(path);

        if (!file.is_open()) {
            throw std::invalid_argument("the file:\t" + path + "\t does not exist.\n");
        }
        std::string line{};
        std::vector<std::string> lines{};

        while (std::getline(file, line)) {
            lines.push_back(line);
        }

        std::string retval{};

        for (const std::string& str : lines) {
            retval += str;
        }

        return retval;
    }
}
