#include <bits/stdc++.h>
using namespace std;
#define N 1005
uint m, n, x, ans;
bool c[N];
queue<uint> q;
int main() {
    cin >> m >> n;
    for (size_t i = 1; i <= n; ++i) {
        scanf("%u", &x);
        if (!c[x]) {
            ans++;
            q.push(x);
            c[x] = true;
            if (q.size() > m) {
                c[q.front()] = false;
                q.pop();
            }
        }
    }
    cout << ans << endl;
    return 0;
}