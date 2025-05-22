#include <cstdio>
#include <cstdlib>
#define inf 0x3f3f3f3f
#define maxn 70
int n, cnt[maxn], mi = inf, ma, sum, d;
void dfs(int u, int k, int p) {
    if (u == 0) u = d, k--, p = ma;
    if (k == 0) printf("%d\n", d), exit(0);
    for (int i = p; i >= mi; i--) {
        if (!cnt[i]) continue;
        cnt[i]--;
        if (u >= i) dfs(u - i, k, i);
        cnt[i]++;
        if (u == i || u == d) break;
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 1, x; i <= n; i++) {
        scanf("%d", &x);
        cnt[x]++;
        mi = x < mi ? x : mi;
        ma = x > ma ? x : ma;
        sum += x;
    }
    for (int i = ma, hf = sum >> 1; i <= hf; i++) {
        if (sum % i == 0) d = i, dfs(0, sum / i, ma);
    }
    printf("%d\n", sum);
    return 0;
}
