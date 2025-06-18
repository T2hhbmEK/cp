#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int main() {
  int n;
  char op = ' ';
  cin >> n;
  while (n--) {
    string a, b;
    cin >> a;
    if (a.size() == 1 && isalpha(a.front())) {
      op = a.front();
      cin >> a;
    }
    cin >> b;
    int x = stoi(a), y = stoi(b);
    ostringstream oss;
    if (op == 'a') {
      oss << x << "+" << y << "=" << x + y;
    } else if (op == 'b') {
      oss << x << "-" << y << "=" << x - y;
    } else if (op == 'c') {
      oss << x << "*" << y << "=" << x * y;
    }
    cout << oss.str() << endl << oss.str().size() << endl;
  }
  return 0;
}
