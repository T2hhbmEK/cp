#include <bits/stdc++.h>
using namespace std;
string s;
double zf;
int n;
int main() {
    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '-') {
            zf -= 0.3;
        } else if (s[i] == '+') {
            zf += 0.3;
        } else {
            zf += 4 - (s[i] - 'A');
            n += 1;
        }
    }
    cout << fixed << setprecision(2);
    cout << zf / n;
    return 0;
}