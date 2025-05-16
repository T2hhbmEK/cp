#include <bits/stdc++.h>
using namespace std;

int n, x;
set<int> s;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        s.insert(x);
    }
    cout << s.size() << endl;
    for (int x : s) {
        cout << x << " ";
    }
    return 0;
}
