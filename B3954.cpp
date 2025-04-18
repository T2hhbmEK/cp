#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;

int main() {
    int n, a, ans = 1;
    cin >> n;
    for (int i = 1; i <= n && ans <= N; i++) {
        cin >> a;
        ans *= a;
    }
    if (ans > N) {
        cout << ">" << N;
    } else {
        cout << ans;
    }
    return 0;
}
