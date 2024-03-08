/*
 * References:
 * https://cop3503spring2022.slack.com/archives/C02T363KV7S/p1648072036055379
 * https://cop3503spring2022.slack.com/archives/C02T363KV7S/p1648221759243049
 */

#include <iostream>
#include <fstream>
#include <vector>
#include "Header.h"
#include "Pixel.h"
#include "Image.h"
using std::ifstream;
using std::ofstream;
using std::string;
using std::vector;
using std::cout;
using std::endl;

ifstream LoadFile(const string& file); // <- Loads file by number and passes to manipulation function(s)

Image ReadFile(ifstream& loadedFile); // <- Takes in loaded file and reads data

void SaveFile(int specifierNumber, Image& newImage); // <- Takes in the newImage and outputs file

// Image Manipulators:
Image Multiply(Image &Bottom, Image &Top);
Image Subtract(Image &Bottom, Image &Top);
Image Screen(Image &Bottom, Image &Top);
Image Overlay(Image &Bottom, Image &Top);
Image SeparateColor(Image &image, int colorSpecifier);
Image CombineColor(Image &blueImage, Image &greenImage, Image &redImage);
Image Rotate180(Image &image);
void AddColor(Image &image, int colorSpecifier, int amount);
void MultiplyColor(Image &image, int colorSpecifier, int amount);

/* Testing Architecture:
void CheckFunction();
bool CompareImages(const Image& image1, const Image& image2);
 */


int main()
{
    ifstream loadedFile; // <- Stores currently loaded file
    vector<Image> readFiles; // <- Stores any currently read files

    for (int i = 1; i <= 10; ++i)
    {
        if (i == 1) // <- Task 1
        {
            // Load & read files:
            loadedFile = LoadFile("pattern1");
            readFiles.push_back(ReadFile(loadedFile));
            loadedFile.close();
            loadedFile = LoadFile("layer1");
            readFiles.push_back(ReadFile(loadedFile));
            loadedFile.close();

            // Manipulate files:
            Image newImage = Multiply(readFiles[0], readFiles[1]);
            readFiles.clear();

            // Save new file/image:
            SaveFile(1, newImage);
        }
        else if (i == 2) // <- Task 2
        {
            // Load & read files:
            loadedFile = LoadFile("car");
            readFiles.push_back(ReadFile(loadedFile));
            loadedFile.close();
            loadedFile = LoadFile("layer2");
            readFiles.push_back(ReadFile(loadedFile));
            loadedFile.close();

            // Manipulate files:
            Image newImage = Subtract(readFiles[0], readFiles[1]);
            readFiles.clear();

            // Save new file/image:
            SaveFile(2, newImage);
        }
        else if (i == 3) // <- Task 3
        {
            // Part A: -------------------------------------------------------------------------------------------------
            // Load & read files:
            loadedFile = LoadFile("pattern2");
            readFiles.push_back(ReadFile(loadedFile));
            loadedFile.close();
            loadedFile = LoadFile("layer1");
            readFiles.push_back(ReadFile(loadedFile));
            loadedFile.close();

            // Manipulate files:
            Image newImage = Multiply(readFiles[0], readFiles[1]);
            readFiles.clear();

            // Part B: -------------------------------------------------------------------------------------------------
            // Load & read files:
            readFiles.push_back(newImage);
            loadedFile = LoadFile("text");
            readFiles.push_back(ReadFile(loadedFile));
            loadedFile.close();

            // Manipulate files:
            newImage = Screen(readFiles[0], readFiles[1]);
            readFiles.clear();

            // Save new file/image:
            SaveFile(3, newImage);
        }
        else if (i == 4) // <- Task 4
        {
            // Part A: -------------------------------------------------------------------------------------------------
            // Load & read files:
            loadedFile = LoadFile("circles");
            readFiles.push_back(ReadFile(loadedFile));
            loadedFile.close();
            loadedFile = LoadFile("layer2");
            readFiles.push_back(ReadFile(loadedFile));
            loadedFile.close();

            // Manipulate files:
            Image newImage = Multiply(readFiles[0], readFiles[1]);
            readFiles.clear();

            // Part B: -------------------------------------------------------------------------------------------------
            // Load & read files:
            readFiles.push_back(newImage);
            loadedFile = LoadFile("pattern2");
            readFiles.push_back(ReadFile(loadedFile));
            loadedFile.close();

            // Manipulate files:
            newImage = Subtract(readFiles[0], readFiles[1]);
            readFiles.clear();

            // Save new file/image:
            SaveFile(4, newImage);
        }
        else if (i == 5) // <- Task 5
        {
            // Load & read files:
            loadedFile = LoadFile("pattern1");
            readFiles.push_back(ReadFile(loadedFile));
            loadedFile.close();
            loadedFile = LoadFile("layer1");
            readFiles.push_back(ReadFile(loadedFile));
            loadedFile.close();

            // Manipulate files:
            Image newImage = Overlay(readFiles[0], readFiles[1]);
            readFiles.clear();

            // Save new file/image:
            SaveFile(5, newImage);
        }
        else if (i == 6) // <- Task 6
        {
            // Load & read files:
            loadedFile = LoadFile("car");
            readFiles.push_back(ReadFile(loadedFile));
            loadedFile.close();

            // Manipulate files:
            AddColor(readFiles[0], 2, 200);

            // Save new file/image:
            SaveFile(6, readFiles[0]);
            readFiles.clear();
        }
        else if (i == 7) // <- Task 7
        {
            // Load & read files:
            loadedFile = LoadFile("car");
            readFiles.push_back(ReadFile(loadedFile));
            loadedFile.close();

            // Manipulate files:
            MultiplyColor(readFiles[0], 3, 4);
            MultiplyColor(readFiles[0], 1, 0);

            // Save new file/image:
            SaveFile(7, readFiles[0]);
            readFiles.clear();
        }
        else if (i == 8)
        {
            // Load & read files:
            loadedFile = LoadFile("car");
            readFiles.push_back(ReadFile(loadedFile));
            loadedFile.close();

            // Separate blue:
            Image newImage = SeparateColor(readFiles[0], 1);
            SaveFile(81, newImage);

            // Separate green:
            newImage = SeparateColor(readFiles[0], 2);
            SaveFile(82, newImage);

            // Separate red:
            newImage = SeparateColor(readFiles[0], 3);
            SaveFile(83, newImage);

            readFiles.clear();
        }
        else if (i == 9)
        {
            // Load & read files:
            loadedFile = LoadFile("layer_blue");
            readFiles.push_back(ReadFile(loadedFile));
            loadedFile.close();
            loadedFile = LoadFile("layer_green");
            readFiles.push_back(ReadFile(loadedFile));
            loadedFile.close();
            loadedFile = LoadFile("layer_red");
            readFiles.push_back(ReadFile(loadedFile));
            loadedFile.close();

            // Combine files:
            Image newImage = CombineColor(readFiles[0],readFiles[1],readFiles[2]);
            readFiles.clear();

            // Save new file/image:
            SaveFile(9, newImage);
        }
        else if (i == 10)
        {
            // Load & read files:
            loadedFile = LoadFile("text2");
            readFiles.push_back(ReadFile(loadedFile));
            loadedFile.close();

            // Flip image:
            Image newImage = Rotate180(readFiles[0]);
            readFiles.clear();

            // Save new file/image:
            SaveFile(10, newImage);
        }
    }

    // CheckFunction();

    return 0;
}

ifstream LoadFile(const string& file)
{
    ifstream loadedFile; // <- Current loaded file

    if (file == "pattern1")
    {
        loadedFile.open("input/pattern1.tga", std::ios_base::binary);
    }
    else if (file == "pattern2")
    {
        loadedFile.open("input/pattern2.tga", std::ios_base::binary);
    }
    else if (file == "text")
    {
        loadedFile.open("input/text.tga", std::ios_base::binary);
    }
    else if (file == "text2")
    {
        loadedFile.open("input/text2.tga", std::ios_base::binary);
    }
    else if (file == "car")
    {
        loadedFile.open("input/car.tga", std::ios_base::binary);
    }
    else if (file == "circles")
    {
        loadedFile.open("input/circles.tga", std::ios_base::binary);
    }
    else if (file == "layer_blue")
    {
        loadedFile.open("input/layer_blue.tga", std::ios_base::binary);
    }
    else if (file == "layer_green")
    {
        loadedFile.open("input/layer_green.tga", std::ios_base::binary);
    }
    else if (file == "layer_red")
    {
        loadedFile.open("input/layer_red.tga", std::ios_base::binary);
    }
    else if (file == "layer1")
    {
        loadedFile.open("input/layer1.tga", std::ios_base::binary);
    }
    else if (file == "layer2")
    {
        loadedFile.open("input/layer2.tga", std::ios_base::binary);
    }
    else if (file == "EXAMPLE1")
    {
        loadedFile.open("examples/EXAMPLE_part1.tga", std::ios_base::binary);
    }
    else if (file == "EXAMPLE2")
    {
        loadedFile.open("examples/EXAMPLE_part2.tga", std::ios_base::binary);
    }
    else if (file == "EXAMPLE3")
    {
        loadedFile.open("examples/EXAMPLE_part3.tga", std::ios_base::binary);
    }
    else if (file == "EXAMPLE4")
    {
        loadedFile.open("examples/EXAMPLE_part4.tga", std::ios_base::binary);
    }
    else if (file == "EXAMPLE5")
    {
        loadedFile.open("examples/EXAMPLE_part5.tga", std::ios_base::binary);
    }
    else if (file == "EXAMPLE6")
    {
        loadedFile.open("examples/EXAMPLE_part6.tga", std::ios_base::binary);
    }
    else if (file == "EXAMPLE7")
    {
        loadedFile.open("examples/EXAMPLE_part7.tga", std::ios_base::binary);
    }
    else if (file == "EXAMPLE8_b")
    {
        loadedFile.open("examples/EXAMPLE_part8_b.tga", std::ios_base::binary);
    }
    else if (file == "EXAMPLE8_g")
    {
        loadedFile.open("examples/EXAMPLE_part8_g.tga", std::ios_base::binary);
    }
    else if (file == "EXAMPLE8_r")
    {
        loadedFile.open("examples/EXAMPLE_part8_r.tga", std::ios_base::binary);
    }
    else if (file == "EXAMPLE9")
    {
        loadedFile.open("examples/EXAMPLE_part9.tga", std::ios_base::binary);
    }
    else if (file == "EXAMPLE10")
    {
        loadedFile.open("examples/EXAMPLE_part10.tga", std::ios_base::binary);
    }
    else if (file == "Part1")
    {
        loadedFile.open("output/part1.tga", std::ios_base::binary);
    }
    else if (file == "Part2")
    {
        loadedFile.open("output/part2.tga", std::ios_base::binary);
    }
    else if (file == "Part3")
    {
        loadedFile.open("output/part3.tga", std::ios_base::binary);
    }
    else if (file == "Part4")
    {
        loadedFile.open("output/part4.tga", std::ios_base::binary);
    }
    else if (file == "Part5")
    {
        loadedFile.open("output/part5.tga", std::ios_base::binary);
    }
    else if (file == "Part6")
    {
        loadedFile.open("output/part6.tga", std::ios_base::binary);
    }
    else if (file == "Part7")
    {
        loadedFile.open("output/part7.tga", std::ios_base::binary);
    }
    else if (file == "Part8_b")
    {
        loadedFile.open("output/part8_b.tga", std::ios_base::binary);
    }
    else if (file == "Part8_g")
    {
        loadedFile.open("output/part8_g.tga", std::ios_base::binary);
    }
    else if (file == "Part8_r")
    {
        loadedFile.open("output/part8_r.tga", std::ios_base::binary);
    }
    else if (file == "Part9")
    {
        loadedFile.open("output/part9.tga", std::ios_base::binary);
    }
    else if (file == "Part10")
    {
        loadedFile.open("output/part10.tga", std::ios_base::binary);
    }

    return loadedFile;
}

Image ReadFile(ifstream& loadedFile)
{
    Header tempHeader; // <- Stores temporary .tga header data
    long imageSize = 0; // <- Stores calculated image size

    // Read Header Information:
    loadedFile.read(&tempHeader.IDLength, sizeof(tempHeader.IDLength));
    loadedFile.read(&tempHeader.ColorMapType, sizeof(tempHeader.ColorMapType));
    loadedFile.read(&tempHeader.ImageType, sizeof(tempHeader.ImageType));
    loadedFile.read(reinterpret_cast<char *>(&tempHeader.ColorMapOrigin), sizeof(tempHeader.ColorMapOrigin));
    loadedFile.read(reinterpret_cast<char *>(&tempHeader.ColorMapLength), sizeof(tempHeader.ColorMapLength));
    loadedFile.read(&tempHeader.ColorMapDepth, sizeof(tempHeader.ColorMapDepth));
    loadedFile.read(reinterpret_cast<char *>(&tempHeader.XOrigin), sizeof(tempHeader.XOrigin));
    loadedFile.read(reinterpret_cast<char *>(&tempHeader.YOrigin), sizeof(tempHeader.YOrigin));
    loadedFile.read(reinterpret_cast<char *>(&tempHeader.ImageWidth), sizeof(tempHeader.ImageWidth));
    loadedFile.read(reinterpret_cast<char *>(&tempHeader.ImageHeight), sizeof(tempHeader.ImageHeight));
    loadedFile.read(&tempHeader.PixelDepth, sizeof(tempHeader.PixelDepth));
    loadedFile.read(&tempHeader.ImageDesc, sizeof(tempHeader.ImageDesc));

    // Calculate image size and create vector of pixels:
    imageSize = tempHeader.ImageHeight * tempHeader.ImageWidth;
    Pixel pixels[imageSize];

    // Read pixel data from image:
    for (int i = 0; i < imageSize; ++i)
    {
        loadedFile.read(reinterpret_cast<char *>(&pixels[i].blue), sizeof(pixels[i].blue));
        loadedFile.read(reinterpret_cast<char *>(&pixels[i].green), sizeof(pixels[i].green));
        loadedFile.read(reinterpret_cast<char *>(&pixels[i].red), sizeof(pixels[i].red));
    }

    // Generate Image object and return it:
    Image readImage(tempHeader, reinterpret_cast<Pixel (&)[]>(pixels), imageSize);
    return readImage;
}

void SaveFile(int specifierNumber, Image& newImage)
{
    // Prepare new output file:
    ofstream outputImage; // <- Takes image data and converts to new image output
    if (specifierNumber == 1) { outputImage.open("output/part1.tga", std::ios_base::binary); }
    else if (specifierNumber == 2) { outputImage.open("output/part2.tga", std::ios_base::binary); }
    else if (specifierNumber == 3) { outputImage.open("output/part3.tga", std::ios_base::binary); }
    else if (specifierNumber == 4) { outputImage.open("output/part4.tga", std::ios_base::binary); }
    else if (specifierNumber == 5) { outputImage.open("output/part5.tga", std::ios_base::binary); }
    else if (specifierNumber == 6) { outputImage.open("output/part6.tga", std::ios_base::binary); }
    else if (specifierNumber == 7) { outputImage.open("output/part7.tga", std::ios_base::binary); }
    else if (specifierNumber == 81) { outputImage.open("output/part8_b.tga", std::ios_base::binary); }
    else if (specifierNumber == 82) { outputImage.open("output/part8_g.tga", std::ios_base::binary); }
    else if (specifierNumber == 83) { outputImage.open("output/part8_r.tga", std::ios_base::binary); }
    else if (specifierNumber == 9) { outputImage.open("output/part9.tga", std::ios_base::binary); }
    else if (specifierNumber == 10) { outputImage.open("output/part10.tga", std::ios_base::binary); }


    // Write header data:
    outputImage.write(&newImage.imageHeaderData.IDLength, sizeof(newImage.imageHeaderData.IDLength));
    outputImage.write(&newImage.imageHeaderData.ColorMapType, sizeof(newImage.imageHeaderData.ColorMapType));
    outputImage.write(&newImage.imageHeaderData.ImageType, sizeof(newImage.imageHeaderData.ImageType));
    outputImage.write(reinterpret_cast<const char *>(&newImage.imageHeaderData.ColorMapOrigin), sizeof(newImage.imageHeaderData.ColorMapOrigin));
    outputImage.write(reinterpret_cast<const char *>(&newImage.imageHeaderData.ColorMapLength), sizeof(newImage.imageHeaderData.ColorMapLength));
    outputImage.write(&newImage.imageHeaderData.ColorMapDepth, sizeof(newImage.imageHeaderData.ColorMapDepth));
    outputImage.write(reinterpret_cast<const char *>(&newImage.imageHeaderData.XOrigin), sizeof(newImage.imageHeaderData.XOrigin));
    outputImage.write(reinterpret_cast<const char *>(&newImage.imageHeaderData.YOrigin), sizeof(newImage.imageHeaderData.YOrigin));
    outputImage.write(reinterpret_cast<const char *>(&newImage.imageHeaderData.ImageWidth), sizeof(newImage.imageHeaderData.ImageWidth));
    outputImage.write(reinterpret_cast<const char *>(&newImage.imageHeaderData.ImageHeight), sizeof(newImage.imageHeaderData.ImageHeight));
    outputImage.write(&newImage.imageHeaderData.PixelDepth, sizeof(newImage.imageHeaderData.PixelDepth));
    outputImage.write(&newImage.imageHeaderData.ImageDesc, sizeof(newImage.imageHeaderData.ImageDesc));

    // Write pixel data:
    for (int i = 0; i < newImage.imageSize; ++i)
    {
        outputImage.write(reinterpret_cast<const char *>(&newImage.imagePixelData[i].blue), sizeof(newImage.imagePixelData[i].blue));
        outputImage.write(reinterpret_cast<const char *>(&newImage.imagePixelData[i].green), sizeof(newImage.imagePixelData[i].green));
        outputImage.write(reinterpret_cast<const char *>(&newImage.imagePixelData[i].red), sizeof(newImage.imagePixelData[i].red));
    }

    // Finalize and close output file/image:
    outputImage.close();
}

Image Multiply(Image &Bottom, Image &Top)
{
    Pixel newPixels[Bottom.imageSize]; // <- Stores new pixel data
    float A = 0;
    float B = 0;

    // Multiply pixels:
    for (int i = 0; i < Bottom.imageSize; ++i)
    {
        // Blue:
        A = ((float)Top.imagePixelData[i].blue / 255);
        B = ((float)Bottom.imagePixelData[i].blue / 255);
        newPixels[i].blue = (unsigned int)((255 * (A * B)) + 0.5f);

        // Green:
        A = ((float)Top.imagePixelData[i].green / 255);
        B = ((float)Bottom.imagePixelData[i].green / 255);
        newPixels[i].green = (unsigned int)((255 * (A * B)) + 0.5f);

        // Red:
        A = ((float)Top.imagePixelData[i].red / 255);
        B = ((float)Bottom.imagePixelData[i].red / 255);
        newPixels[i].red = (unsigned int)((255 * (A * B)) + 0.5f);
    }

    // Tidy up:
    Image multipliedImage(Bottom.imageHeaderData, reinterpret_cast<Pixel (&)[]>(newPixels), Bottom.imageSize);
    return multipliedImage;
}

Image Subtract(Image &Bottom, Image &Top)
{
    Pixel newPixels[Bottom.imageSize]; // <- Stores new pixel data
    float A = 0;
    float B = 0;

    // Subtract pixels:
    for (int i = 0; i < Bottom.imageSize; ++i)
    {
        // Blue:
        A = ((float)Top.imagePixelData[i].blue / 255);
        B = ((float)Bottom.imagePixelData[i].blue / 255);
        if ((B - A) < 0) // <- Low clamp
        {
            newPixels[i].blue = 0;
        }
        else
        {
            newPixels[i].blue = (unsigned int)((255 * (B - A)) + 0.5f);
        }

        // Green:
        A = ((float)Top.imagePixelData[i].green / 255);
        B = ((float)Bottom.imagePixelData[i].green / 255);
        if ((B - A) < 0) // <- Low clamp
        {
            newPixels[i].green = 0;
        }
        else
        {
            newPixels[i].green = (unsigned int)((255 * (B - A)) + 0.5f);
        }

        // Red:
        A = ((float)Top.imagePixelData[i].red / 255);
        B = ((float)Bottom.imagePixelData[i].red / 255);
        if ((B - A) < 0) // <- Low clamp
        {
            newPixels[i].red = 0;
        }
        else
        {
            newPixels[i].red = (unsigned int)((255 * (B - A)) + 0.5f);
        }
    }

    // Tidy up:
    Image subtractedImage(Bottom.imageHeaderData, reinterpret_cast<Pixel (&)[]>(newPixels), Bottom.imageSize);
    return subtractedImage;
}

Image Screen(Image &Bottom, Image &Top)
{
    Pixel newPixels[Bottom.imageSize]; // <- Stores new pixel data
    float A = 0;
    float B = 0;

    // Screen pixels:
    for (int i = 0; i < Bottom.imageSize; ++i)
    {
        // Blue:
        A = ((float)Top.imagePixelData[i].blue / 255);
        B = ((float)Bottom.imagePixelData[i].blue / 255);
        newPixels[i].blue = (unsigned int)((255 * (1 - ((1 - A) * (1 - B)))) + 0.5f);

        // Green:
        A = ((float)Top.imagePixelData[i].green / 255);
        B = ((float)Bottom.imagePixelData[i].green / 255);
        newPixels[i].green = (unsigned int)((255 * (1 - ((1 - A) * (1 - B)))) + 0.5f);

        // Red:
        A = ((float)Top.imagePixelData[i].red / 255);
        B = ((float)Bottom.imagePixelData[i].red / 255);
        newPixels[i].red = (unsigned int)((255 * (1 - ((1 - A) * (1 - B)))) + 0.5f);
    }

    // Tidy up:
    Image screenedImage(Bottom.imageHeaderData, reinterpret_cast<Pixel (&)[]>(newPixels), Bottom.imageSize);
    return screenedImage;
}

Image Overlay(Image &Bottom, Image &Top)
{
    Pixel newPixels[Bottom.imageSize]; // <- Stores new pixel data
    float A = 0;
    float B = 0;

    // Overlay pixels:
    for (int i = 0; i < Bottom.imageSize; ++i)
    {
        // Blue:
        A = ((float)Top.imagePixelData[i].blue / 255);
        B = ((float)Bottom.imagePixelData[i].blue / 255);
        if (B <= 0.5)
        {
            newPixels[i].blue = (unsigned char)((255 * (2 * A * B)) + 0.5f);
        }
        else
        {
            newPixels[i].blue = (unsigned char)((255 * (1 - 2 * (1 - A) * (1 - B))) + 0.5f);
        }

        // Green:
        A = ((float)Top.imagePixelData[i].green / 255);
        B = ((float)Bottom.imagePixelData[i].green / 255);
        if (B <= 0.5)
        {
            newPixels[i].green = (unsigned char)((255 * (2 * A * B)) + 0.5f);
        }
        else
        {
            newPixels[i].green = (unsigned char)((255 * (1 - 2 * (1 - A) * (1 - B))) + 0.5f);
        }

        // Red:
        A = ((float)Top.imagePixelData[i].red / 255);
        B = ((float)Bottom.imagePixelData[i].red / 255);
        if (B <= 0.5)
        {
            newPixels[i].red = (unsigned char)((255 * (2 * A * B)) + 0.5f);
        }
        else
        {
            newPixels[i].red = (unsigned char)((255 * (1 - 2 * (1 - A) * (1 - B))) + 0.5f);
        }
    }

    // Tidy up:
    Image overlayedImage(Bottom.imageHeaderData, reinterpret_cast<Pixel (&)[]>(newPixels), Bottom.imageSize);
    return overlayedImage;
}

void AddColor(Image &image, int colorSpecifier, int amount)
{
    if (colorSpecifier == 1) // <- Add blue
    {
        for (int i = 0; i < image.imageSize; ++i)
        {
            if ((image.imagePixelData[i].blue + amount) > 255) // <- Upper clamp
            {
                image.imagePixelData[i].blue = 255;
            }
            else
            {
                image.imagePixelData[i].blue += amount;
            }
        }
    }
    else if (colorSpecifier == 2) // <- Add green
    {
        for (int i = 0; i < image.imageSize; ++i)
        {
            if ((image.imagePixelData[i].green + amount) > 255) // <- Upper clamp
            {
                image.imagePixelData[i].green = 255;
            }
            else
            {
                image.imagePixelData[i].green += amount;
            }
        }
    }
    else // <- Add red
    {
        for (int i = 0; i < image.imageSize; ++i)
        {
            if ((image.imagePixelData[i].red + amount) > 255) // <- Upper clamp
            {
                image.imagePixelData[i].red = 255;
            }
            else
            {
                image.imagePixelData[i].red += amount;
            }
        }
    }
}

void MultiplyColor(Image &image, int colorSpecifier, int amount)
{
    if (colorSpecifier == 1) // <- Multiply blue
    {
        for (int i = 0; i < image.imageSize; ++i)
        {
            if ((image.imagePixelData[i].blue * amount) > 255) // <- Upper clamp
            {
                image.imagePixelData[i].blue = 255;
            }
            else
            {
                image.imagePixelData[i].blue *= amount;
            }
        }
    }
    else if (colorSpecifier == 2) // <- Multiply green
    {
        for (int i = 0; i < image.imageSize; ++i)
        {
            if ((image.imagePixelData[i].green * amount) > 255) // <- Upper clamp
            {
                image.imagePixelData[i].green = 255;
            }
            else
            {
                image.imagePixelData[i].green *= amount;
            }
        }
    }
    else // <- Multiply red
    {
        for (int i = 0; i < image.imageSize; ++i)
        {
            if ((image.imagePixelData[i].red * amount) > 255) // <- Upper clamp
            {
                image.imagePixelData[i].red = 255;
            }
            else
            {
                image.imagePixelData[i].red *= amount;
            }
        }
    }
}

Image SeparateColor(Image &image, int colorSpecifier)
{
    Pixel newPixels[image.imageSize]; // <- Stores new pixel data

    if (colorSpecifier == 1) // <- Keep blue only
    {
        for (int i = 0; i < image.imageSize; ++i)
        {
            newPixels[i].blue = image.imagePixelData[i].blue;
            newPixels[i].green = image.imagePixelData[i].blue;
            newPixels[i].red = image.imagePixelData[i].blue;
        }
    }
    else if (colorSpecifier == 2) // <- Keep green only
    {
        for (int i = 0; i < image.imageSize; ++i)
        {
            newPixels[i].blue = image.imagePixelData[i].green;
            newPixels[i].green = image.imagePixelData[i].green;
            newPixels[i].red = image.imagePixelData[i].green;
        }
    }
    else // <- Keep red only
    {
        for (int i = 0; i < image.imageSize; ++i)
        {
            newPixels[i].blue = image.imagePixelData[i].red;
            newPixels[i].green = image.imagePixelData[i].red;
            newPixels[i].red = image.imagePixelData[i].red;
        }
    }

    // Tidy up:
    Image pulledColorImage(image.imageHeaderData, reinterpret_cast<Pixel (&)[]>(newPixels), image.imageSize);
    return pulledColorImage;
}

Image CombineColor(Image &blueImage, Image &greenImage, Image &redImage)
{
    Pixel newPixels[blueImage.imageSize]; // <- Stores new pixel data

    for (int i = 0; i < blueImage.imageSize; ++i) // <- Combine data
    {
        newPixels[i].blue = blueImage.imagePixelData[i].blue;
        newPixels[i].green = greenImage.imagePixelData[i].green;
        newPixels[i].red = redImage.imagePixelData[i].red;
    }

    // Tidy up:
    Image pulledColorImage(blueImage.imageHeaderData, reinterpret_cast<Pixel (&)[]>(newPixels), blueImage.imageSize);
    return pulledColorImage;
}

Image Rotate180(Image &image)
{
    Pixel newPixels[image.imageSize]; // <- Stores new pixel data

    for (int i = 0; i < image.imageSize; ++i) // <- Flip data
    {
        newPixels[i].blue = image.imagePixelData[image.imageSize - 1 - i].blue;
        newPixels[i].green = image.imagePixelData[image.imageSize - 1 - i].green;
        newPixels[i].red = image.imagePixelData[image.imageSize - 1 - i].red;
    }

    // Tidy up:
    Image flippedImage(image.imageHeaderData, reinterpret_cast<Pixel (&)[]>(newPixels), image.imageSize);
    return flippedImage;
}

/* TESTING ARCHITECTURE
void CheckFunction()
{
    ifstream loadedFile; // <- Stores currently loaded file
    vector<Image> readFiles; // <- Stores any currently read files


    readFiles.push_back(ReadFile(loadedFile = LoadFile("EXAMPLE1")));
    loadedFile.close();
    readFiles.push_back(ReadFile(loadedFile = LoadFile("Part1")));
    loadedFile.close();
    readFiles.push_back(ReadFile(loadedFile = LoadFile("EXAMPLE2")));
    loadedFile.close();
    readFiles.push_back(ReadFile(loadedFile = LoadFile("Part2")));
    loadedFile.close();
    readFiles.push_back(ReadFile(loadedFile = LoadFile("EXAMPLE3")));
    loadedFile.close();
    readFiles.push_back(ReadFile(loadedFile = LoadFile("Part3")));
    loadedFile.close();
    readFiles.push_back(ReadFile(loadedFile = LoadFile("EXAMPLE4")));
    loadedFile.close();
    readFiles.push_back(ReadFile(loadedFile = LoadFile("Part4")));
    loadedFile.close();
    readFiles.push_back(ReadFile(loadedFile = LoadFile("EXAMPLE5")));
    loadedFile.close();
    readFiles.push_back(ReadFile(loadedFile = LoadFile("Part5")));
    loadedFile.close();
    readFiles.push_back(ReadFile(loadedFile = LoadFile("EXAMPLE6")));
    loadedFile.close();
    readFiles.push_back(ReadFile(loadedFile = LoadFile("Part6")));
    loadedFile.close();
    readFiles.push_back(ReadFile(loadedFile = LoadFile("EXAMPLE7")));
    loadedFile.close();
    readFiles.push_back(ReadFile(loadedFile = LoadFile("Part7")));
    loadedFile.close();
    readFiles.push_back(ReadFile(loadedFile = LoadFile("EXAMPLE8_b")));
    loadedFile.close();
    readFiles.push_back(ReadFile(loadedFile = LoadFile("Part8_b")));
    loadedFile.close();
    readFiles.push_back(ReadFile(loadedFile = LoadFile("EXAMPLE8_g")));
    loadedFile.close();
    readFiles.push_back(ReadFile(loadedFile = LoadFile("Part8_g")));
    loadedFile.close();
    readFiles.push_back(ReadFile(loadedFile = LoadFile("EXAMPLE8_r")));
    loadedFile.close();
    readFiles.push_back(ReadFile(loadedFile = LoadFile("Part8_r")));
    loadedFile.close();
    readFiles.push_back(ReadFile(loadedFile = LoadFile("EXAMPLE9")));
    loadedFile.close();
    readFiles.push_back(ReadFile(loadedFile = LoadFile("Part9")));
    loadedFile.close();
    readFiles.push_back(ReadFile(loadedFile = LoadFile("EXAMPLE10")));
    loadedFile.close();
    readFiles.push_back(ReadFile(loadedFile = LoadFile("Part10")));
    loadedFile.close();

    for (int i = 0; i < 24; i += 2)
    {
        if (!CompareImages(readFiles[i], readFiles[i + 1]))
        {
            cout << i << " Failed" << endl;
        }
        else
        {
            cout << i << " Passed" << endl;
        }
    }
}

bool CompareImages(const Image& image1, const Image& image2)
{
    for (int i = 0; i < image1.imageSize; ++i)
    {
        if (image1.imagePixelData[i].blue != image2.imagePixelData[i].blue)
        {
            cout << "Current Pixel Blue: " << i << " " << (unsigned int)image1.imagePixelData[i].blue << " : " << (unsigned int)image2.imagePixelData[i].blue << endl;
            cout << "Next Pixel Blue: " << " " << (unsigned int)image1.imagePixelData[i+1].blue << " : " << (unsigned int)image2.imagePixelData[i+1].blue << endl;

            return false;
        }
        if (image1.imagePixelData[i].green != image2.imagePixelData[i].green)
        {
            cout << "Current Pixel green: " << i << " " << (unsigned int)image1.imagePixelData[i].green << " : " << (unsigned int)image2.imagePixelData[i].green << endl;
            cout << "Next Pixel green: " << (unsigned int)image1.imagePixelData[i+1].green << " : " << (unsigned int)image2.imagePixelData[i+1].green << endl;

            return false;
        }
        if (image1.imagePixelData[i].red != image2.imagePixelData[i].red)
        {
            cout << "Current Pixel red: " << i << " " << (unsigned int)image1.imagePixelData[i].red << " : " << (unsigned int)image2.imagePixelData[i].red << endl;
            cout << "Next Pixel red: " << (unsigned int)image1.imagePixelData[i+1].red << " : " << (unsigned int)image2.imagePixelData[i+1].red << endl;

            return false;
        }
    }

    if (image1.imageSize != image2.imageSize)
    {
        return false;
    }

    return true;
}
 */