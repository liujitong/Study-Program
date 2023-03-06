#include <stdio.h>
// 定义一个表示复数的结构体类型
struct complex {
    double real;
    double imag;
};
int main()
{
    // 声明两个复数变量
    struct complex num1, num2;
    // 读入第一个复数
    printf("输入第一个复数的实部和虚部（用空格隔开）：");
    scanf("%lf %lf", &num1.real, &num1.imag);
    // 读入第二个复数
    printf("输入第二个复数的实部和虚部（用空格隔开）：");
    scanf("%lf %lf", &num2.real, &num2.imag);
    // 计算两个复数的和
    struct complex sum;
    sum.real = num1.real + num2.real;
    sum.imag = num1.imag + num2.imag;
    // 打印两个复数的和
    printf("两个复数的和是 %.2lf + %.2lfi\n", sum.real, sum.imag);
    return 0;
}