#include <iostream>
using namespace std;

char soundex(char c) {
    if (c == 'B' || c == 'F' || c == 'P' || c == 'V') return '1';
    if (c == 'C' || c == 'G' || c == 'J' || c == 'K' || c == 'Q' || c == 'S' || c == 'X' || c == 'Z') return '2';
    if (c == 'D' || c == 'T') return '3';
    if (c == 'L') return '4';
    if (c == 'M' || c == 'N') return '5';
    if (c == 'R') return '6';
    return ' ';
}

int main() {
    string s;
    while (cin >> s) {
        char prev = ' ', c;
        for (int i = 0; i < s.length(); i++) {
            c = soundex(s[i]);
            if (c != prev && c != ' ') printf("%c", c);
            prev = c;
        }
        printf("\n");
    }
    return 0;
}
