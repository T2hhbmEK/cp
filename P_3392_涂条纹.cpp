#include <bits/stdc++.h>
#define maxn 55
#define inf 0x3f3f3f3f
using namespace std;

int n, m, ans = inf;
char a[maxn][maxn];
int preW[maxn], preB[maxn], preR[maxn];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        preW[i] = preW[i - 1] + m;
        preB[i] = preB[i - 1] + m;
        preR[i] = preR[i - 1] + m;
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'W') preW[i]--;
            if (a[i][j] == 'B') preB[i]--;
            if (a[i][j] == 'R') preR[i]--;
        }
    }
    for (int i = 1; i + 2 <= n; i++) {
        for (int j = i + 1; j + 1 <= n; j++) {
            int sum = preW[i] + preB[j] - preB[i] + preR[n] - preR[j];
            ans = min(ans, sum);
        }
    }
    cout << ans << endl;
    return 0;
}
