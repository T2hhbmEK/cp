#include <bits/stdc++.h>
using namespace std;

int main() {
    int w;
    cin >> w;
    if (w % 2 == 0 && w > 2) {
        cout << "yes";
    } else {
        cout << "no";
    }
    return 0;
}

/*
偶数+偶数=偶数
偶数一定可以分解成两个偶数相加
而且一定不是奇数，必须是偶数

但是要注意：
如果 w=2，分成 0+2，0并不算一部分
    所以 2 不行
对于 >2 的偶数，都可以分成 2 和 w-2 两个偶数
    肯定可以

总结：偶数 && 大于2

逻辑运算符
逻辑与 && 并且
逻辑或 || 或者
逻辑非 !  否定
*/