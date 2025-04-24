#include <bits/stdc++.h>
using namespace std;

int T;

int main() {
  cin >> T;
  switch (T) {
    case 1: {
      cout << "I love Luogu!" << endl;
    } break;
    case 2: {
      cout << 2 + 4 << " " << 10 - 2 - 4 << endl;
    } break;
    case 3: {
      cout << 14 / 4 << endl << 14 / 4 * 4 << endl << 14 % 4 << endl;
    } break;
    case 4: {
      cout << fixed << setprecision(3) << 500.0 / 3 << endl;
    } break;
    case 5: {
      cout << (260 + 220) / (12 + 20) << endl;
    } break;
    case 6: {
      cout << sqrt(6 * 6 + 9 * 9) << endl;
    } break;
    case 7: {
      cout << 100 + 10 << endl << 100 + 10 - 20 << endl << 0 << endl;
    } break;
    case 8: {
      double pi = 3.141593, r = 5;
      cout << 2 * pi * r << endl;
      cout << pi * r * r << endl;
      cout << 4.0 / 3 * pi * r * r * r << endl;
    } break;
    case 9: {
      int a = 1;
      a = (a + 1) * 2;
      a = (a + 1) * 2;
      a = (a + 1) * 2;
      cout << a;
    } break;
    case 10: {
      // a+30b=8*30, a+6b=10*6, (a+10b)/10=?
      cout << (8 * 30 + 10 * 6 * 5) / (1 + 5) / 10 << endl;
    } break;
    case 11: {
      cout << 100.0 / (8 - 5) << endl;
    } break;
    case 12: {
      cout << 'M' - 'A' + 1 << endl;
      cout << char('A' + 17) << endl;
    } break;
    case 13: {
      double pi = 3.141593, r1 = 4, r2 = 10;
      int a = cbrt(4.0 / 3 * pi * (r1 * r1 * r1 + r2 * r2 * r2));
      cout << a << endl;
    } break;
    case 14: {
      // x*(10+110-x)=3500
      // x*x-120*x+3500=0
      double b = -120, c = 3500;
      double delta = b * b - 4 * c;
      int x = round((-b - sqrt(delta)) / 2);
      cout << x;
    } break;
    default:
      break;
  }
  return 0;
}
