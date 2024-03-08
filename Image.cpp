#include "Image.h"

Image::Image(Header &imageHeaderData, Pixel (&imagePixelData)[], long imageSize)
{
    this->imageSize = imageSize;
    this->imageHeaderData = imageHeaderData;

    // Copy over temp data into Image object:
    for (long i = 0; i < imageSize; ++i)
    {
        this->imagePixelData.push_back(imagePixelData[i]);
    }
}
