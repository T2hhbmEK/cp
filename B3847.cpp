#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, m, s;
    char ch;
    cin >> h >> m >> s >> ch;
    int t = h * 60 * 60 + m * 60 + s;
    if (ch == 'P') {
        t += 12 * 60 * 60;
    }
    cout << t;
    return 0;
}
