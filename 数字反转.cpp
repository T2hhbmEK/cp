#include <iostream>
using namespace std;
int main() {
    long long n, s = 0;
    cin >> n;
    while (n) {
        s *= 10;
        s += n % 10;
        n /= 10;
    }
    cout << s;
    return 0;
}
