#include<iostream>

using namespace std;
//指针传递

void swap_ptr(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a, b;
    cin >> a >> b;
    swap_ptr(&a, &b);
    std::cout << a << std::endl << b << std::endl;
    return 0;
}