#include <bits/stdc++.h>
#define maxn 1010
using namespace std;

int n, a[maxn][4], cnt;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 3; j++) {
            cin >> a[i][j];
            a[i][0] += a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (abs(a[i][0] - a[j][0]) > 10) continue;
            if (abs(a[i][1] - a[j][1]) > 5) continue;
            if (abs(a[i][2] - a[j][2]) > 5) continue;
            if (abs(a[i][3] - a[j][3]) > 5) continue;
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
