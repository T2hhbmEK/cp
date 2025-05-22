#include <iostream>
using namespace std;

int main() {
    int a;
    cin >> a;
    int gewei = a % 10;
    int shiwei = a / 10 % 10;
    int baiwei = a / 100;
    cout << gewei << shiwei << baiwei;
    return 0;
}
