#pragma once

#include <cassert>
#include <algorithm>
#include <string>
#include <string_view>

namespace utilities::string {

    auto replace(std::string_view str, std::string_view substr, std::string_view replacement) -> std::string {
        auto res = std::string();

        for (auto itr = str.begin(); itr != str.end(); ) {
            auto match = std::search(itr, str.end(), substr.begin(), substr.end());
            // TODO does this constructor work?
            res += std::string_view{itr, match};
            if (match == str.end()) break;

            res += replacement;
            itr = match + (int) substr.length();
        }

        return res;
    }

    assert(replace("tchou/tcha/tchi", "/", "!!") == "tchou!!tcha!!tchi");


} // namespace utilities::string
