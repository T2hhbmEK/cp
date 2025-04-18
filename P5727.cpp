#include <bits/stdc++.h>
using namespace std;
int n;
stack<int> q;
int main() {
    cin >> n;
    q.push(n);
    while (n > 1) {
        n = n % 2 ? 3 * n + 1 : n / 2;
        q.push(n);
    }
    while (!q.empty()) {
        printf("%d ", q.top());
        q.pop();
    }
    putchar('\n');
    return 0;
}