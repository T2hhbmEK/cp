#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

int n;
unordered_map<string, int> mp;

bool check(string& ad) {
    char s[32], fmt[] = "%d.%d.%d.%d:%d";
    int a, b, c, d, e;
    sscanf(ad.c_str(), fmt, &a, &b, &c, &d, &e);
    sprintf(s, fmt, a & 0xFF, b & 0xFF, c & 0xFF, d & 0xFF, e & 0xFFFF);
    return ad == s;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string op, ad;
        cin >> op >> ad;
        if (!check(ad)) {
            cout << "ERR" << endl;
            continue;
        }
        if (op == "Server") {
            if (mp.find(ad) != mp.end()) {
                cout << "FAIL" << endl;
            } else {
                mp[ad] = i;
                cout << "OK" << endl;
            }
        } else if (op == "Client") {
            if (mp.find(ad) != mp.end()) {
                cout << mp[ad] << endl;
            } else {
                cout << "FAIL" << endl;
            }
        }
    }
    return 0;
}
