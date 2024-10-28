#pragma once
#include <string>

namespace rbini {

    template<typename T>
    struct value_formatter;

    template<>
    struct value_formatter<int> {
        static std::string write(int value) {
            return std::to_string(value);
        }

        static int read(const std::string& data) {
            return std::stoi(data);
        }
    };

    template<>
    struct value_formatter<long> {
        static std::string write(long value) {
            return std::to_string(value);
        }

        static long read(const std::string& data) {
            return std::stol(data);
        }
    };

    template<>
    struct value_formatter<float> {
        static std::string write(float value) {
            return std::to_string(value);
        }

        static float read(const std::string& data) {
            return std::stof(data);
        }
    };

    template<>
    struct value_formatter<double> {
        static std::string write(double value) {
            return std::to_string(value);
        }

        static double read(const std::string& data) {
            return std::stod(data);
        }
    };

    class Value {
    public:
        Value() = default;
        Value(const std::string& data): m_data{data} {}
        ~Value() = default;


        template<typename T>
        T as() {
            return value_formatter<T>::read(m_data);
        }
    private:
        std::string m_data;
    };
}