#include <cstring>
#include <iostream>
using namespace std;
int t, i, j;
char s[100005], p[100005];
int main() {
    cin >> t;
    while (t--) {
        cin >> s >> p;
        i = j = 0;
        while (p[j]) {
            if (s[i] == p[j]) {
                ++i;
                ++j;
            } else {
                ++j;
            }
        }
        if (s[i] == '\0' && p[j] == '\0') {
            cout << strlen(p) - strlen(s) << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}