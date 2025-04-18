#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    string s;
    unordered_map<char, int> n, p, n1;
    int r;
    cin >> s;
    for (char c : string("BSC")) cin >> n[c];
    for (char c : string("BSC")) cin >> p[c];
    cin >> r;
    for (char c : s) {
        n1[c] += 1;
    }
    int L = 0, R = 1e13;
    auto chk = [&](int m) {
        int t = 0;
        for (char c : string("BSC")) {
            t += max(0ll, m * n1[c] - n[c]) * p[c];
        }
        return t <= r;
    };
    while (L < R) {
        int M = (L + R + 1) >> 1;
        if (chk(M)) {
            L = M;
        } else {
            R = M - 1;
        }
    }
    cout << L << endl;
    return 0;
}
