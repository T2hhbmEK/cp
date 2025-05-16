#include <bits/stdc++.h>
#define maxn 1010
using namespace std;

int n, a[maxn], cnt[maxn];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) {
        a[i] = abs(a[i] - a[i + 1]);
    }
    for (int i = 1; i < n; i++) {
        if (a[i] < n) cnt[a[i]]++;
    }
    for (int i = 1; i < n; i++) {
        if (cnt[i] != 1) {
            cout << "Not jolly" << endl;
            return 0;
        }
    }
    cout << "Jolly" << endl;
    return 0;
}
