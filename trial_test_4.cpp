#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 1000005
vector<int> primes = {2, 3, 4, 5, 7, 9, 11, 13, 17, 19, 23, 25, 29, 31, 37, 41, 43, 47, 49, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 121, 127, 131, 137, 139, 149, 151, 157, 163, 167, 169, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 289, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 361, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 529, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 841, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 961, 967, 971, 977, 983, 991, 997};
int n, a[N], x, ans, dp[N];
vector<int> g[200];
vector<int> fac[N];
bool is_prime(int x) {
    for (int i = 2; i * i < x; ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}
bool huzhi(int i, int j) {
    for (int k = 0; k < primes.size(); ++k) {
        if (a[i] % primes[k] == 0 && a[j] % primes[k] == 0) {
            return false;
        }
    }
    return true;
}
int dfs(int i) {
    if (dp[i] >= 0) {
        return dp[i];
    }
    int ret = 0;
    for (int f_j = 0; f_j < fac[i].size(); ++f_j) {
        int p_i = fac[i][f_j];
        for (int k = 0; k < g[p_i].size(); ++k) {
            int j = g[p_i][k];
            if (j > i) {
                // i & j have common factor p_i
                // cout << a[i] << " & " << a[j] << ": " << primes[p_i] << endl;
                ret = max(ret, 1 + dfs(j));
            }
        }
    }
    dp[i] = ret;
    return ret;
}
int main() {
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        for (int j = 0; j < primes.size(); ++j) {
            int p = primes[j];
            if (a[i] % p == 0) {
                g[j].push_back(i);    // prime i is factor of a[i]
                fac[i].push_back(j);  // a[i] has factor j
            }
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        dfs(i);
        if (dfs(i) > 0) {
            ans = max(ans, 1 + dfs(i));
        }
    }
    cout << ans << endl;
    return 0;
}