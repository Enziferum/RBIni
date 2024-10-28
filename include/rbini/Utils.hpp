#pragma once
#include <string>
#include <vector>

namespace rbini {

    std::vector<std::string> split(const std::string& str, const std::string& delim) {
        std::vector<std::string> result;
        using idx = std::string::size_type;
        idx pos_start = 0, pos_end = 0, delim_len = delim.length();
        while((pos_end = str.find(delim, pos_start)) != std::string::npos) {
            result.push_back(str.substr(pos_start, pos_end - pos_start));
            pos_start = pos_end + delim_len;
        }

        result.push_back(str.substr(pos_start));
        return result;
    }

} // namespace rbini