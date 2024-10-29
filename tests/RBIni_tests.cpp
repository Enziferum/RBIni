#include <gtest/gtest.h>

#include "rbini/RBIni.hpp"

namespace {
    const std::string correctIniPath = "res/correct.ini";
    const std::string badIniPath = "res/bad.ini";
}


TEST(RBIniParser, LoadFileCorrect) {
    rbini::RBIniParser parser;
    bool result = parser.loadFromFile(correctIniPath);
    ASSERT_TRUE(result);
}

TEST(RBIniParser, LoadFileBad) {
    rbini::RBIniParser parser;
    bool result = parser.loadFromFile(badIniPath);
    ASSERT_FALSE(result);
}


TEST(RBIniParser, LoadFileException) {
    std::string exceptionMessage;
    rbini::RBIniParser parser;

    try {
        parser.loadFromFile(correctIniPath);
        FAIL();
    }
    catch (const std::exception& e) {
        auto throwMessage = std::string{e.what()};
        ASSERT_EQ(throwMessage, exceptionMessage);
    }

}

TEST(RBIniParser, LoadStrCorrect) {

}