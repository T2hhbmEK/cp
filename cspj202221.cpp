#include <iostream>
using namespace std;
int main() {
    unsigned short x, y;
    cin >> x >> y;
    x = (x | x << 2) & 0x33;
    cout << x << endl;
    x = (x | x << 1) & 0x55;
    cout << x << endl;
    y = (y | y << 2) & 0x33;
    cout << y << endl;
    y = (y | y << 1) & 0x55;
    cout << y << endl;
    cout << x << endl;
    cout << (y << 1) << endl;
    cout << (x | y << 1) << endl;
    unsigned short z = x | y << 1;
    cout << z << endl;
    return 0;
}
