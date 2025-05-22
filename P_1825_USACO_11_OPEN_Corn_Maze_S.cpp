#include <bits/stdc++.h>
using namespace std;

constexpr int inf = 0x3f3f3f3f;
constexpr int maxn = 310;

struct Vector2D {
    int x, y;
    Vector2D operator+(const Vector2D& o) const {
        return Vector2D{x + o.x, y + o.y};
    }
    bool operator==(const Vector2D& o) const {
        return x == o.x && y == o.y;
    }
} vs, ve;

namespace std {
template <>
struct hash<Vector2D> {
    size_t operator()(const Vector2D& u) const noexcept {
        size_t h1 = hash<int>{}(u.x);
        size_t h2 = hash<int>{}(u.y);
        return h1 ^ (h2 << 1);
    }
};
}  // namespace std

char a[maxn][maxn];
int d[maxn][maxn];
int n, m, ans;
Vector2D dr[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
Vector2D endpoint1[26];
unordered_map<Vector2D, Vector2D> mp;
queue<Vector2D> q;

void init() {
    memset(d, -1, sizeof(d));
}

inline bool chk(Vector2D u) {
    return u.x >= 1 && u.x <= n && u.y >= 1 && u.y <= m && a[u.x][u.y] != '#';
}

int bfs() {
    q.push(vs);
    d[vs.x][vs.y] = 0;
    while (!q.empty()) {
        Vector2D cur = q.front();
        q.pop();
        if (cur == ve) return d[ve.x][ve.y];
        for (int i = 0; i < 4; i++) {
            Vector2D nex = cur + dr[i];
            if (mp.find(nex) != mp.end()) {
                nex = mp[nex];
            }
            if (chk(nex) && d[nex.x][nex.y] == -1) {
                d[nex.x][nex.y] = d[cur.x][cur.y] + 1;
                q.push(nex);
            }
        }
    }
    return -1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    init();
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if (a[i][j] == '@') {
                vs = {i, j};
            } else if (a[i][j] == '=') {
                ve = {i, j};
            } else if (a[i][j] >= 'A' && a[i][j] <= 'Z') {
                if (endpoint1[a[i][j] - 'A'].x) {
                    mp[{i, j}] = endpoint1[a[i][j] - 'A'];
                    mp[endpoint1[a[i][j] - 'A']] = {i, j};
                } else {
                    endpoint1[a[i][j] - 'A'] = {i, j};
                }
            }
        }
    }
    ans = bfs();
    cout << ans << endl;
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         cout << setw(3) << d[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}
