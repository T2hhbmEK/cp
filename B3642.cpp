#include <bits/stdc++.h>
using namespace std;
#define N 1'000'005
int n, ch[N][2];

void dfs1(int rt) {
    if (rt == 0) {
        return;
    }
    printf("%d ", rt);
    dfs1(ch[rt][0]);
    dfs1(ch[rt][1]);
}

void dfs2(int rt) {
    if (rt == 0) {
        return;
    }
    dfs2(ch[rt][0]);
    printf("%d ", rt);
    dfs2(ch[rt][1]);
}

void dfs3(int rt) {
    if (rt == 0) {
        return;
    }
    dfs3(ch[rt][0]);
    dfs3(ch[rt][1]);
    printf("%d ", rt);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &ch[i][0], &ch[i][1]);
    }
    dfs1(1);
    printf("\n");
    dfs2(1);
    printf("\n");
    dfs3(1);
    printf("\n");
    return 0;
}