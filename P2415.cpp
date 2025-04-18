#include <bits/stdc++.h>
using namespace std;
int main() {
    long long ans = 0;
    long long cnt = 1;
    int x;
    while (scanf("%d", &x) != EOF) {
        ans = ans * 2 + cnt * x;
        cnt *= 2;
    }
    cout << ans << endl;
    return 0;
}