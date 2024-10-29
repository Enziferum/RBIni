#pragma once
#include <string>
#include <vector>

namespace rbini {

    std::pair<std::string, std::string> split_2(const std::string& s, char delim);

    std::vector<std::string> split_n(const std::string& str, const std::string& delim);

} // namespace rbini