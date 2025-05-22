#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a, b;
int s[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 5};
int main() {
    cin >> a >> b;
    int c = a + b, sum = 0;
    while (c != 0) {
        sum += s[c % 10];
        c /= 10;
    }
    cout << sum;
    return 0;
}
