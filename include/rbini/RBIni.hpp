#pragma once
#include <unordered_map>
#include <string>

namespace rbini {

    class Section {
    public:
        Section();
        Section(const std::string& name);
        ~Section();


        template<typename T>
        T getValue();

        template<typename T>
        void setValue(const T& value);
    private:
        std::string m_data;
        std::string m_name;
    };


    class RBIniReader {
    public:
        RBIniReader();
        RBIniReader(const RBIniReader& other) = delete;
        RBIniReader& operator=(const RBIniReader& other) = delete;
        RBIniReader(RBIniReader&& other) = delete;
        RBIniReader& operator=(RBIniReader&& other) = delete;
        ~RBIniReader();

        bool loadFromFile(const std::string& filename);
        bool save2File(const std::string& filename);

        Section& operator[](const std::string& key);
        const Section& operator[](const std::string& key) const;
        const std::unordered_map<std::string, Section>& getSections() const;
    private:
        std::unordered_map<std::string, Section> m_sections;
    };

} // namespace rbini