#include <bits/stdc++.h>
using namespace std;
string i2c = "0123456789ABCDEFGHIJ";
int b;
string flip(const string& s) {
    return string(s.rbegin(), s.rend());
}
string i2s(int i) {
    string s;
    while (i) {
        s += i2c[i % b];
        i /= b;
    }
    return s;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> b;
    for (int i = 1; i <= 300; ++i) {
        string s2 = i2s(i * i);
        if (s2 == flip(s2)) {
            string s = i2s(i);
            cout << flip(s) << " ";
            cout << s2 << "\n";
        }
    }
    return 0;
}