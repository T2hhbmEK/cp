#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

struct window {
    int left, right, top, bottom;
    void input() { cin >> left >> right >> top >> bottom; }
    int area() { return (right - left) * (bottom - top); }
    window intersection(window &x) {
        int l = max(left, x.left), r = min(right, x.right);
        int t = max(top, x.top), b = min(bottom, x.bottom);
        if (l >= r || t >= b) return (window){0, 0, 0, 0};
        return (window){l, r, t, b};
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    window a, b;
    a.input();
    b.input();
    cout << a.intersection(b).area() << endl;
    return 0;
}
