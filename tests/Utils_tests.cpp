#include <gtest/gtest.h>

#include <rbini/Utils.hpp>

namespace {

}


TEST(Utils, SplitStringN) {
    std::vector<std::string> testStrs = {"abcd", "efg", "opsv"};
    std::string testStr = "abcd+-efg+-opsv";
    std::string sep = "+-";

    auto splitted = rbini::split_n(testStr, sep);
    ASSERT_EQ(splitted.size(), testStrs.size());
    ASSERT_EQ(splitted, testStrs);
}

TEST(Utils, SplitString2) {
    std::vector<std::string> testStrs = {"1280", "720"};
    std::string testStr = "1280x720";
    char sep = 'x';

    auto splitted = rbini::split_2(testStr, sep);
    ASSERT_EQ(splitted.first, testStrs[0]);
    ASSERT_EQ(splitted.second, testStrs[1]);
}