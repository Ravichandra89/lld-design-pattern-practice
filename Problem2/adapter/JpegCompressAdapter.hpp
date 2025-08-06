#ifndef JPEG_COMPRESSOR_ADAPTER_HPP
#define JPEG_COMPRESSOR_ADAPTER_HPP

#include "ImageCompressor.hpp"
#include "../legacyCompressors/JpegCompressor.hpp"
using namespace std;

class JpegAdapter : public ImageCompressor {
        JpegCompressor legacy_jpeg;
    public: 
        void compress(const string& inPath, const string& outPath) override {
            legacy_jpeg.JpegCompress(inPath, outPath);
        }
};

#endif