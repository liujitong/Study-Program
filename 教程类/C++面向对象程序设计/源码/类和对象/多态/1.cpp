//多态-1
#include <iostream>
using namespace std;
class Base
{
public:
     void func()
     {
        cout<<"Base func"<<endl;
     }
};
class Derived : public Base
{
    void func()
    {
        cout << "Derived func()" << endl;
    }
};
int main()
{
    Base *p = new Derived();
    p->func();
    return 0;
}