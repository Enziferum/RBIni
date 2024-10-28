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

        // std::enable_if_t<std::is_invocable_r_v<T, std::declval() >>
        template<typename T>
        T getValue(const std::string& key) {
            m_values.at(key);
            //return value_formatter<T>::read(m_data);
        }

        template<typename T>
        void setValue(const std::string& key, const T& value) {
            m_values[key];
            //value_formatter<T>::write(m_data, value);
        }
    private:
        std::string m_name;
        std::unordered_map<std::string, Value> m_values;
    };

}