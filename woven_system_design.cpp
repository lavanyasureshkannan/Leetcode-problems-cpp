#include <iostream>
#include <memory>
using namespace std;

// 1. create a simple class
class shape
{
    public:
    virtual void draw() = 0; // making it abstract class
    ~shape() = default; // virtual destructor
};

// 2. create  a subclass from shape
class circle : public shape
{
    public:
    void draw()
    {
        cout << "Draw a Circle" << endl;
    }
};

class square : public shape
{
    public:
    void draw()
    {
        cout << "Draw a square" << endl;
    }
};

// 3. create a factory class
class shapefactory
{
    public:
    // static shape* create_shape(const string& shape_name)
    // {
    //     if(shape_name == "circle") return new circle();
    //     else if (shape_name == "square") return new square();
    //     else return nullptr;
    // }

    static unique_ptr<shape> create_shape(const string& shape_name)
    {
        if(shape_name == "circle") return make_unique<circle>();
        else if(shape_name == "square") return make_unique<square>();
        else return nullptr;
    }
};

int main()
{
    // shape* s1 = shapefactory::create_shape("circle");
    // s1->draw();
    // shape* s2 = shapefactory::create_shape("square");
    // s2->draw();

    // delete s1;
    // delete s2;

    unique_ptr<shape> s1 = shapefactory::create_shape("circle");
    s1->draw();
    unique_ptr<shape> s2 = shapefactory::create_shape("square");
    s2->draw();
    return 0;
}

///////////////// image processor ////////////////////
enum processor_type
{
    BLUR,
    SHARPEN
};

class Image
{
    private:
    int height;
    int width;
    int* data;

    public:
    Image(int m_height, int m_width)
    {
        height = m_height;
        width = m_width;
    }
};


class Image_processor
{
    public:
    virtual void perform_image_processing(const Image& image) = 0;
    virtual ~Image_processor()
    {
        cout << "Image processor is destroyed" << endl;
    };
};

class Blur : public Image_processor
{
    public:
    void perform_image_processing(const Image& image)
    {
        cout << "Blur processor is created" << endl;
    }  
};

class sharpen : public Image_processor
{
    public:
    void perform_image_processing(const Image& image)
    {
        cout << "Sharpen processor is created" << endl;
    }
};

class Image_Processor_Factory
{
    public:
    // static unique_ptr<Image_processor> Image_processing_ptr(const string& name_processor)
    // {
    //     if(name_processor == "BLUR") return make_unique<Blur>();
    //     else if(name_processor == "sharpen") return make_unique<sharpen>();
    //     else return nullptr; 
    // }

    static unique_ptr<Image_processor> Image_Processor_ptr(processor_type process)
    {
        switch(process)
        {
            case processor_type::BLUR:
            {
                return make_unique<Blur>();
            }
            case processor_type::SHARPEN:
            {
                return make_unique<sharpen>();
            }
            default:
                return nullptr;
        }
        
    }
};

int main()
{
    int h = 10;
    int w = 20;
    Image image_1(h,w);
    //unique_ptr<Image_processor> process_image = Image_Processor_Factory::Image_processing_ptr("BLUR");
    //process_image->perform_image_processing(image_1);

    unique_ptr<Image_processor> process_1_image = Image_Processor_Factory::Image_Processor_ptr(processor_type::BLUR);
    process_1_image->perform_image_processing(image_1);
    
    unique_ptr<Image_processor> process_2_image = Image_Processor_Factory::Image_Processor_ptr(processor_type::SHARPEN);
    process_2_image->perform_image_processing(image_1);
    
    return 0;
}


