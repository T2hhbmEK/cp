#include <algorithm>
#include <iostream>
using namespace std;
const int N = 2e5 + 5;

int n, b, a[N], cnt[N];
int main() {
    cin >> n >> b;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] >= 3 * b) {
            a[i] -= 3 * b;
        } else if (a[i] >= 2 * b) {
            a[i] -= 2 * b;
        } else if (a[i] >= b) {
            a[i] -= b;
        }
        ans += a[i];
    }

    cout << ans << endl;
    return 0;
}
