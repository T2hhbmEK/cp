#include <bits/stdc++.h>
using namespace std;
long long a, c, num[200005], maxx, sum, real1;
int main() {
    cin >> a >> c;
    for (long long i = 1; i <= a; i++) {
        cin >> num[i];
        if (maxx < num[i]) {
            maxx = num[i];
        }
        if (num[i] != 0) real1++;
        sum += num[i];
    }

    long long to = min(a, (real1 + c));
    for (long long i = to; i >= 1; i--) {  // 枚举每个人分的糖果种类即糖果数
        if (i - sum % i <= c && (sum + c) / i >= maxx) {
            cout << (sum + c) / i << endl;
            cout << i;
            break;
        } else if (sum % i == 0 && sum / i >= maxx) {
            cout << sum / i << endl;
            cout << i;
            break;
        }
    }
    return 0;
}
