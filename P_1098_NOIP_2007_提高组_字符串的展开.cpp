#include <bits/stdc++.h>
using namespace std;

int p1, p2, p3;
string s;

void _putchar(char ch) {
    for (int i = 1; i <= p2; i++) {
        if (p1 == 1) {
            putchar(tolower(ch));
        } else if (p1 == 2) {
            putchar(toupper(ch));
        } else if (p1 == 3) {
            putchar('*');
        }
    }
}

int main() {
    cin >> p1 >> p2 >> p3;
    cin >> s;
    for (int i = 0; s[i]; i++) {
        if (s[i] == '-' &&
            (islower(s[i - 1]) && islower(s[i + 1]) ||
             isdigit(s[i - 1]) && isdigit(s[i + 1])) &&
            s[i - 1] < s[i + 1]) {
            if (p3 == 1) {
                for (char j = s[i - 1] + 1; j < s[i + 1]; j++) {
                    _putchar(j);
                }
            } else if (p3 == 2) {
                for (char j = s[i + 1] - 1; j > s[i - 1]; j--) {
                    _putchar(j);
                }
            }
        } else {
            putchar(s[i]);
        }
    }
    putchar('\n');
    return 0;
}
