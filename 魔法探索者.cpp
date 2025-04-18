#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vii = vector<vi>;
using viii = vector<vii>;
const int inf = 0x3f3f3f3f;
const int n = 7;
const int maxn = n + 5;
char a[maxn][maxn];
int cnt[maxn][maxn];
int dir[5][2] = {{0, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
bool check(int i, int j) {
    for (int k = 0; k < 5; k++) {
        int x = i + dir[k][0];
        int y = j + dir[k][1];
        if (a[x][y] != 'B') {
            return false;
        }
    }
    return true;
}
int count(int &ii, int &jj) {
    int ans = 0;
    memset(cnt, 0, sizeof cnt);
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            if (check(i, j)) {
                for (int k = 0; k < 5; k++) {
                    int x = i + dir[k][0];
                    int y = j + dir[k][1];
                    cnt[x][y]++;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (cnt[i][j] > ans) {
                ii = i;
                jj = j;
                ans = cnt[i][j];
            }
        }
    }
    return ans;
}
void solve() {
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int i, j;
    int c = 0;
    while (count(i, j)) {
        a[i][j] = 'W';
        c++;
    }
    cout << c << endl;
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
