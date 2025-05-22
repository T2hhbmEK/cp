#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, m;  // 小时 和 分钟
    cin >> h >> m;
    int t = h * 60 + m;  // h时m分过去的分钟数
    cout << t << endl;
    if (t > 7 * 60) {  // 7点整过去的分钟数 7*60
        cout << h时m分的分钟数 - 7点的分钟数 ;    // 7点之后
    } else {
        cout << ? ;  // 7点之前
    }
    return 0;
}
