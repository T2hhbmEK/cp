#include <bits/stdc++.h>
using namespace std;
int a[1000005], cnt;
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int top = 1;
    for (int i = 2; i <= n; ++i) {
        if (a[i] != a[top]) {
            a[++top] = a[i];
        }
    }
    for (int i = 2; i < top; i++) {
        if (a[i - 1] > a[i] && a[i + 1] > a[i]) cnt++;
    }
    cout << cnt;
    return 0;
}