#ifndef PNG_COMPRESS_ADAPTER_HPP
#define PNG_COMPRESS_ADAPTER_HPP

#include "ImageCompressor.hpp"
#include "../legacyCompressors/PngCompressor.hpp"
using namespace std;

class PngAdapter : public ImageCompressor {
        PngCompressor legacy_png;

    public: 
        void compress(const string& inPath, const string& outPath) override {
            legacy_png.compressPng(inPath, outPath);
        }
};

#endif