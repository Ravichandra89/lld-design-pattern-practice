/**
 * Legaxy Png Compressor
 */
#ifndef PNG_LEGACY_COMPRESSOR_HPP
#define PNG_LEGACY_COMPRESSOR_HPP

#include <iostream>
#include <string>
using namespace std;

class PngCompressor {
    public: 
        void compressPng(const string& inPath, const string outPath) {
            cout << "Legacy PNG Compressor " << inPath << " -> " << outPath << endl;
        }
};

#endif