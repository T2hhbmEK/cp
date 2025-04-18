#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    // 1*n+2*(n-1)+...+n*1
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i * (n - i + 1);
    }
    cout << sum;
    return 0;
}
