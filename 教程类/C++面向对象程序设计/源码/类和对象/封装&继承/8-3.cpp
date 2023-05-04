//2-8-3
#include<iostream>
using namespace std;
class example2;
class example
{
    public:
    example();
    void print();
    private:
	example2 *ex;
};
class example2
{
    public:
    friend void example::print();
    example2()
    {
        a = 10;
        b = 20;
    }
    example2(int a, int b)
    {
        this->a = a;
        this->b = b;
    }
    private:
    int a;
    int b;
};
example::example()
{
    ex = new example2;
}
void example::print()
    {
        cout<<ex->a<<endl;
        cout<<ex->b<<endl;
    }
int main()
{
    example2 ex(100,20);
    example ex2;
    ex2.print();
    return 0;
}