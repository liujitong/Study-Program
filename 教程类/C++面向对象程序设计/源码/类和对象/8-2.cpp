//2-8-2
#include<iostream>
using namespace std;
class example
{
    friend class example2;
    public:
    example(int a,int b)
    {
        this->a=a;
        this->b=b;
    }

    private:
    int a;
    int b;
};
class example2
{
    public:
    void print(example *ex)
    {
        cout<<ex->a<<endl;
        cout<<ex->b<<endl;
    }
};
int main()
{
    example ex(10,20);
    example2 ex2;
    ex2.print(&ex);
}