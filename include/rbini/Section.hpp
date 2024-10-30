#pragma once
#include <string>
#include <unordered_map>

#include "Value.hpp"

namespace rbini {

    class Section {
    public:
        Section();
        Section(const std::string& name);
        Section(const Section& other) = default;
        Section& operator=(const Section& other) = default;
        Section(Section&& other) = default;
        Section& operator=(Section&& other) = default;
        ~Section();


        Value& operator[](const std::string& key);
        const Value& operator[](const std::string& key) const;

        const std::unordered_map<std::string, Value>& getValues() const;
    private:
        std::string m_name;
        std::unordered_map<std::string, Value> m_values;
    };

}