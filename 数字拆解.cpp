#include <bits/stdc++.h>
using namespace std;
const int LEN = 1005;  // 高精度位数
const int N = 5005;
int dp[N][LEN];

void add(int a[], int b[], int c[]) {  // 高精度加法
    memset(c, 0, sizeof(int) * LEN);
    for (int i = 0; i < LEN - 1; ++i) {
        c[i] += a[i] + b[i];
        c[i + 1] += c[i] / 10;
        c[i] %= 10;
    }
}

void add(int a[], int b[], int c[], int d[]) {  // 三个高精度数相加
    int t[LEN];
    add(a, b, t);
    add(t, c, d);
}

void read(int a[]) {  // 读入高精度
    string s;
    cin >> s;
    int len = s.size();
    memset(a, 0, sizeof(int) * LEN);
    for (int i = 0; i < len; ++i) a[i] = s[len - i - 1] - '0';
}

void print(int a[]) {  // 输出高精度
    int i = LEN - 1;
    while (i > 0 && a[i] == 0) --i;
    for (; i >= 0; --i) cout << a[i];
    cout << endl;
}

int main() {
    // int n;
    // cin >> n;
    // dp[1][0] = dp[2][0] = 1, dp[3][0] = 2, dp[4][0] = 4;  // 边界
    // for (int i = 5; i <= n; ++i) {
    //     add(dp[i - 1], dp[i - 3], dp[i - 4], dp[i]);  // 状态转移方程
    // }
    // print(dp[n]);
    int a[LEN], b[LEN], c[LEN];
    read(a);
    read(b);
    add(a, b, c);
    print(c);
    return 0;
}
