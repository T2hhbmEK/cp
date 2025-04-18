#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 1; i <= n; ++i) {
        int li;
        scanf("%d", &li);
        q.push(li);
    }
    long long ans = 0;
    while (q.size() > 1) {
        int a = q.top();
        q.pop();
        int b = q.top();
        q.pop();
        a += b;
        ans += a;
        q.push(a);
    }
    cout << ans << endl;
    return 0;
}