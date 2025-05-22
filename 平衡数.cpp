#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define uint unsigned int
const int inf = 0x3f3f3f3f;
const int maxn = 1e6 + 5;
int cnt[3];

int main() {
#ifndef ONLINE_JUDGE
    freopen("balance.in", "r", stdin);
    freopen("balance.out", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        cnt[s[i] - '0'] += 1;
    }
    int m = n / 3;
    for (int i = 0; i < n; ++i) {
        int x = s[i] - '0';
        if (cnt[x] > m) {
            for (int j = 0; j < x; ++j) {
                if (cnt[j] < m) {
                    s[i] = j + '0';
                    cnt[x] -= 1;
                    cnt[j] += 1;
                    break;
                }
            }
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        int x = s[i] - '0';
        if (cnt[x] > m) {
            for (int j = 2; j > x; --j) {
                if (cnt[j] < m) {
                    s[i] = j + '0';
                    cnt[x] -= 1;
                    cnt[j] += 1;
                    break;
                }
            }
        }
    }
    cout << s << endl;
    return 0;
}
