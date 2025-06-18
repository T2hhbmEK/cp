#include <iostream>
#include <string>
using namespace std;
int main() {
    int n, cnt = 0, p = '0';
    string s, t;
    cin >> s;
    n = (int)s.size();
    for (int i = 2; i <= n; i++) {
        cin >> t;
        s += t;
    }
    cout << n << ' ';
    for (char ch : s) {
        if (ch != p) {
            cout << cnt << ' ';
            cnt = 0;
        }
        cnt++;
        p = ch;
    }
    cout << cnt << endl;
    return 0;
}
