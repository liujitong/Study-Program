#include<iostream>
int main()
{
    int k;
    std::cin>>k;
    double S_n=0.0;
    int i;
    for(i=1;;i++)
    {
        S_n+=1.0*1/i;
        if(S_n>k) break;
    }
    std::cout<<i<<std::endl;
    return 0;
}