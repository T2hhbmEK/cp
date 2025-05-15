#include <bits/stdc++.h>
#define maxn 15
using namespace std;

int n;
int a[maxn];
int vis[maxn];  // visited 标记是否访问

void dfs(int k) {
    if (k > n) {
        for (int i = 1; i <= n; ++i) {
            cout << a[i] << " \n"[i == n];
        }
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
