#include <iostream>
using namespace std;

int fysh(int x) {  // 计算因数和的函数
    int he = 0;    // 和
    for (int i = 2; i < x; ++i) {
        if (x % i == 0) {
            he += i;
        }
    }
    return he;
}

int main() {
    int n;
    cin >> n;
    for (int a = 2; a <= n; ++a) {
        int ahe = fysh(a);    // a的因数和
        int b = ahe;          // b是a的因数和
        if (b > n) continue;  // 如果b大于n，就不用计算了
        int bhe = fysh(b);    // b的因数和
        if (bhe == a) {       // 如果b的因数和等于a
            cout << a << " " << b << endl;
        }
    }
    return 0;
}
