#pragma once
#include <string>

namespace rbini {

    template<typename T>
    struct value_formatter;

    template<>
    struct value_formatter<int> {
        static int read(const std::string& rawData) {
            return 42;
        }
    };


    class Section {
    public:
        Section();
        Section(const std::string& name);
        Section(const Section& other) = default;
        Section& operator=(const Section& other) = default;
        Section(Section&& other) = default;
        Section& operator=(Section&& other) = default;
        ~Section();

        // std::enable_if_t<std::is_invocable_r_v<T, std::declval() >>
        template<typename T>
        T getValue() {
            return value_formatter<T>::read(m_data);
        }

        template<typename T>
        void setValue(const T& value);
    private:
        std::string m_data;
        std::string m_name;
    };

}