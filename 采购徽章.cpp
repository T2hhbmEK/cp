#include <bits/stdc++.h>
using namespace std;
int main() {
    int s, a, x, c;
    cin >> s >> a >> x >> c;
    int q = s + a - x * c;
    if (q < 0) q = 0;  // 倒贴钱
    if (q > a) q = a;  // 班费够用
    cout << q << endl;
    return 0;
}
