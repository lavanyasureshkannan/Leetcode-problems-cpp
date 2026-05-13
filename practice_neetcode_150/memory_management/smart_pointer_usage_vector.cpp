#include <iostream>
#include <memory>
#include <vector>

template<typename... Args>
void Log(Args... args)
{
    (std::cout << ... << args) << std::endl;
}


class Myclass
{
    public:
    Myclass(int m_id) : id(m_id) 
    {
        Log("Constructor created: ", id);
    };

    ~Myclass()
    {
        Log("Destructor destroyed: ", id);
    }

    void display() const
    {
        Log("Smart pool id: ", id);
    }
    private:
    size_t id;
};

int main()
{
    std::vector<std::unique_ptr<Myclass>> my_classes;
    for(size_t i=0; i<3; i++)
    {
        my_classes.push_back(std::make_unique<Myclass>(i));
    }
    for(auto &i: my_classes)
    {
        i->display();
    }
    return 0;
}