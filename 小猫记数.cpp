#include <bits/stdc++.h>
using namespace std;

void f() {
    int a;
    cin >> a;
    if (a == -1) return;
    f();
    cout << a << " ";
}

int main() {
    f();
    return 0;
}
