#include <bits/stdc++.h>
using namespace std;

bool check_ss(string &s) {
    long long a, b, c, d, e;
    sscanf(s.c_str(), "%lld.%lld.%lld.%lld:%lld", &a, &b, &c, &d, &e);
    if (a < 0 || b < 0 || c < 0 || d < 0 || e < 0) return false;
    if (a > 255 || b > 255 || c > 255 || d > 255 || e > 65535) return false;
    stringstream ss;
    ss << a << '.' << b << '.' << c << '.' << d << ':' << e;
    return ss.str() == s;
}

int get_num(string &s, int &i) {
    int a = 0;
    while ('0' <= s[i] && s[i] <= '9') {
        a = a * 10 + s[i] - '0';
        i++;
    }
    return a;
}

void put_num(string &s, int a) {
    if (a == 0) {
        s += '0';
        return;
    }
    string t;
    while (a) {
        t += (char)(a % 10 + '0');
        a /= 10;
    }
    for (int i = 0, j = t.size() - 1; i < j; i++, j--) swap(t[i], t[j]);
    s += t;
}

bool check(string &s) {
    int i = 0;
    string t;
    for (int j = 0; j < 5; i++, j++) {
        int a = get_num(s, i);
        if (a > (j == 4 ? 65535 : 255)) return false;
        put_num(t, a);
        if (j < 4) t += (j == 3 ? ':' : '.');
    }
    return t == s;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    unordered_map<string, int> mp;
    for (int i = 1; i <= n; i++) {
        string op, ad;
        cin >> op >> ad;
        if (!check(ad)) {
            cout << "ERR" << '\n';
            continue;
        }
        if (op[0] == 'S') {
            if (mp.count(ad)) {
                cout << "FAIL" << '\n';
            } else {
                mp[ad] = i;
                cout << "OK" << '\n';
            }
        } else {
            if (mp.count(ad)) {
                cout << mp[ad] << '\n';
            } else {
                cout << "FAIL" << '\n';
            }
        }
    }
    return 0;
}
