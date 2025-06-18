#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return n >= 2;
}

int main() {
    int L, sum = 0, cnt = 0;
    cin >> L;
    for (int i = 2;; i++) {
        if (isPrime(i)) {
            sum += i;
            if (sum > L) break;
            cout << i << endl;
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
