#include <iostream>
using namespace std;

int main() {
    int a;
    cin >> a;
    if (a % 3 == 0 || a % 5 == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
