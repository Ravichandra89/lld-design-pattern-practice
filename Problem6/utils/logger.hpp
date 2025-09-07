#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <iostream>
#include <string>
using namespace std;

namespace utils {
    struct Logger {
        template<typename... Args> static void info(Args&&... args) {
            (cout << ... << args) << endl;
        }
    };
}

#endif