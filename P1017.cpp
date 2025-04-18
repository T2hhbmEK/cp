#include <bits/stdc++.h>
using namespace std;
int n, R;
stack<int> q;
char i2c(int i) {
    return i > 9 ? 'A' + (i - 10) : '0' + i;
}
int main() {
    cin >> n >> R;
    printf("%d=", n);
    R = -R;
    while (n != 0) {
        int x = n % R;
        if (x < 0) {
            x += R;
        }
        q.push(x);
        n = (n - x) / -R;
    }
    while (!q.empty()) {
        putchar(i2c(q.top()));
        q.pop();
    }
    printf("(base-%d)\n", R);
    return 0;
}