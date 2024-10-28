#include <gtest/gtest.h>

#include "rbini/RBIni.hpp"

namespace {
    const std::string correctIniPath = "correct.ini";
}


TEST(RBIniParser, LoadFileCorrect) {
    rbini::RBIniParser parser;
    parser.loadFromFile(correctIniPath);
}

TEST(RBIniParser, LoadFileException) {
    rbini::RBIniParser parser;
    try {

    }
    catch (const std::exception& e) {

    }
}
