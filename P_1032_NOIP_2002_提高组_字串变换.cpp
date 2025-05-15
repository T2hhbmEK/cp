#include <bits/stdc++.h>
#define sz(s) (int)(s).size()
#define inf 0x3f3f3f3f
#define maxn 10
using namespace std;

struct State {
    string s;
    int k, dr;
};

int n, ans = inf;
string a[2][maxn];
map<string, int> mp[2];
queue<State> q;

void bfs() {
    q.push({a[0][0], 0, 0});
    q.push({a[1][0], 0, 1});
    while (!q.empty()) {
        string s = q.front().s;
        int k = q.front().k;
        int dr = q.front().dr;
        q.pop();
        // cerr << s << " " << k << " " << dr << endl;
        if (k > 5) continue;
        if (mp[dr].find(s) != mp[dr].end()) continue;
        mp[dr][s] = k;
        if (mp[dr ^ 1].find(s) != mp[dr ^ 1].end()) {
            ans = min(ans, mp[dr ^ 1][s] + k);
            break;
        }
        for (int i = 1; i <= n; i++) {
            int pos = s.find(a[dr][i], 0);
            while (pos != string::npos) {
                string t = s.substr(0, pos) + a[dr ^ 1][i] +
                           s.substr(pos + sz(a[dr][i]));
                q.push({t, k + 1, dr});
                pos = s.find(a[dr][i], pos + 1);
            }
        }
    }
}

int main() {
    while (cin >> a[0][n] >> a[1][n]) {
        n++;
    }
    n--;
    bfs();
    if (ans == inf) {
        cout << "NO ANSWER!" << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}
