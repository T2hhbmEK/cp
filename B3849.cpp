#include <bits/stdc++.h>
using namespace std;

int a[50];

int main() {
    int n, r;
    cin >> n >> r;
    int k = 0;
    do {
        a[k++] = n % r;
        n /= r;
    } while (n);
    for (int i = k - 1; i >= 0; i--) {
        if (a[i] < 10) {
            cout << a[i];
        } else {
            cout << char('A' + a[i] - 10);
        }
    }
    return 0;
}
