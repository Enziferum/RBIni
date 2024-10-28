#include <fstream>
#include <algorithm>
#include "rbini/RBIni.hpp"

namespace rbini {

    RBIniParser::RBIniParser() {}

    RBIniParser::~RBIniParser() = default;

    bool RBIniParser::loadFromFile(const std::string& filename) {

        auto split_string = [](const std::string& str, char sep) {
            auto found = str.find(sep);
            std::string line1 = str.substr(0, found);
            std::string line2 = str.substr(found + 1, str.length() - found - 1);
            return std::make_pair(line1, line2);
        };

        std::ifstream file(filename);
        if (!file.is_open()) {
            return false;
        }

        std::string line;
        Section* currentSection{nullptr};
        while(std::getline( file, line)) {
            if(line.starts_with('#') || line.starts_with(';')) {
                continue; // comment
            }

            if(line.starts_with('[')) {
                std::string key = line.substr(1, line.size() - 2);
                key.erase(std::remove_if(key.begin(), key.end(),
                                        [](const char& symbol) { return symbol == ' '; }), key.end());
                currentSection = &m_sections[key];
            }

            auto [key, value] = split_string(line,'=');
            currentSection -> operator[](key) = Value(value);
        }

        return true;
    }

    bool RBIniParser::save2File(const std::string& filename) {
        return true;
    }


    Section& RBIniParser::operator[](const std::string& key) {
        return m_sections[key];
    }

    const Section& RBIniParser::operator[](const std::string& key) const {
        return m_sections.at(key);
    }

    const std::unordered_map<std::string, Section>& RBIniParser::getSections() const {
        return m_sections;
    }

} // namespace rbini