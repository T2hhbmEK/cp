#include <iostream>
using namespace std;

int main() {
    int n, x, cnt = 0;
    cin >> n >> x;
    for (int i = 1, a; a = i, i <= n; ++i) {
        while (a) {
            if (a % 10 == x) ++cnt;
            a /= 10;
        }
    }
    cout << cnt << endl;
    return 0;
}
