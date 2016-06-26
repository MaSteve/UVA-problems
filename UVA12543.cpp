#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

int main() {
    string s, m = "";
    int size = 0;
    while (cin >> s && s != "E-N-D") {
        int c = 0;
        string proc = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '-' || isalpha(s[i])) c++, proc += s[i];
        }
        if (c > size) m = proc, size = c;
    }
    transform(m.begin(), m.end(), m.begin(), ::tolower);
    cout << m << endl;
    return 0;
}
