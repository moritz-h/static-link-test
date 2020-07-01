#pragma once

#include <iostream>

namespace plugin {
    class Plugin {
        static inline bool static_plugin_ = []() {
            std::cout << "static plugin" << std::endl;
            return true;
        }();
    };
}
