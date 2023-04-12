//多态-3
#include <iostream>
using namespace std;
class Base
{
public:
    virtual void func() = 0;
};
class Derived : public Base
{
    public:
    void func()
    {
        cout << "Derived func()" << endl;
    }
};
class Derived2 : public Base
{
    public:
    void func()
    {
        cout << "Derived2 func()" << endl;
    }
};
int main()
{
    Base *p = new Derived();
    Derived2 d2;
    p->func();
    d2.func();
    return 0;
}