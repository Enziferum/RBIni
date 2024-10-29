# RBIni 
![Build Status](https://github.com/Enziferum/RBIni/actions/workflows/ci.yml/badge.svg) \
Simple .ini parser with supporting custom types.

### Example:
```cpp 
#include "rbini/RBIni.hpp"

int main() {
    rbini::RBIniParser parser;
    
    return 0;
}
```

### Custom Type:
```cpp
#include "rbini/RBIni.hpp"
#include "rbini/Utils.hpp"

namespace math {
    struct vec2f {
        float x;
        float y;
    };
}

namespace rbini {
    template<>
    struct value_formatter<::math::vec2f> {
        static std::string write(const math::vec2f& value) {
            constexpr int precision = 2;
            std::string s = to_string(value.x, precision) + 'x' + to_string(value.y, precision);
            return s;   
        }
        
        static math::vec2f read(const std::string& rawData) {
            auto [x, y] = split_2(rawData, 'x');                
            return { std::stof(x), std::stof(y) };
        }
    }
}


int main() {
    rbini::Value value;
    math::vec2f vec{ 1280.f, 720.f };
    value.setAs(vec);
    return 0;
}    
```


## Requirements
 - C++20 compiler
 - CMake

## How-To
```shell
    git clone
    cd rbini
    cmake -B build/ -DCMAKE_BUILD_TYPE=Release/Debug
    cmake --build build/ --config==Release/Debug -- -j THREAD_COUNT
```