#include <bits/stdc++.h>
#define maxn 50010
using namespace std;

struct Vector3 {
    int x, y, z;
    bool operator<(Vector3 o) {
        return z < o.z;
    }
    friend istream& operator>>(istream& is, Vector3& v) {
        is >> v.x >> v.y >> v.z;
        return is;
    }
    friend ostream& operator<<(ostream& os, Vector3& v) {
        os << v.x << " " << v.y << " " << v.z;
        return os;
    }
    Vector3 operator-(Vector3 o) {
        Vector3 r{x - o.x, y - o.y, z - o.z};
        return r;
    }
    double rad() {
        return sqrt(x * x + y * y + z * z);
    }
} a[maxn];
int n;
double ans;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    for (int i = 2; i <= n; i++) {
        ans += (a[i] - a[i - 1]).rad();
    }
    cout << fixed << setprecision(3) << ans << endl;
    return 0;
}
