#pragma once

#include <iostream>

namespace core {
    class Core {
        static inline bool static_core_ = []() {
            std::cout << "static core" << std::endl;
            return true;
        }();
    };
}
