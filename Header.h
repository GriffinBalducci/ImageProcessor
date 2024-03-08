#pragma once


struct Header
{
    char IDLength = 0;
    char ColorMapType = 0;
    char ImageType = 0;
    short ColorMapOrigin = 0;
    short ColorMapLength = 0;
    char ColorMapDepth = 0;
    short XOrigin = 0;
    short YOrigin = 0;
    short ImageWidth = 0;
    short ImageHeight = 0;
    char PixelDepth = 0;
    char ImageDesc = 0;
};
