#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        long long a, b;
        string dw1, dh, wh, dw2;
        cin >> a >> dw1 >> dh >> wh >> dw2;
        // 统一转化为 mm 或者 mg
        b = a;
        if (dw1 == "km" || dw1 == "kg") {
            b *= 1e6;
        } else if (dw1 == "m" || dw1 == "g") {
            b *= 1e3;
        }
        // 在转换为新的单位
        if (dw2 == "km" || dw2 == "kg") {
            b /= 1e6;
        } else if (dw2 == "m" || dw2 == "g") {
            b /= 1e3;
        }
        cout << a << " " << dw1 << " = " << b << " " << dw2 << "\n";
    }
    return 0;
}
