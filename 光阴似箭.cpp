#include <iostream>
using namespace std;
int main() {
    int a, b, s;
    cin >> a >> b >> s;
    b += s;
    a += b / 60;
    b %= 60;
    a %= 24;
    cout << a << " " << b;
    return 0;
}