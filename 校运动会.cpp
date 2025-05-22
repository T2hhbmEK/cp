#include <iostream>
using namespace std;
int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    while (n--) {
        c++;
        int m = 31;  // 这个月的天数
        if (b == 2) {
            if (a % 400 == 0 || a % 100 != 0 && a % 4 == 0) {
                m = 29;
            } else {
                m = 28;
            }
        } else if (b == 4 || b == 6 || b == 9 || b == 11) {
            m = 30;
        }
        if (c > m) {
            b++;
            c = 1;
        }
        if (b > 12) {
            a++;
            b = 1;
        }
    }
    cout << a << " " << b << " " << c;
    return 0;
}
