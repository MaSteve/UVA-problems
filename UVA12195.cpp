#include <iostream>
using namespace std;

int main() {
    string s;
    while (cin >> s && s != "*") {
        int m = 0, d = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '/') {
                if (d == 64) m++;
                d = 0;
            } else if (s[i] == 'W') d += 64;
            else if (s[i] == 'H') d += 32;
            else if (s[i] == 'Q') d += 16;
            else if (s[i] == 'E') d += 8;
            else if (s[i] == 'S') d += 4;
            else if (s[i] == 'T') d += 2;
            else if (s[i] == 'X') d += 1;
        }
        printf("%d\n", m);
    }
    return 0;
}
