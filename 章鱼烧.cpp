#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if (b < c) {
        if (a > b && a < c) {
            cout << "No";
        } else {
            cout << "Yes";
        }
    } else {  // b > c
        if ((a > b && a < c + 24) || (a > b - 24 && a < c)) {
            cout << "No";
        } else {
            cout << "Yes";
        }
    }
    return 0;
    int ta = (a - b + 24) % 24;
    int tc = (c - b + 24) % 24;
    if (ta > tc) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}

/*
注意 a b c 两两不相等，不用取等号
方法一：分情况讨论
1. b < c
2. b > c

方法二：计算相对时间之后直接比较
*/