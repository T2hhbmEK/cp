#include <bits/stdc++.h>
using namespace std;
int a[26] = {1, 2, 3, 1, 2, 3,
             1, 2, 3, 1, 2, 3, 1, 2, 3,
             1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4},
    ans;
int main() {
    while (true) {
        char c = getchar();
        if (c == ' ') {
            ans++;
        } else if (c >= 'a' && c <= 'z') {
            ans += a[c - 'a'];
        } else {
            break;
        }
    }
    cout << ans << endl;
    return 0;
}