#include <iostream>
using namespace std;
void nian(int x) {
    if (x == 0) {
        cout << "ling ";
    } else if (x == 1) {
        cout << "yi ";
    } else if (x == 2) {
        cout << "er ";
    } else if (x == 3) {
        cout << "san ";
    } else if (x == 4) {
        cout << "si ";
    } else if (x == 5) {
        cout << "wu ";
    } else if (x == 6) {
        cout << "liu ";
    } else if (x == 7) {
        cout << "qi ";
    } else if (x == 8) {
        cout << "ba ";
    } else if (x == 9) {
        cout << "jiu ";
    } else if (x == 10) {
        cout << "shi ";
    } else if (x <= 19){
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
