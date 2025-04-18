#include <bits/stdc++.h>
using namespace std;
int c2i(char c) {
    if (c == 'X') {
        return 10;
    }
    return c - '0';
}
char i2c(int i) {
    if (i == 10) {
        return 'X';
    }
    return '0' + i;
}
int main() {
    int a = 0;
    char s[20];
    scanf("%s", s);
    int cnt = 0;
    for (int i = 0; i < 11; ++i) {
        if (s[i] != '-') {
            a += c2i(s[i]) * (++cnt);
        }
    }
    a %= 11;
    char c = i2c(a);
    if (c == s[12]) {
        cout << "Right\n";
        return 0;
    }
    s[12] = c;
    printf("%s\n", s);
    return 0;
}