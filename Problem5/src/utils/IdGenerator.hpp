#ifndef IDGENERATOR_HPP
#define IDGENERATOR_HPP

#include <string>
#include <atomic>
using namespace std;

class IdGenerator
{
private:
    static inline atomic<int> counter{0};

public:
    static string next(const string &prefix)
    {
        return prefix + to_string(++counter);
    }
};

#endif
