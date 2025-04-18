#include <bits/stdc++.h>
using namespace std;
#define N 55
char s[N];
int n;
int main() {
    cin >> n;
    scanf("%s", s);
    for (int i = 0; i < strlen(s); ++i) {
        s[i] += n - 26;
        if (s[i] < 'a') {
            s[i] += 26;
        }
    }
    printf("%s\n", s);
    return 0;
}