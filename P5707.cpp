#include <bits/stdc++.h>
using namespace std;
int s, v;
char t[10];
void i2t(int i, char* t) {
    while (i < 0) {
        i += 24 * 60;
    }
    int h = i / 60;
    int m = i % 60;
    for (int i = 1; i >= 0; i--) {
        t[i] = '0' + h % 10;
        h /= 10;
    }
    t[2] = ':';
    for (int i = 4; i >= 3; i--) {
        t[i] = '0' + m % 10;
        m /= 10;
    }
}
int main() {
    cin >> s >> v;
    int i = (s - 1) / v + 1 + 10;
    i = 8 * 60 - i;
    i2t(i, t);
    cout << t << endl;
    return 0;
}