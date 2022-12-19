#include<stdio.h>
int maxi(int x,int y)
{
    if(x>=y) return x;
    else return y;
}
int mini(int x,int y)
{
    if(x<=y) return x;
    else return y;
}

int sort_ascending(int num) {
  int sorted = 0; // 存储排列后的整数
  int digits[3];  // 存储数字各位的数组
  int i;
  // 将数字的各位数字分离出来
  for (i = 0; i < 3; i++) {
    digits[i] = num % 10;
    num /= 10;
  }
  // 使用冒泡排序算法将数字从小到大排序
  for (i = 0; i < 3; i++) {
    int j;
    int min_index = i;
    for (j = i + 1; j < 3; j++) {
      if (digits[j] < digits[min_index]) {
        min_index = j;
      }
    }
    if (min_index != i) {
      int temp = digits[i];
      digits[i] = digits[min_index];
      digits[min_index] = temp;
    }
  }
  // 将排序后的数字重新组合成一个整数
  for (i = 0; i < 3; i++) {
    sorted = sorted * 10 + digits[i];
  }
  return sorted;
}
int sort_descending(int num) {
  int sorted = 0; // 存储排列后的整数
  int digits[3];  // 存储数字各位的数组
  int i;
  // 将数字的各位数字分离出来
  for (i = 0; i < 3; i++) {
    digits[i] = num % 10;
    num /= 10;
  }
  // 使用冒泡排序算法将数字从大到小排序
  for (i = 0; i < 3; i++) {
    int j;
    int max_index = i;
    for (j = i + 1; j < 3; j++) {
      if (digits[j] > digits[max_index]) {
        max_index = j;
      }
    }
    if (max_index != i) {
      int temp = digits[i];
      digits[i] = digits[max_index];
      digits[max_index] = temp;
    }
  }
  // 将排序后的数字重新组合成一个整数
  for (i = 0; i < 3; i++) {
    sorted = sorted * 10 + digits[i];
  }
  return sorted;
}
int main()
{
    int cnt=1;
    int input;
    scanf("%d",&input);
    do    
    {
        int max;
        int min;
        int n;
        int z;
        n=sort_descending(input);
        z=sort_ascending(input);
        max= maxi(n,z);
        min= mini(n,z);
        printf("%d: %d - %d = %d\n",cnt,max,min,max-min);
        input=max-min;
        cnt++;
    }while(input!=495&&input!=0);
}
/*黑洞数也称为陷阱数，又称“Kaprekar问题”，是一类具有奇特转换特性的数。

任何一个各位数字不全相同的三位数，经有限次“重排求差”操作，总会得到495。最后所得的495即为三位黑洞数。所谓“重排求差”操作即组成该数的数字重排后的最大数减去重排后的最小数。（6174为四位黑洞数。）

例如，对三位数207：

第1次重排求差得：720 - 27 ＝ 693；
第2次重排求差得：963 - 369 ＝ 594；
第3次重排求差得：954 - 459 ＝ 495；
以后会停留在495这一黑洞数。如果三位数的3个数字全相同，一次转换后即为0。

任意输入一个三位数，编程给出重排求差的过程。

输入格式：
输入在一行中给出一个三位数。

输出格式：
按照以下格式输出重排求差的过程：

序号: 数字重排后的最大数 - 重排后的最小数 = 差值
序号从1开始，直到495出现在等号右边为止。

输入样例：
123
输出样例：
1: 321 - 123 = 198
2: 981 - 189 = 792
3: 972 - 279 = 693
4: 963 - 369 = 594
5: 954 - 459 = 495
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB*/