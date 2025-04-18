#include <bits/stdc++.h>
using namespace std;
#define N 150005
typedef long long ll;
int n, ans;
ll t;
priority_queue<ll> q;
struct bld {
    int t1, t2;
    bool operator<(const bld &y) const {
        return t2 < y.t2;
    }
} a[N];
int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int t1, t2;
        scanf("%d%d", &a[i].t1, &a[i].t2);
    }
    sort(a, a + n);
    for (int i = 0; i < n; ++i) {
        t += a[i].t1;
        q.push(a[i].t1);
        ++ans;
        if (t > a[i].t2) {
            t -= q.top();
            q.pop();
            --ans;
        }
    }
    cout << ans << endl;
    return 0;
}