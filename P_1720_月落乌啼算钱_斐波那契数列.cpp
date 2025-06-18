#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    cout << fixed << setprecision(2);
    cout << (pow((1 + sqrt(5)) / 2, n) - pow((1 - sqrt(5)) / 2, n)) / sqrt(5)
         << endl;
    return 0;
}
