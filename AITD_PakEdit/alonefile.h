#ifndef ALONEFILE_H
#define ALONEFILE_H

#include <iostream>
#include <cstdint>

extern "C" {
#include "../src/pak.h"
#include "../src/unpack.h"
#include "../src/bmp.h"
}



class AloneFile
{
public:
    AloneFile();
    ~AloneFile();
    bool read(FILE* pakfile, const char *filename, unsigned int index);
    void print();

    bool exportAsBMP(u32 offset, u32 width, u8* palette);
    bool exportUncompressed(const char *outfilename);


    static u8 palette[];

//protected:
    pakInfoStruct mInfo;
    u32 mFileOffset;
    u32 mAdditionalDescriptorSize;
    char mNameBuffer[256];

    const char* mPAKFilename;
    int mIndex;

    u8* mComprData;
    u8* mDecomprData;

    u8 mTailingBytes[0x10];//what is it? Seems not mandatory...
};

#endif // ALONEFILE_H
