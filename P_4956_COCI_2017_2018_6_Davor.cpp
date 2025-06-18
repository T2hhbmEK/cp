#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    // 52*(x+x+k+x+2k+...+x+6k)
    //=52*(7x+21k)
    //=364(x+3k)
    int x = n / 364, k = 0;
    do {
        x -= 3, k++;
    } while (x > 100);
    cout << x << endl << k << endl;
    return 0;
}
