#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
bool not_prime[N] = {1, 1};
int a, b, ans;

int main() {
    cin >> a >> b;
    for (int i = 2; i <= b; i++) {
        if (!not_prime[i] && i >= a) ans++;
        for (int j = i * 2; j <= b; j += i) {
            not_prime[j] = 1;
        }
    }
    cout << ans;
    return 0;
}
