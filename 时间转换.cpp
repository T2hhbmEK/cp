#include <bits/stdc++.h>
using namespace std;
int main() {
    int s;
    cin >> s;
    int h = s / 3600;
    int m = s % 3600 / 60;
    int ss = s % 60;
    cout << h << " " << m << " " << ss;
    return 0;
}
