#include <bits/stdc++.h>
using namespace std;

int main() {
    // 1*n+2*(n-1)+3*(n-2)+...+n*1
    //  \sum_{i=1}^{n}i*(n+1-i)
    // =((n+1)*\sumi)-\sumi^2
    // =(n+1)*n*(n+1)/2-n*(n+1)*(2*n+1)/6
    // =1/6*n*(n+1)*(3*(n+1)-(2*n+1))
    // =1/6*n*(n+1)*(n+2)
    int n;
    cin >> n;
    cout << n * (n + 1) * (n + 2) / 6;
    return 0;
}
