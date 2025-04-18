#include <bits/stdc++.h>
using namespace std;

int a[1005];

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int L = 1, R = L + k; R <= 1000; L++, R++) {
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] >= L && a[i] <= R) {
                sum += a[i];
            }
        }
        ans = max(ans, sum);
    }
    cout << ans;
    return 0;
}
