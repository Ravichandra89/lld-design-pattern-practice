/**
 * Interface for Adapter
 */
#ifndef IMAGE_COMPRESSOR_HPP
#define IMAGE_COMPRESSOR_HPP

#include <string>
using namespace std;

class ImageCompressor {
    public: 
        virtual ~ImageCompressor() = default;
        virtual void compress(const string& inPath, const string& outPath) = 0;
};

#endif