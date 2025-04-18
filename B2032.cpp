#include <bits/stdc++.h>
using namespace std;
#define N 1005
int a1, a2, n;
int main() {
    cin >> a1 >> a2 >> n;
    int d = a2 - a1;
    int an = a1 + d * (n - 1);
    cout << an << endl;
    return 0;
}