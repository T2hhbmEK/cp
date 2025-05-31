#include <bits/stdc++.h>
#define maxn 20
using namespace std;

int n, a[maxn];

bool nex() {
    int p = n;
    while (a[p] > a[p + 1]) p--;
    if (p > 0) {
        int q = p + 1;
        while (a[q + 1] > a[p]) q++;
        swap(a[p], a[q]);
    }
    for (int i = p + 1, j = n; i < j; i++, j--) swap(a[i], a[j]);
    return p > 0;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) a[i] = i;
    do {
        for (int i = 1; i <= n; i++) cout << setw(5) << a[i];
        cout << '\n';
    } while (nex());
    return 0;
}
