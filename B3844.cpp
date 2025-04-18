#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int k = i % 26;
        for (int j = 0; j < n; j++) {
            cout << char('A' + k);
            k = (k + 1) % 26;
        }
        cout << '\n';
    }
    return 0;
}
