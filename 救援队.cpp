#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define uint unsigned int
const int inf = 0x3f3f3f3f;
const int maxn = 1e3 + 5;

struct T {
    int id, t1, t2;
} a[maxn];

bool cmp(T a, T b) {
    if (a.t2 != b.t2) return a.t2 < b.t2;
    if (a.t1 != b.t1) return a.t1 < b.t1;
    return a.id < b.id;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int hh, mm;
        char c;
        cin >> hh >> c >> mm;
        a[i].t1 = hh * 60 + mm;
        cin >> hh >> c >> mm;
        a[i].t2 = a[i].t1 + hh * 60 + mm;
        a[i].id = i;
    }
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        cout << a[i].id << endl;
    }
    return 0;
}
