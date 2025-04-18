#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double yw = 89.5;
    double sx = 99.5;
    double yy = 78.5;
    double zf = yw + sx + yy;
    double pjf = zf / 3;
    cout << fixed << setprecision(1) << pjf;
    return 0;
}
