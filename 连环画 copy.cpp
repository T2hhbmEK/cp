#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;
const int N = 1e6 + 7;

queue<int> q;
stack<int> s;
int n;

void show() {
    cout << "s: ";
    stack<int> ss;
    while (!s.empty()) {
        ss.push(s.top());
        s.pop();
    }
    while (!ss.empty()) {
        cout << ss.top() << " ";
        s.push(ss.top());
        ss.pop();
    }
    cout << endl;
    cout << "q: ";
    int sz = q.size();
    while (sz--) {
        cout << q.front() << " ";
        q.push(q.front());
        q.pop();
    }
    cout << endl;
}

int main() {
    cin >> n;
    while (n--) {
        int a;
        cin >> a;
        q.push(a);
    }
    int i = 0;
    while (!q.empty()) {
        i += 1;
        int a = q.front();
        if (a == i) {
            s.push(q.front());
            q.pop();
            printf("read %d\n", i);
            show();
        } else {
            if (s.size() < 2) {
                printf("read %d failed\n", i);
                show();
                cout << i - 1;
                return 0;
            } else {
                if (q.front() <= i) {
                    q.pop();
                } else {
                    s.pop();
                }
                if (q.front() <= i) {
                    q.pop();
                } else {
                    s.pop();
                }
                s.push(i);
                printf("read %d\n", i);
                show();
            }
        }
    }
    cout << i;
    return 0;
}