#include <rbini/Utils.hpp>

namespace rbini {

    std::pair<std::string, std::string> split_2(const std::string& s, char delim) {
        auto found = s.find_first_of(delim);
        auto s1 = s.substr(0, found);
        auto s2 = s.substr(s.length() - found - 1);
        return std::make_pair(s1, s2);
    }

    std::vector<std::string> split_n(const std::string& str, const std::string& delim) {
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