#include <iostream>
#include <rbini/RBIni.hpp>

#include <fstream>
#include <vector>

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
    template<>
    struct value_formatter<::robot2D::vec2f> {
        static ::robot2D::vec2f read(const std::string& rawData) {
            return {142.f, 111.f};
        }
    };
}

int main()
{
    rbini::RBIniParser parser;
    try {

        std::vector<char> fileBuffer;
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

        std::cout << "Window size: " << parser["Window"]["size"].as<robot2D::vec2f>() << std::endl;
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
