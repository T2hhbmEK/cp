#include <iostream>
using namespace std;
int a[205];

int main() {
    int n, s, s_i;
    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        a[i] = s;
    }
    for (int i = 1; i <= n; i++) {
        cin >> s_i;
        for (int j = 1; j <= n; j++) {
            if (a[j] >= s_i) {
                a[j] -= s_i;
                cout << j << " ";
                break;
            }
        }
    }
    return 0;
}
