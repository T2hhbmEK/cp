#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[10], h, cnt = 0;
    for (int i = 0; i < 10; i++) cin >> a[i];
    cin >> h, h += 30;
    for (int i = 0; i < 10; i++) cnt += (h >= a[i]);
    cout << cnt << endl;
    return 0;
}
