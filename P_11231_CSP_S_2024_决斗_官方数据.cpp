#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int i = 0, j = 1;
    while (i < n && j < n) {
        while (i < n && a[i] == 0) i++;
        if (i >= n) break;
        if (j <= i) j = i + 1;
        while (j < n && (a[j] == 0 || a[j] == a[i])) j++;
        if (j >= n) break;
        a[i] = 0;
        j++;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        // cerr << a[i] << " ";
        if (a[i] > 0) ans++;
    }
    // cerr << endl;
    cout << ans << endl;
    return 0;
}
