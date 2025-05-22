#include <bits/stdc++.h>
using namespace std;

int main() {
    double K;
    cin >> K;
    double C = K - 273.15;
    double F = C * 1.8 + 32;
    if (F > 212) {
        cout << "Temperature is too high!";
    } else {
        cout << fixed << setprecision(2);
        cout << C << " " << F;
    }
    return 0;
}
