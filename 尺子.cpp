#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b, flag = 0;
    cin >> n >> a >> b;
    if (a - b >= 0) {
        cout << a - b << " ";
        flag = 1;
    }
    if (a + b <= n && a + b != a - b) {
        cout << a + b << " ";
        flag = 1;
    }
    if (flag == 0) {
        cout << -1;
    }
    return 0;
    if (a - b < 0 && a + b > n) {
        cout << -1;
    } else if (a - b < 0 && a + b <= n) {
        cout << a + b;
    } else if (a - b >= 0 && a + b > n) {
        cout << a - b;
    } else if (a - b >= 0 && a + b <= n) {
        if (b != 0) {
            cout << a - b << " " << a + b;
        } else {
            cout << a;
        }
    }
    return 0;
}

/*
方法一：画表格
  ------   -----   -----------
|        | a-b<0 | a-b>=0      |
| ------ | ----- | ----------- |
| a+b>n  |       |             |
| ------ | ----- | ----------- |
| a+b<=n |       | b==0 | b!=0 |
  ------   -----   -----------

方法二：分别讨论
1. 是否输出 a-b
2. 是否输出 a+b
3. 是否输出 -1

行末的空格，最后一行的换行可有可无不影响正确
*/
