#include <rbini/Value.hpp>

namespace rbini {

    Value::Value(const std::string& data): m_data{data} {}

    void Value::setRaw(const std::string& data) {
        m_data = data;
    }

    const std::string& Value::asRaw() const {
        return m_data;
    }

} // namespace rbini