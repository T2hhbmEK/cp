#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;
const int N = 1e5 + 7;

int n, k;
bool vis[N];
int cnt[N];
queue<int> q;

void bfs() {
    q.push(n);
    vis[n] = 1;
    cnt[n] = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (x == k) {
            return;
        }
        int xx[3] = {
            x - 1,
            x + 1,
            2 * x};
        for (int i = 0; i < 3; ++i) {
            if (xx[i] >= 0 && xx[i] <= 1e5 && vis[xx[i]] == 0) {
                q.push(xx[i]);
                vis[xx[i]] = 1;
                cnt[xx[i]] = cnt[x] + 1;
            }
        }
    }
}

int main() {
    cin >> n >> k;
    bfs();
    cout << cnt[k];
    return 0;
}