#include <charconv>
#include <iostream>
#include <rbini/RBIni.hpp>

#include <fstream>
#include <vector>

#include "rbini/Utils.hpp"

namespace robot2D {

    struct vec2f {
        float x;
        float y;

        friend std::ostream& operator<<(std::ostream& os, const vec2f& vector);
    };


    std::ostream& operator<<(std::ostream& os, const vec2f& vector) {
        os << "x=" << vector.x << " y=" << vector.y << std::endl;
        return os;
    }
}

namespace rbini {

    template<typename T>
    std::string to_string(const T& value, int precision = 2) {
        std::array<char, 16> buffer;
        auto [ptr, ec] = std::to_chars(
            buffer.data(),
            buffer.data() + buffer.size(),
            value, std::chars_format::fixed, precision
        );

        std::string s(buffer.data(), ptr);
        return s;
    }


    template<>
    struct value_formatter<::robot2D::vec2f> {
        static std::string write(const robot2D::vec2f& pos) {
            std::string s = to_string(pos.x) + "x" + to_string(pos.y);
            return s;
        }

        static robot2D::vec2f read(const std::string& rawData) {
            auto [x, y] = split_2(rawData, 'x');
            return  { std::stof(x), std::stof(y) };
        }
    };
}

int main()
{
    rbini::RBIniParser parser;
    try {

        /*std::vector<char> fileBuffer;
        std::ifstream file{"test.ini", std::ios::binary};
        file.seekg(0, std::ios::end);
        int file_len = file.tellg();
        file.seekg(0, std::ios::beg);
        fileBuffer.resize(file_len);
        file.read(fileBuffer.data(), file_len);
        file.close();

        std::string iniAsStr = "[Window]\r\nsize=1280x720\r\n";

        std::unordered_map<std::string, rbini::Section> sections;

        rbini::Section* currentSection{ nullptr };
        for(auto c: iniAsStr) {
            // \r \n ; parse
            if(c == '\r' || c == '\n' || c == ';')
                continue;
            if(c == '[') {

            }
        }


        if(!parser.loadFromFile("test.ini")) {
            return -1;
        }

        std::cout << "Window size: " << parser["Window"]["size"].as<robot2D::vec2f>() << std::endl;*/

        robot2D::vec2f v1 = { 1920, 1080 };
        auto v1_str = rbini::value_formatter<robot2D::vec2f>::write(v1);

        rbini::Section section;
        section["size"] = rbini::Value(v1_str);
        parser["Engine"] = section;
        parser.save2File("write.ini");
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
