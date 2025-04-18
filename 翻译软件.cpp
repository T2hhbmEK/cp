#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int m, n;
    cin >> m >> n;
    queue<int> q;
    bitset<1001> vis;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        if (vis[a]) continue;
        q.push(a);
        vis[a] = 1;
        cnt++;
        if (q.size() > m) {
            vis[q.front()] = 0;
            q.pop();    
        }
    }
    cout << cnt << endl;
    return 0;
}
