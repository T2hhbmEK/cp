#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, b, c;
    cin >> n >> b >> c;
    int gz = n, pz = n, sum = n;  // gz：盖子数 pz：瓶子数
    while (gz >= b || pz >= c) {
        if (gz >= b) gz -= b, sum++, gz++, pz++;
        if (pz >= c) pz -= c, sum++, pz++, gz++;
    }
    cout << sum;
    return 0;
}
