#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;
int a[N];

int main() {
    int n, k, amin = INF, amax = -INF;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        amin = min(amin, a[i]);
        amax = max(amax, a[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] > k) {
            cout << amax << " ";
        } else if (a[i] < k) {
            cout << amin << " ";
        } else {
            cout << k << " ";
        }
    }
    return 0;
}
