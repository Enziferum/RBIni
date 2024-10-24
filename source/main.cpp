#include <iostream>
#include <rbini/RBIni.hpp>

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
    rbini::RBIniReader reader;
    rbini::Section section{"Window"};
    try {
        std::cout << "size.x: " << section.getValue<int>() << std::endl;
        std::cout << "size: " << section.getValue<robot2D::vec2f>() << std::endl;
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
