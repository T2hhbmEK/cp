#include <bits/stdc++.h>
using namespace std;
int n, x, m;
char s[40];
int c2i(char c) {
    return c > '9' ? c - 'A' + 10 : c - '0';
}
char i2c(int i) {
    return i > 9 ? 'A' + (i - 10) : '0' + i;
}
int main() {
    cin >> n >> s >> m;
    for (int i = 0; i < strlen(s); ++i) {
        x = x * n + c2i(s[i]);
    }
    int i = 32;
    s[i] = 0;
    while (x != 0) {
        s[--i] = i2c(x % m);
        x /= m;
    }
    printf("%s\n", s + i);
    return 0;
}