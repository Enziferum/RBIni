#include <iostream>
#include <rbini/RBIni.hpp>

int main()
{
    rbini::RBIniReader reader;
    try {

    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
