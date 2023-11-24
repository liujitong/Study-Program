#include<stdio.h>

int locate(int nums[], int key,int size)
{
    int count=0;

    for (int i = 0; i < size; i++)
    {
        count++;
        if (nums[i] == key)
        {
            printf("查找次数为：%d\n", count);
            return i;
        }
    }
    return -1;
}
int main()
{
    int a[] = { 8, 15, 19, 26, 33, 41, 47, 52, 64, 90 };
    int key = 41;
    int index = locate(a, key,sizeof(a) / sizeof(a[0]));
    printf("index = %d\n", index);
    return 0;
}
