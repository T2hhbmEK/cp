#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define uint unsigned int
const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 5;

struct shop {
    int id;
    double price;
} a[maxn];

bool cmp(shop a, shop b) {
    if (a.price != b.price) return a.price < b.price;
    return a.id < b.id;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].price;
        a[i].id = i;
    }
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= m; i++) {
        cout << a[i].id << endl;
    }
    return 0;
}
