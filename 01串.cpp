#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    int n;
    cin >> str >> n;
    for (int i = 1; i <= n; i++) {
        int len = str.length();
        string str1 = "";
        for (int j = 0; j < len; j++) {
            if (str[j] == '0')
                str1 = str1 + "1";
            else
                str1 = str1 + "01";
        }
        str = str1;
    }
    cout << str;
    return 0;
}
