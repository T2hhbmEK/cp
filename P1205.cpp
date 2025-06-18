#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using vs = vector<string>;
void prt(vs a) {
    for (string &s : a) {
        cout << s << endl;
    }
}
bool eq(vs a, vs b) {
    if (a.size() != b.size()) return false;
    for (int i = 0; i < (int)a.size(); i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}
vs rot90(vs src) {
    int n = (int)src.size();
    vs ret = src;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ret[j][n - 1 - i] = src[i][j];
        }
    }
    return ret;
}
vs rot180(vs src) {
    return rot90(rot90(src));
}
vs rot270(vs src) {
    return rot90(rot180(src));
}
vs hflip(vs src) {
    vs ret = src;
    for (int i = 0; i < (int)ret.size(); i++) {
        reverse(ret[i].begin(), ret[i].end());
    }
    return ret;
}
int main() {
    int n;
    cin >> n;
    vs src(n), dst(n);
    for (string &s : src) cin >> s;
    for (string &s : dst) cin >> s;
    if (eq(dst, rot90(src))) {
        cout << 1 << endl;
    } else if (eq(dst, rot180(src))) {
        cout << 2 << endl;
    } else if (eq(dst, rot270(src))) {
        cout << 3 << endl;
    } else if (eq(dst, hflip(src))) {
        cout << 4 << endl;
    } else if (eq(dst, rot90(hflip(src))) || eq(dst, rot180(hflip(src))) ||
               eq(dst, rot270(hflip(src)))) {
        cout << 5 << endl;
    } else if (eq(dst, src)) {
        cout << 6 << endl;
    } else {
        cout << 7 << endl;
    }
    return 0;
}
