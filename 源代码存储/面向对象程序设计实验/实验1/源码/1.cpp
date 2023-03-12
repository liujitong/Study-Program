#include <iostream>
using namespace std;
int main() {
    int* scores = new int[10];  // 动态分配10个整型变量的内存空间
    int maxScore = 0;

    // 循环输入10个成绩
    for (int i = 0; i < 10; i++) {
        cout << "请输入第" << i+1 << "个成绩：";
        cin >> scores[i];
        if (scores[i] > maxScore) {
            maxScore = scores[i];  // 更新最高分
        }
    }

    cout << "最高分为：" << maxScore << endl;

    delete[] scores;  // 释放内存空间

    return 0;
}