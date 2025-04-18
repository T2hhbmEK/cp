#include <bits/stdc++.h>
using namespace std;
string s, t;
int st, ed;
int main() {
    cin >> s >> t >> st >> ed;
    cout << s.substr(0, st) + t + s.substr(ed + 1);
    return 0;
}