#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    double a, b, c;
    cin >> a >> b >> c;
    double zf = a + b + c;
    double pjf = zf / 3;
    cout << fixed << setprecision(1) << zf << endl;
    cout << fixed << setprecision(1) << pjf << endl;
    return 0;
}
