#include<iostream>
using namespace std;
class example
{
public:
    int m_Age=100;
};
class example2 :virtual public example
{
public: 
    int m_Age=102;
};
class example3:virtual public example
{
    int m_age=103;
};
class example4:virtual public example2,virtual public example3
{
    public:
    void print()
    {
        cout<<example::m_Age<<endl;
        cout<<example2::m_Age<<endl;
        cout<<example3::m_Age<<endl;
        cout<<example4::m_Age<<endl;
    }
};
int main()
{
    example4 e;
    e.print();
    return 0;
}