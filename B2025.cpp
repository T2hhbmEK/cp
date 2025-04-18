#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
const int n = 5;

int main() {
    fastio;
    for (int i = 0; i < n; i++) {
        int L = abs((n - 1) / 2 - i);
        int R = n - 1 - L;
        for (int j = 0; j < L; j++) {
            cout << " ";
        }
        for (int j = L; j <= R; j++) {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}