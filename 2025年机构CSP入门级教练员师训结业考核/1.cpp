#include <bits/stdc++.h>
#define maxn 10005
using namespace std;

int m, n;
int a[maxn];
int ans;
int main() {
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] > m) {
            ans++;
        } else {
            m -= a[i];
        }
    }
    cout << ans;
    return 0;
}
