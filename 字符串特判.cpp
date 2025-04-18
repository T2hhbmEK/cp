#include <cstring>
#include <iostream>
using namespace std;

string nizhi(string s, int n, int m) {
    --n, --m;
    for (int i = n, j = m; i < j; ++i, --j) {
        swap(s[i], s[j]);
    }
    return s;
}

int huiwen(string s) {
    for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
        if (s[i] != s[j]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    string s;
    int n, m;
    cin >> s >> n >> m;
    if (huiwen(nizhi(s, n, m))) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}