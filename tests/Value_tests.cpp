#include <gtest/gtest.h>
#include <rbini/Value.hpp>
#include <rbini/Utils.hpp>

namespace robot2D {
    struct vec2f {
        float x;
        float y;
    };
}

namespace rbini {
    template<>
     struct value_formatter<::robot2D::vec2f> {
        static robot2D::vec2f read(const std::string& rawData) {
            auto [x, y] = rbini::split_2(rawData, 'x');
            robot2D::vec2f result{std::stof(x), std::stof(y)};
            return result;
        }
    };
}

TEST(Value, GetDefault) {
    int testValue = 1280;
    rbini::Value value;
    value.setRaw("1280");
    ASSERT_EQ(value.as<int>(), testValue);
}

TEST(Value, GetCustom) {
    robot2D::vec2f testValue{1280, 720};
    rbini::Value value;
    value.setRaw("1280x720");
    auto got = value.as<robot2D::vec2f>();
    ASSERT_EQ(got.x, testValue.x);
    ASSERT_EQ(got.y, testValue.y);
}