//多态-5
#include <iostream>
using namespace std;
class Base
{
public:
    virtual ~Base() = 0;
};
Base::~Base()
{
    cout << "Base析构函数" << endl;
}
class Derived : public Base
{
public:
    int *p;
    Derived()
    {
        p = new int(10);
    }
    ~Derived()
    {
        cout << "Derived析构函数" << endl;
        //释放堆区数据
        if (p != NULL)
        {
            delete p;
            p = NULL;
        }
    }
};

void test01()
{
    Base *p = new Derived();
    delete p;
}
int main()
{
    test01();
    return 0;
}