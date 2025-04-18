#include <bits/stdc++.h>
using namespace std;
int main() {
    int h, m, s;
    scanf("%d%d%d", &h, &m, &s);
    int t = h * 60 + m + s + s / 30 * 5;
    h = t / 60;
    m = t % 60;
    printf("%02d:%02d", h, m);
    return 0;
}
