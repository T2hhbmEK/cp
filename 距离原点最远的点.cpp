#include <bits/stdc++.h>
using namespace std;
string moves;
int x, tj;
int main() {
    cin >> moves;
    for (int i = 0; i < moves.size(); ++i) {
        if (moves[i] == 'L') {
            x -= 1;
        } else if (moves[i] == 'R') {
            x += 1;
        } else {
            // _
            tj += 1;
        }
    }
    cout << abs(x) + tj;
    return 0;
}