#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9 + 7;
const int LINF = 1e18 + 7;
const int N = 1e5 + 7;
int a, b;
int main() {
    cin >> a >> b;
    if (b % a == 0) {
        cout << b / a;
    } else {
        cout << b / a + 1;
    }
    return 0;
}