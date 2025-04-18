#include <bits/stdc++.h>
using namespace std;
typedef struct Student {
    string name;
    int yw;
    int sx;
    int yy;
    int zf;
} Student;
int main() {
    int n;
    Student a;
    a.zf = -1;
    cin >> n;
    for (size_t i = 1; i <= n; ++i) {
        string name;
        int yw, sx, yy, zf;
        cin >> name >> yw >> sx >> yy;
        zf = yw + sx + yy;
        if (zf > a.zf) {
            a = {name, yw, sx, yy, zf};
        }
    }
    printf("%s %d %d %d\n", a.name.c_str(), a.yw, a.sx, a.yy);
    return 0;
}