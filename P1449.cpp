#include <bits/stdc++.h>
using namespace std;
#define N 55
string s;
int n, st[N], sn;

int main() {
    cin >> s;
    int i = 0;
    while (s[i] != '@') {
        int j = i;
        // if ((s[i] == '-' && s[i + 1] >= '0' && s[i + 1] <= '9') || (s[i] >= '0' && s[i] <= '9')) {
        if (s[i] >= '0' && s[i] <= '9') {
            while (s[j] != '.') {
                ++j;
            }
            st[sn++] = stoi(s.substr(i, j - i));
            i = j + 1;
        } else {
            int y = st[--sn];
            int x = st[--sn];
            int z;
            if (s[i] == '+') {
                z = x + y;
            } else if (s[i] == '-') {
                z = x - y;
            } else if (s[i] == '*') {
                z = x * y;
            } else if (s[i] == '/') {
                z = x / y;
            }
            st[sn++] = z;
            ++i;
        }
    }
    cout << st[sn - 1] << endl;
    return 0;
}