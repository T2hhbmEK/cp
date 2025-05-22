#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, i;
    cin >> n >> i;
    for (int k = 1;; k++) {
        int a = n * k + i, flag = 1;
        for (int j = n - 1; j >= 1; j--) {
            if (a % (n - 1) != 0) {
                flag = 0;
                break;
            }
            a = a / (n - 1) * n + i;
        }
        if (flag) {
            cout << a;
            break;
        }
    }
    return 0;
}
