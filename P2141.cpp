#include <algorithm>
#include <iostream>
using namespace std;

constexpr int maxn = 128;
int n, a[maxn], ans;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    for (int k = 1; k <= n; k++) {
        int i = 1, j = k - 1;
        while (i < j) {
            if (a[i] + a[j] > a[k]) {
                j--;
            } else if (a[i] + a[j] < a[k]) {
                i++;
            } else {
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
