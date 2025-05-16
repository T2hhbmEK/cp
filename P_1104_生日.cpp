#include <bits/stdc++.h>
#define maxn 110
using namespace std;

struct Stu {
    string s;
    int y, m, d, id;
    int ymd;
    int key() {
        return y * 10000 + m * 100 + d;
    }
    bool operator<(Stu& o) {
        if (ymd != o.ymd) return ymd < o.ymd;
        return id > o.id;
    }
} a[maxn];
int n;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].s >> a[i].y >> a[i].m >> a[i].d;
        a[i].id = i;
        a[i].ymd = a[i].key();
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) {
        cout << a[i].s << endl;
    }
    return 0;
}
