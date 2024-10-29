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
        explicit Value(const std::string& data);
        Value(const Value& other) = default;
        Value& operator=(const Value& other) = default;
        Value(Value&& other) = default;
        Value& operator=(Value&& other) = default;
        ~Value() = default;

        template<typename T>
        void setAs(T&& data) {
            m_data = value_formatter<T>::write(std::forward<T>(data));
        }

        template<typename T>
        T as() const {
            return value_formatter<T>::read(m_data);
        }

        void setRaw(const std::string& data);
        const std::string& asRaw() const;
    private:
        std::string m_data;
    };

}