//多态-2
#include <iostream>
using namespace std;
class Base
{
public:
    virtual void func()
    {
        cout << "Base func()" << endl;
    }
};
class Derived : public Base
{
    public:
    void func()
    {
        cout << "Derived func()" << endl;
    }
};
int main()
{
    Base *q= new Base();
    Base *p = new Derived();
    Derived *d = new Derived();
    q->func();
    p->func();
    d->func();
    return 0;
}