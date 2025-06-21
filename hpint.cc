#include "hpint.h"

#include <bits/stdc++.h>

#include <cassert>
#include <iostream>
#include <random>
#include <utility>

using namespace std;
using namespace hpint;
using ll = long long;

int main() {
  random_device rd;
  mt19937 gen(rd());
  constexpr int n = 1000;

  for (int i = 0; i < n; i++) {
    uniform_int_distribution<ll> dist(0LL, (ll)1e18);
    ll a = dist(gen), b = dist(gen);
    HPInt x = a, y = b;
    cout << x << "+" << y << "=" << x + y << endl;
    assert(x + y == a + b);
  }
  cout << endl;

  for (int i = 0; i < n; i++) {
    uniform_int_distribution<ll> dist(0LL, (ll)1e18);
    ll a = dist(gen), b = dist(gen);
    if (a < b) swap(a, b);
    HPInt x = a, y = b;
    cout << x << "-" << y << "=" << x - y << endl;
    assert(x - y == a - b);
  }
  cout << endl;

  for (int i = 0; i < n; i++) {
    uniform_int_distribution<ll> dist(0LL, (ll)1e9);
    ll a = dist(gen), b = dist(gen);
    HPInt x = a, y = b;
    cout << x << "*" << y << "=" << x * y << endl;
    assert(x * y == a * b);
  }
  cout << endl;

  for (int i = 0; i < n; i++) {
    uniform_int_distribution<ll> dist1(0LL, (ll)1e18);
    uniform_int_distribution<ll> dist2(0LL, (ll)1e4);
    ll a = dist1(gen), b = dist2(gen), y = b;
    HPInt x = a;
    cout << x << "/" << y << "=" << x / y << endl;
    assert(x / y == a / b);
  }
  cout << endl;

  for (int i = 0; i < n; i++) {
    uniform_int_distribution<ll> dist(0LL, (ll)1e18);
    ll a = dist(gen), b = dist(gen);
    HPInt x = a, y = b;
#define TEST_CMP(op)                                          \
  cout << x << " " #op " " << y << " = " << (x op y) << endl; \
  assert((x op y) == (a op b));
    TEST_CMP(<) TEST_CMP(>) TEST_CMP(==);
    TEST_CMP(<=) TEST_CMP(>=) TEST_CMP(!=);
  }
  cout << endl;

  return 0;
}
