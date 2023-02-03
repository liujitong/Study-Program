#include<stdio.h>
int main()
{
    int a[100][100];//矩阵
    int maxi[100];//行最大
    int n;
    int minj[100];
    for(int z=0;z<100;z++)
    {
        maxi[z]=0;
        minj[z]=65535;
    }
    scanf("%d",&n);
   
    for(int z=0;z<n;z++)
    {
        for(int y=0;y<n;y++)
        {
            scanf("%d",&a[z][y]);
        }
    }//输入矩阵各数
    
    for(int z=0;z<n;z++)
    {
        for(int p=0;p<n;p++)
        {   
            if(a[z][p]>maxi[z]) maxi[z]=a[z][p];
        }
    }//寻找每一行的最大值

    for(int z=0;z<n;z++)
    {
        for(int p=0;p<n;p++)
        {
            if(a[p][z]<minj[z]) minj[z]=a[p][z];
        }
    }//寻找每一列的最小值

    for(int h=0;h<n;h++)
    {
        for(int l=0;l<n;l++)
        {
            if(a[h][l]==maxi[h]&&a[h][l]==minj[l]) 
            {
                printf("%d %d",h,l);
                return 0;
            }            
        }
    }//找鞍点输出鞍点
    printf("NO");
}/*题目内容：
给定一个n*n矩阵A。矩阵A的鞍点是一个位置（i，j），在该位置上的元素是第i行上的最大数，第j列上的最小数。一个矩阵A也可能没有鞍点。
你的任务是找出A的鞍点。
输入格式:
输入的第1行是一个正整数n, （1<=n<=100），然后有n行，每一行有n个整数，同一行上两个整数之间有一个或多个空格。
输出格式：
对输入的矩阵，如果找到鞍点，就输出其下标。下标为两个数字，第一个数字是行号，第二个数字是列号，均从0开始计数。
如果找不到，就输出
NO
题目所给的数据保证了不会出现多个鞍点。
输入样例：
4 
1 7 4 1 
4 8 3 6 
1 6 1 2 
0 7 8 9
输出样例：
2 1
时间限制：500ms内存限制：32000kb*/