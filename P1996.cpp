#include <bits/stdc++.h>
using namespace std;
#define N 105
queue<int> q;
int n, m;
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        q.push(i);
    }
    int i = 1;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (i++ == m) {
            printf("%d ", x);
            i = 1;
        } else {
            q.push(x);
        }
    }
    printf("\n");
    return 0;
}