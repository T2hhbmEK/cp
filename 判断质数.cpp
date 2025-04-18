#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        if (isPrime(n)) {
            cout << "Yes" << '\n';
        } else {
            cout << "No" << '\n';
        }
    }
    return 0;
}
