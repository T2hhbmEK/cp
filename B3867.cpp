#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int ans[N];

int main() {
    int n, d, a;
    cin >> n >> d;
    for (int i = 1; i <= d; i++) {
        cin >> a;
        ans[a] += i;
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}
