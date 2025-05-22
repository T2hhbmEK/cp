#include <bits/stdc++.h>
using namespace std;

const int N = 15;
int n;
string a[N][N];
map<char, int> mp;

int s2i(string& s, int x) {
    int a = 0;
    for (char ch : s) {
        a = a * x + mp[ch];
    }
    return a;
}

bool check() {
    for (int i = 1; i < n; i++) {
        int x = s2i(a[i][0], n - 1);
        for (int j = 1; j < n; j++) {
            int y = s2i(a[0][j], n - 1);
            if (x + y != s2i(a[i][j], n - 1)) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        char ch = a[i][0][0];
        int v = 0;
        for (int j = 0; j < n; j++) {
            v += a[i][j].size() - 1;
        }
        mp[ch] = v;
    }
    if (!check()) {
        cout << "ERROR!" << '\n';
        return 0;
    }
    for (int i = 1; i < n; i++) {
        char ch = a[i][0][0];
        cout << a[i][0] << "=" << mp[ch] << " \n"[i == n - 1];
    }
    cout << n - 1;
    return 0;
}
