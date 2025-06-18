#include <bits/stdc++.h>
using namespace std;

int main() {
    double s, sum = 0, cnt = 0, v = 2, decay = 0.98;
    cin >> s;
    while (sum < s) {
        sum += v;
        v *= decay;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}
