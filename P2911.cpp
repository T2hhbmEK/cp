#include <iostream>
#define maxn 128
using namespace std;

int main() {
    static int b[maxn], ans;
    int s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    for (int i = 1; i <= s1; i++) {
        for (int j = 1; j <= s2; j++) {
            for (int k = 1; k <= s3; k++) {
                b[i + j + k]++;
            }
        }
    }
    for (int i = 3; i <= s1 + s2 + s3; i++) {
        if (b[i] > b[ans]) ans = i;
    }
    cout << ans << endl;
    return 0;
}
