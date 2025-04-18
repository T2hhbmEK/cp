#include <bits/stdc++.h>
using namespace std;

int mp[128];

void init() {
    for (int i = 0; i < 10; i++) mp['0' + i] = i;
    for (int i = 10; i < 16; i++) mp['A' + i - 10] = i;
}

void solve() {
    int k;
    string s;
    cin >> k >> s;
    long long a = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        a = a * k + mp[(int)s[i]];
    }
    cout << a << '\n';
}

int main() {
    init();
    int n;
    cin >> n;
    while (n--) {
        solve();
    }
    return 0;
}
