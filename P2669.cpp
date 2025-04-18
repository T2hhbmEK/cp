#include <bits/stdc++.h>
using namespace std;
#define N 20005
int n, a[N];
int main() {
    cin >> n;
    int i = 1;
    for (int j = 1; i <= n; ++j) {
        for (int k = 0; k < j && i <= n; ++k) {
            a[i] = j;
            a[i] += a[i - 1];
            i++;
        }
    }
    cout << a[n] << endl;
    return 0;
}