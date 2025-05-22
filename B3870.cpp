#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define uint unsigned int
int main() {
  ull n;
  cin >> n;
  do {
    uint a = (n & 0x7F);
    if (n >>= 7) a |= 0x80;
    printf("%02X ", a);
  } while (n);
  return 0;
}