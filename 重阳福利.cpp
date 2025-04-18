#include <bits/stdc++.h>
using namespace std;

int main() {
    double s = 5 + 8 + 4 + 6 + 15 + 7;
    cout << s / 100 * 6 * 8;
    return 0;
}

/*
注意实数计算
实数计算方法：
1. double 类型变量
2. 1.0 * ... 乘以常量 1.0 转换类型
3. (double) ... 强制类型转换
   转换最靠近的变量或常量
4. / 0.06 运算中有小数
*/