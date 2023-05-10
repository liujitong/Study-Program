#include<iostream>
using namespace std;
int fuction(int a,int b=19)
{
    return a+b;
}
int fuction2(int b=1,int c=1)
{
    return b+c;
}
int main()
{
    int c=fuction(20);
    cout<<c<<endl;
    c=fuction2();
    cout<<c<<endl;
    c=fuction(1,2);
    cout<<c<<endl;
}