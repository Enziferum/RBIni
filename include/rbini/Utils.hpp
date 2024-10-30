#pragma once

#include <string>
#include <vector>
#include <charconv>
#include <array>

namespace rbini {

    std::pair<std::string, std::string> split_2(const std::string& s, char delim);

    std::vector<std::string> split_n(const std::string& str, const std::string& delim);

    template<typename T>
    std::string to_string(const T& value, int precision = 2) {
        std::array<char, 16> buffer;
        auto [ptr, ec] = std::to_chars(
                buffer.data(),
                buffer.data() + buffer.size(),
                value, std::chars_format::fixed, precision
        );

        /*std::string format = "{:." + std::to_string(precision) + "}";
        "{:.2f}"*/
        std::string s(buffer.data(), ptr);
        return s;
    }

} // namespace rbini