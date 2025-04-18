#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ull unsigned long

const int maxn = 1e6 + 10;
const int maxm = maxn << 1;

struct node {
    char op;
    bool val;
    int id;
    // void print() { printf("node(op=%c,val=%d,id=%d)", op, val, id); }
} x[maxn];
int head[maxn];
int nxt[maxm];
int to[maxm];
int cntm, cntn, n, q;

void add_edge(int u, int v) {
    to[++cntm] = v;
    nxt[cntm] = head[u];
    head[u] = cntm;
}

int st[maxn];
int top;

char *s;
ull len;

int read(int &i) {
    int ret = 0;
    if (s[i] == 'x') {
        ++i;
        while (s[i] >= '0' && s[i] <= '9') {
            ret = (ret << 3) + (ret << 1) + (s[i++] & 0xf);
        }
    } else {
        x[++cntn].op = s[i++];
        x[cntn].id = cntn;
        ret = cntn;
    }
    while (s[i] == ' ') ++i;
    return ret;
}

bool used[maxn];

void dfs(int u) {
    if (x[u].op == 'x') {
        used[x[u].id] = true;
    }
    for (int i = head[u]; i; i = nxt[i]) {
        int v = to[i];
        dfs(v);
    }
}

int main() {
    getline(&s, &len, stdin);
    scanf("%d", &n);
    cntn = n;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &x[i].val);
        x[i].op = 'x';
        x[i].id = i;
    }
    for (int i = 0; s[i] != '\n';) {
        int u = read(i);
        if (x[u].op == '!') {
            int a = st[top--];
            x[u].val = !x[a].val;
            // x[u].print(), printf("->"), x[a].print(), putchar('\n');
            add_edge(u, a);
        } else if (x[u].op == '&') {
            int b = st[top--];
            int a = st[top--];
            x[u].val = x[a].val && x[b].val;
            if (x[u].val != (!x[a].val && x[b].val)) {
                // x[u].print(), printf("->"), x[a].print(), putchar('\n');
                add_edge(u, a);
            }
            if (x[u].val != (x[a].val && !x[b].val)) {
                // x[u].print(), printf("->"), x[b].print(), putchar('\n');
                add_edge(u, b);
            }
        } else if (x[u].op == '|') {
            int b = st[top--];
            int a = st[top--];
            x[u].val = x[a].val || x[b].val;
            if (x[u].val != (!x[a].val || x[b].val)) {
                // x[u].print(), printf("->"), x[a].print(), putchar('\n');
                add_edge(u, a);
            }
            if (x[u].val != (x[a].val || !x[b].val)) {
                // x[u].print(), printf("->"), x[b].print(), putchar('\n');
                add_edge(u, b);
            }
        }
        st[++top] = u;
    }
    assert(top == 1);
    int u = st[top];
    dfs(u);
    // for (int i = 1; i <= n; ++i) {
    //     printf("%d ", used[i] ? !x[u].val : x[u].val);
    // }
    // putchar('\n');
    scanf("%d", &q);
    while (q--) {
        int i;
        scanf("%d", &i);
        printf("%d\n", used[i] ? !x[u].val : x[u].val);
    }
    return 0;
}
