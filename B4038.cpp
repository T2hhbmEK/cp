#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
int a[N];

bool solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    for (int i = 1; i < n; i++) {
        if (a[i] * 2 == a[n]) return true;
    }
    return false;
}
bool solve1() {
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    int pre = 0;
    for (int i = 1; i < n; i++) {
        pre += a[i];
        if (pre * 2 == sum) return true;
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        if (solve()) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}
