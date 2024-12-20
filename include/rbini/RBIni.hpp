#pragma once
#include <unordered_map>
#include <string>
#include <vector>

#include "Section.hpp"

namespace rbini {

    class RBIniParser {
    public:
        RBIniParser();
        RBIniParser(const RBIniParser& other) = delete;
        RBIniParser& operator=(const RBIniParser& other) = delete;
        RBIniParser(RBIniParser&& other) = delete;
        RBIniParser& operator=(RBIniParser&& other) = delete;
        ~RBIniParser();

        bool loadFromFile(const std::string& filename);
        bool save2File(const std::string& filename);

        Section& operator[](const std::string& key);
        const Section& operator[](const std::string& key) const;
        const std::unordered_map<std::string, Section>& getSections() const;
    private:
        void parseFromMemory(std::vector<char> buffer);
    private:
        std::unordered_map<std::string, Section> m_sections;
    };

} // namespace rbini