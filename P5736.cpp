#include <bits/stdc++.h>
using namespace std;
#define N 105
int n;
int a[N];
bool is_prime(int x) {
    if (x == 1) {
        return false;
    }
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
    }
    for (int i = 1; i <= n; ++i) {
        if (is_prime(a[i])) {
            printf("%d ", a[i]);
        }
    }
    cout << endl;
    return 0;
}