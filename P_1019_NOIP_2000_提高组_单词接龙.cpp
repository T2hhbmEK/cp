#include <bits/stdc++.h>
#define maxn 45
using namespace std;

int n, vis[maxn], tr[maxn], ans, sum;
string s[maxn];
map<int, int> edges[maxn];
char ch;

int dis(int i, int j) {
    int n1 = s[i].size(), n2 = s[j].size();
    for (int k = 1; k < min(n1, n2); k++) {
        if (s[i].substr(n1 - k) == s[j].substr(0, k)) {
            return k;
        }
    }
    return -1;
}

void dfs(int k) {
    ans = max(ans, sum);
    int i = tr[k - 1];
    for (auto p : edges[i]) {
        int j = p.first, d = p.second;
        if (vis[j] < 2) {
            vis[j]++;
            tr[k] = j;
            sum += s[j].size() - d;
            dfs(k + 1);
            sum -= s[j].size() - d;
            vis[j]--;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> s[i];
    cin >> ch;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int d = dis(i, j);
            if (d > 0) {
                edges[i][j] = d;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (s[i][0] == ch) {
            tr[1] = i, vis[i]++, sum = s[i].size();
            dfs(2);
            vis[i]--;
        }
    }
    cout << ans << endl;
    return 0;
}
