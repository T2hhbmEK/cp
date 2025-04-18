#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

const int N = 2e5 + 7;
int n, m, head;
struct Node {
    int prev, next;
    int val;
} a[N], s[N];

int erase(Node s[], int& head, int i) {
    if (i == head) {
        head = s[i].next;
        s[head].prev = 0;
        return head;
    } else {
        s[s[i].prev].next = s[i].next;
        s[s[i].next].prev = s[i].prev;
        return s[i].next;
    }
}

void merge(Node a[], Node b[]) {}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].val;
        if (i > 1 && a[i].val == a[i - 1].val) {
            a[i].prev = i - 1;
            a[i - 1].next = i;
        } else {
            s[++m].val = i;
            s[m].prev = m - 1;
            s[m - 1].next = m;
        }
    }
    head = 1;
    while (head != 0) {
        for (int i = head; i != 0; i = s[i].next) {
            cout << s[i].val << " ";
            erase(a, s[i].val, s[i].val);
        }
        cout << endl;
        for (int i = head; i != 0;) {
            if (s[i].val == 0) {
                i = erase(s, head, i);
            }
        }
        for () break;
    }
    return 0;
}
