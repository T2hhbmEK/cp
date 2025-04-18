#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

bool check(int a[3]) {  // 123 456 789
    int cnt[15] = {};   // 统计 0~9 出现的次数 {0,1,1,1,1,1,1,1,1,1}
    for (int i = 0; i < 3; i++) {
        while (a[i]) {
            cnt[a[i] % 10]++;
            a[i] /= 10;
        }
    }
    if (cnt[0] != 0) return 0;
    for (int i = 1; i <= 9; i++) {
        if (cnt[i] != 1) return 0;
    }
    return 1;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int a, b, c;
    cin >> a >> b >> c;
    int cnt = 0;
    for (int i = 1; c * i <= 999; i++) {
        if (a * i < 100) continue;
        int s[] = {a * i, b * i, c * i};
        if (check(s)) {
            cnt++;
            cout << a * i << " " << b * i << " " << c * i << endl;
        }
    }
    /* 稍慢一点的写法
    for (int i = 123; i <= 987; i++) {
        if (i % a == 0) {
            int s[] = {i, i / a * b, i / a * c};
        }
    }*/
    if (cnt == 0) {
        cout << "No!!!";
    }
    return 0;
}
