#include<stdio.h>
int main()
{
    int a;
    int b=0;
    for(a=0;a<=100;a++){
        if(a%3==0&&a%5!=0){
            printf("%-3d ",a);
            b++;
        }
        if(b==5){
            printf("\n");
            b=0;
        }
    }
}