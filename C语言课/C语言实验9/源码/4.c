#include <stdio.h>
// ����һ����ʾ�����Ľṹ������
struct complex {
    double real;
    double imag;
};
int main()
{
    // ����������������
    struct complex num1, num2;
    // �����һ������
    printf("�����һ��������ʵ�����鲿���ÿո��������");
    scanf("%lf %lf", &num1.real, &num1.imag);
    // ����ڶ�������
    printf("����ڶ���������ʵ�����鲿���ÿո��������");
    scanf("%lf %lf", &num2.real, &num2.imag);
    // �������������ĺ�
    struct complex sum;
    sum.real = num1.real + num2.real;
    sum.imag = num1.imag + num2.imag;
    // ��ӡ���������ĺ�
    printf("���������ĺ��� %.2lf + %.2lfi\n", sum.real, sum.imag);
    return 0;
}