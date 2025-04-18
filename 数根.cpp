#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main() {
    string s;
    cin >> s;
    int sz = s.length();
    long long shugen = 0;
    for (int i = 0; i < sz; ++i) {
        a[i] = s[i] - '0';
        shugen += a[i];
    }
    long long n = 0;
    for (int i = 0; i < sz; ++i) {
        n *= 10;
        n += a[i];
        n %= shugen;
    }
    if (n % shugen == 0) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}