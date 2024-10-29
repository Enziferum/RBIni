#include <gtest/gtest.h>

#include <rbini/Utils.hpp>

namespace {

}


TEST(Utils, SplitStringN) {
    std::vector<std::string> testStrs = {"abcd", "efg", "opsv"};
    std::string testStr = "abcd+-efg+-opsv";
    std::string sep = "+-";

    auto splitted = rbini::split(testStr, sep);
    ASSERT_EQ(splitted.size(), testStrs.size());
    ASSERT_EQ(splitted, testStrs);
}