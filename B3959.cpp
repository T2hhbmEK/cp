#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int a[N];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    int k = 1;
    for (int i = 1; i <= n; i++) {
        if (a[i] >= k) k++;
    }
    cout << k - 1;
    return 0;
}