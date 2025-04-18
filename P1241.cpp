#include <bits/stdc++.h>
using namespace std;
#define N 105
char s[N];
int f[N];
stack<int> st;
int main() {
    scanf("%s", s);
    int n = strlen(s);
    for (int i = 0; i < n; ++i) {
        char x = s[i];
        if (x == '(' || x == '[') {
            st.push(i);
        }
        if (!st.empty()) {
            int j = st.top();
            char y = s[j];
            if (x == ')' && y == '(') {
                f[i] = 1;
                f[j] = 1;
                st.pop();
            } else if (x == ']' && y == '[') {
                f[i] = 1;
                f[j] = 1;
                st.pop();
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (f[i] == 1) {
            printf("%c", s[i]);
        } else {
            char x = s[i];
            if (x == '(' || x == ')') {
                printf("()");
            } else if (x == '[' || x == ']') {
                printf("[]");
            }
        }
    }
    printf("\n");
    return 0;
}