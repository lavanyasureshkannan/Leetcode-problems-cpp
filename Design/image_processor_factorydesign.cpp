#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>

enum class ProcessorType
{
    BLUR, SHARPEN, GRAY
};

class Image
{
public:
    Image(uint32_t width, uint32_t height)
    : m_width(width), m_height(height)
    {}

private:
    uint32_t m_width;
    uint32_t m_height;
    uint8_t* m_data;
};

// base class
class ImageProcessor
{
public:
    // pure virtual function
    virtual void perform_image_operation(Image image) = 0;
    // virtual destructor
    virtual ~ImageProcessor() { std::cout << "ImageProcessor Destroyed.\n";};
};


//sub class 1
class BlurProcessor: public ImageProcessor
{
public:
    BlurProcessor()
    {
        std::cout << "Blur Processor created.\n";   
    }

    ~BlurProcessor()
    {
        std::cout << "BlurProcessor Destroyed.\n";
    }

    void perform_image_operation(Image image)
    {
        std::cout << "Performing Blur Operation on image.\n";
    }


};

class SharpenProcessor: public ImageProcessor
{
public:
    SharpenProcessor()
    {
        std::cout << "Sharpen Processor created.\n";   
    }

    ~SharpenProcessor()
    {
        std::cout << "SharpenProcessor Destroyed.\n";
    }

    void perform_image_operation(Image image)
    {
        std::cout << "Performing Sharpen Operation on image.\n";
    }

};

class ConverToGrayscale: public ImageProcessor
{
public:
    ConverToGrayscale()
    {
        std::cout << "GrayScale Processor created.\n";   
    }

    ~ConverToGrayscale()
    {
        std::cout << "ConverToGrayscaleProcessor destroyed.\n";   
    }

    void perform_image_operation(Image image)
    {
        std::cout << "Performing Grayscale operation on image.\n";
    }


};

class ResizeProcessor: public ImageProcessor
{
public:
    ResizeProcessor(uint32_t width, uint32_t height):
        m_new_width(width), m_new_height(height)
    {
        std::cout << "ResizeProcessor created.\n";   
    }

    ~ResizeProcessor()
    {
        std::cout << "ResizeProcessor destroyed.\n";   
    }

    void perform_image_operation(Image image)
    {
        std::cout << "Resizing image to " << m_new_width << "," << m_new_height << ".\n";
    }

private:
    uint32_t m_new_width, m_new_height;
};


class ImageProcessorFactory
{
public:
    // static ImageProcessor* get_image_processor(ProcessorType process)
    static std::unique_ptr<ImageProcessor> get_image_processor(ProcessorType process)
    {
        switch (process)
        {
        case ProcessorType::BLUR:
            std::cout << "Creating BlurringProcessor\n";
            return std::make_unique<BlurProcessor>();
        case ProcessorType::SHARPEN:
            std::cout << "Creating SharpenProcessor\n";
            return std::make_unique<SharpenProcessor>();
        case ProcessorType::GRAY:
            std::cout << "Creating ConverToGrayscale\n";
            return std::make_unique<ConverToGrayscale>();
        default:
            std::cout << "Invalid Input";
            return nullptr;
        }
        
    }
};

int main()
{
    Image image(30, 40);
    std::unique_ptr<ImageProcessor> processor = ImageProcessorFactory::get_image_processor(ProcessorType :: BLUR);
    if(processor)
        processor->perform_image_operation(image);
    else
        std::cout << "Invalid command, can't create processor objet.\n";
    // ProcessorType blur = ProcessorType::BLUR;
    // std::unique_ptr<ImageProcessor> processor = ImageProcessorFactory::get_image_processor(blur);
    // processor->perform_image_operation(image);
    return 0;
}

