#include <iostream>
using namespace std;
string s, t;
int q, i, j;
int main() {
    cin >> s >> q;
    while (q--) {
        cin >> t;
        i = j = 0;
        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j]) {
                j++;
            }
            i++;
        }
        if (j == t.size()) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}