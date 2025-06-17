#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[3];
    char s[4];
    for (int i = 0; i < 3; i++) cin >> a[i];
    sort(a, a + 3);
    cin >> s;
    for (int i = 0; i < 3; i++) cout << a[s[i] - 'A'] << " ";
    cout << endl;
    return 0;
}
