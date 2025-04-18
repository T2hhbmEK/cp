#include <bits/stdc++.h>
using namespace std;
#define N 1005
int n, t[N], idx[N];
typedef long long ll;
ll s, ans;
bool cmp(int i, int j) {
    return t[i] < t[j];
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        idx[i] = i;
        scanf("%d", &t[i]);
    }
    sort(idx + 1, idx + n + 1, cmp);
    for (int i = 1; i <= n; ++i) {
        printf("%d ", idx[i]);
        ans += s;
        s += t[idx[i]];
    }
    printf("\n");
    printf("%.2lf\n", static_cast<double>(ans) / n);
    return 0;
}