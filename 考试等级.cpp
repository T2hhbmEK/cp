#include <iostream>
using namespace std;

int main() {
    int a;
    cin >> a;
    if (a >= 90) {
        cout << "A" << endl;
    } else if (a >= 70) {
        cout << "B" << endl;
    } else if (a >= 60) {
        cout << "C" << endl;
    } else {
        cout << "D" << endl;
    }
    return 0;
}
