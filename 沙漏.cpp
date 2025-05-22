#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int l = i;          // left
            int r = n + 1 - i;  // right
            if (l > r) {
                swap(l, r);
            }
            if (j >= l && j <= r) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
