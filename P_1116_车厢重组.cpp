#include <bits/stdc++.h>
#define maxn 10010
using namespace std;

int n, a[maxn], ans;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (a[i] > a[j]) {
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}
