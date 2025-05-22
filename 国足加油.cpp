#include<iostream>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a + 3 >= max(b + 1, c + 1)) {
        cout << "YES" << endl;
    } else if (a + 3 >= max(b + 3, c)) {
        cout << "YES" << endl;
    } else if (a + 3 >= max(b, c + 3)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
