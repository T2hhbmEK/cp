#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;

int main() {
    int n, a, mi=inf;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a, mi = min(mi, a);
    cout << mi << endl;
    return 0;
}
