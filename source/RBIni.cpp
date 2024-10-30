#include <fstream>
#include <algorithm>

#include "rbini/RBIni.hpp"
#include "rbini/Utils.hpp"

namespace rbini {

    struct RBParserConfig {
        bool severalSectionNames { false };
    };

    class RBIniException : public std::runtime_error {
    public:
        explicit RBIniException(const std::string &msg) : std::runtime_error(msg) {}
        const char* what() const noexcept override {
            auto msg = std::runtime_error::what();
            m_outMessage = std::string{"RBIniParser Exception: "} + msg;
            return m_outMessage.c_str();
        }

    private:
        mutable std::string m_outMessage;
    };


    RBIniParser::RBIniParser() {}

    RBIniParser::~RBIniParser() = default;


    bool RBIniParser::loadFromFile(const std::string& filename) {
        RBParserConfig m_config;
        m_config.severalSectionNames = true;

        std::ifstream file(filename);
        if (!file.is_open()) {
            return false;
        }

        std::string line;
        Section* currentSection{ nullptr };

        while(std::getline( file, line)) {
            if(line.starts_with('#') || line.starts_with(';')) {
                continue; // comment
            }

            if(line.starts_with('[')) {
                std::string key = line.substr(1, line.size() - 2);
                key.erase(std::remove_if(key.begin(), key.end(),[](const char& symbol) {
                    return symbol == ' ';
                }), key.end());
                currentSection = &m_sections[key];
            }

            auto [key, value] = split_2(line, '=');
            if(currentSection == nullptr)
                throw RBIniException("Invalid Section");
            currentSection -> operator[](key) = Value(value);
        }

        return true;
    }

    bool RBIniParser::save2File(const std::string& filename) {

        std::ofstream file(filename);
        if (!file.is_open()) {
            return false;
        }

        for(const auto& [key, section] : m_sections) {
            std::string sectionName = '[' + key + ']';
            file.write(sectionName.c_str(), sectionName.size());
            file.write("\n", 1);
            for(const auto& [key, value] : section.getValues()) {
                std::string line = key + '=' + value.asRaw();
                file.write(line.c_str(), line.size());
                file.write("\n", 1);
            }
        }

        file.close();

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