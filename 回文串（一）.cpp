#include <bits/stdc++.h>
using namespace std;
string s;
int cnt;
int main() {
    cin >> s;
    for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
        if (s[i] != s[j]) cnt += 1;
    }
    cout << cnt;
    return 0;
}