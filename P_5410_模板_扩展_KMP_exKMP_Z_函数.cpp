#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 4E7 + 10;
char a[N], b[N];
int z[N];
void prt(int* z, int n) {
    for (int i = 0; i < n; ++i) {
        cout << z[i] << " ";
    }
    cout << "\n";
}
ll f(int* a, int n) {
    ll r = 0;
    for (ll i = 0; i < n; ++i) {
        r = r ^ ((i + 1) * (a[i] + 1));
    }
    return r;
}
void zf(char* a, int* z, int n) {
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r && z[i - l] < r - i + 1) {
            z[i] = z[i - l];
        } else {
            z[i] = max(r - i + 1, 0);
            while (i + z[i] < n && a[z[i]] == a[i + z[i]]) ++z[i];
        }
        if (z[i] > r - i + 1) {
            l = i;
            r = i + z[i] - 1;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> a >> b;
    int n1 = strlen(a);
    int n2 = strlen(b);
    b[n2] = '#';
    strcat(b, a);
    zf(b, z, n1 + n2 + 1);
    z[0] = n2;
    cout << f(z, n2) << "\n";
    int* p = z + n2 + 1;
    cout << f(p, n1) << "\n";
    // prt(z, n2);
    // prt(p, n1);
    // prt(p, n1 + n2 + 1);
    return 0;
}