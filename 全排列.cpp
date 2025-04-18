#include <bits/stdc++.h>
using namespace std;
const int NMAX = 15;

int n;
int a[NMAX], vis[NMAX];

void prt() {
    for (int i = 1; i <= n; ++i) {
        cout << a[i] << ' ';
    }
    cout << '\n';
}

void dfs(int k) {
    if (k > n) {
        prt();
        return;
    }
    for (int i = 1; i <= n; ++i) {
        if (vis[i] == 0) {  // 如果 i 还未被选过
            a[k] = i;       // 记录选择
            vis[i] = 1;     // 标记 i 已被选过
            dfs(k + 1);     // 选下一个
            vis[i] = 0;     // 回溯
        }
    }
}

int main() {
    cin >> n;
    dfs(1);
    return 0;
}
