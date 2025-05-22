#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;
const double EPS = 1e-9;
const double PI = acos(-1);
const int MOD = 1e9 + 7;
const int NMAX = 1e2 + 5;

int n, a[NMAX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    n = 20;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == 1 || a[i] == 2) {
            a[i] += 13;
        }
    }
    // insertion sort
    for (int i = 2; i <= n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 1 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
    // output
    for (int i = 1; i <= n; i++) {
        if (a[i] == 14 || a[i] == 15) {
            a[i] -= 13;
        }
        cout << a[i] << " ";
    }
    return 0;
}
