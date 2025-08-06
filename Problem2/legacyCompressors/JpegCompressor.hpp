/**
 * Legaxy Jpeg Compressor 
 */
#ifndef JPEG_LEGACY_COMPRESS_HPP
#define JPEG_LEGACY_COMPRESS_HPP

#include <iostream>
#include <string>
using namespace std;

class JpegCompressor {
    public: 
        void JpegCompress(const string& inPath, const string& outPath) {
            cout << "Legacy JPEG Compressor " << inPath << " -> " << outPath << endl;
        }
};

#endif