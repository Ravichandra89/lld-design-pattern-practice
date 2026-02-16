#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <chrono>
#include <sstream>
#include <iomanip>

using namespace std;

class Utils
{
public:
    static string now()
    {
        auto t = chrono::system_clock::now();
        auto time = chrono::system_clock::to_time_t(t);
        stringstream ss;
        ss << put_time(localtime(&time), "%Y-%m-%d %H:%M:%S");
        return ss.str();
    }
};

#endif
