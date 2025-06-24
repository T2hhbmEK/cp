#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int n, op, score;
string name;
unordered_map<string, int> mp;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  while (n--) {
    cin >> op;
    if (op == 1) {
      cin >> name >> score;
      mp[name] = score;
      cout << "OK\n";
    } else if (op == 2) {
      cin >> name;
      if (mp.find(name) != mp.end()) {
        cout << mp[name] << '\n';
      } else {
        cout << "Not found\n";
      }
    } else if (op == 3) {
      cin >> name;
      if (mp.find(name) != mp.end()) {
        mp.erase(mp.find(name));
        cout << "Deleted successfully\n";
      } else {
        cout << "Not found\n";
      }
    } else {
      cout << mp.size() << '\n';
    }
  }
  return 0;
}
