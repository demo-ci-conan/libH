
#include "libH/libH.h"

#include <iostream>
#include "libA/libA.h"

void hello_libH(int indent, const std::string& msg) {
    std::cout << std::string(indent, ' ') << "libH: " << msg << std::endl;
    hello_libA(indent+1, "hello from libH");
}