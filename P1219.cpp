#include <bits/stdc++.h>
using namespace std;
#define N 15
int ans[N], dl[N * 2], dr[N * 2], row[N], col[N], n, cnt;

void dfs(int i) {
    if (i > n) {
        if (++cnt > 3) {
            return;
        }
        for(int j = 1; j <= n; ++j) {
            printf("%d ", ans[j]);
        }
        printf("\n");
        return;
    }
    for (int j = 1; j <= n; ++j) {
        if (dl[j - i + n] || dr[i + j] || row[i] || col[j]) {
            continue;
        }
        ans[i] = j;
        dl[j - i + n] = dr[i + j] = row[i] = col[j] = 1;
        dfs(i + 1);
        dl[j - i + n] = dr[i + j] = row[i] = col[j] = 0;
        ans[i] = 0;
    }
}

int main() {
    scanf("%d", &n);
    dfs(1);
    printf("%d\n", cnt);
    return 0;
}