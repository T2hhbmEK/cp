#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 60;
int n, f[N] = {1, 1, 2};

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for (int i = 3; i <= n; i++) {
		f[i] = f[i - 1] + f[i - 2] + f[i - 3];
	}
	cout << f[n];
	return 0;
}
