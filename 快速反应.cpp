#include<iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int he = n + m;
    if (he % 2 != 0) {
        cout << "odd";
    } else {
        int ji = n * m;
        if (ji % 2 != 0) {
            cout << "odd2";
        } else {
            cout << "even";
        }
    }
    return 0;
}
