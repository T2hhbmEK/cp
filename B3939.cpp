#include <bits/stdc++.h>
using namespace std;

int flip(int a) {
    int b = 0;
    while (a) {
        b = b * 10 + a % 10;
        a /= 10;
    }
    return b;
}

int is_prime(int a) {
    for (int i = 2; i * i <= a; i++) {
        if (a % i == 0) return false;
    }
    return a > 1;
}

int main() {
    int a, b;
    cin >> a >> b;
    for (int i = a; i <= b; i++) {
        if (is_prime(i) && is_prime(flip(i))) {
            cout << i << '\n';
        }
    }
    return 0;
}
