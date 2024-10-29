#include "rbini/Section.hpp"

namespace rbini {

    Section::Section(const std::string& name): m_name{name} {}

    Section::Section() = default;

    Section::~Section() = default;

    Value& Section::operator[](const std::string& key) {
        return m_values[key];
    }

    const Value& Section::operator[](const std::string& key) const {
        return m_values.at(key);
    }

    const std::unordered_map<std::string, Value>& Section::getValues() const {
        return m_values;
    }

} // namespace rbini