//多态-4
#include <iostream>
using namespace std;
class Base
{
public:
    virtual ~Base()
    {
        cout << "Base析构函数" << endl;
    }
};
class Derived : public Base
{
public:
    ~Derived()
    {
        cout << "Derived析构函数" << endl;
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