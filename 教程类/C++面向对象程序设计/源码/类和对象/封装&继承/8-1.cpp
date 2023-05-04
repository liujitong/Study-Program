//2-8-1
#include<iostream>
using namespace std;
class example
{
    friend void goodprint(example &ex);
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
void goodprint(example &ex)
{
    cout<<ex.a<<endl;
    cout<<ex.b<<endl;
}
int main()
{
    example ex(10,20);
    goodprint(ex);
}