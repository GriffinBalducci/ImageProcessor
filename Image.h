#pragma once
#include <vector>
#include "Header.h"
#include "Pixel.h"
using std::vector;


class Image : private Header, private Pixel
{
public:
    Header imageHeaderData;
    long imageSize = 0;
    vector<Pixel> imagePixelData;

    Image(Header &imageHeaderData, Pixel (&imagePixelData)[], long imageSize);
};


