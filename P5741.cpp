#include <bits/stdc++.h>
using namespace std;
typedef struct Student {
    string name;
    int yw;
    int sx;
    int yy;
    int zf;
} Student;
bool cmp(Student a, Student b) {
    return a.zf < b.zf;
}
bool near(Student a, Student b) {
    return abs(a.yw - b.yw) <= 5 && abs(a.sx - b.sx) <= 5 &&
           abs(a.yy - b.yy) <= 5 && abs(a.zf - b.zf) <= 10;
}
int main() {
    int n;
    vector<Student> a;
    cin >> n;
    for (size_t i = 1; i <= n; ++i) {
        string name;
        int yw, sx, yy, zf;
        cin >> name >> yw >> sx >> yy;
        zf = yw + sx + yy;
        a.push_back({name, yw, sx, yy, zf});
    }
    for (size_t i = 0; i < n - 1; ++i) {
        Student x = a[i];
        for (size_t j = i + 1; j < n; ++j) {
            Student y = a[j];
            if (near(x, y)) {
                if (x.name > y.name) {
                    swap(x, y);
                }
                printf("%s %s\n", x.name.c_str(), y.name.c_str());
            }
        }
    }
    return 0;
}