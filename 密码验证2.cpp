#include <bits/stdc++.h>
using namespace std;
string na, pw;
string m, d;
int main() {
    cin >> na >> m >> d;
    cin >> pw;
    if (m.size() == 1) na += "0";
    na += m;
    if (d.size() == 1) na += "0";
    na += d;
    cout << na << endl;
    if (na == pw) {
        cout << "yes";
    } else {
        cout << "no";
    }
    return 0;
}