#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;
const double EPS = 1e-9;
const double PI = acos(-1);
const int MOD = 1e9 + 7;
const int NMAX = 1e3 + 5;

int a[NMAX], n;

void print() {
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= n - i; j++) {
            if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
        }
        print();
    }
    return 0;
}
