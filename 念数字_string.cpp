#include <iostream>
using namespace std;
void nian(int x) {
    string digits[] = {"ling ", "yi ", "er ", "san ", "si ", "wu ",
                       "liu ",  "qi ", "ba ", "jiu ", "shi "};
    if (x <= 10) {
        cout << digits[x];
    } else if (x <= 19) {
        nian(10);
        nian(x % 10);
    } else if (x % 10 == 0) {
        nian(x / 10);
        nian(10);
    } else {
        nian(x / 10);
        nian(10);
        nian(x % 10);
    }
}
int main() {
    int n;
    cin >> n;
    nian(n);
    return 0;
}
