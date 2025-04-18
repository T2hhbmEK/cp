#include <iostream>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    int sum = 0;
    while (n > 0) {
        if (n >= m) {
            sum += m;
            n -= m;
        } else {
            sum += n;
            n = 0;
        }
        n -= 1;
    }
    cout << sum;
    return 0;
}