#include <bits/stdc++.h>
using namespace std;

const int N = 25;
int n, a[N][N];
int main() {
    cin >> n;
    int i = 0, j = n / 2, k = 1;
    a[i][j] = k++;
    while (k <= n * n) {
        int i1 = (i - 1 + n) % n;
        int j1 = (j + 1) % n;
        if (a[i1][j1] != 0) {
            i1 = (i + 1) % n;
            j1 = j;
        }
        i = i1, j = j1;
        a[i][j] = k++;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " \n"[j == n - 1];
        }
    }
    return 0;
}
