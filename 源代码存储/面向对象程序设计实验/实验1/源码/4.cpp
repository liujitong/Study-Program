#include<iostream>
using namespace std;

inline int max(int a,int b)
{
    return (a>b)?a:b;
}
inline int max (int a,int b,int c)
{
    return max(max(a,b),c);
}
int main()
{
    int x,y,z;
    x=5;
    y=21;
    z=78;
    cout << "最大值（2）" << max(x, y) << endl;
    cout << "最大值（3）" << max(x, y, z) << endl; 
    return 0;
}