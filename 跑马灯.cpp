#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, s, m, t;
    cin >> n >> s >> m >> t;
    cout << (m + t / s - 1) % n + 1;
    return 0;
}
