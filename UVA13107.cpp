#include <iostream>
using namespace std;

int main() {
    string s;
    int code[30];
    while (cin >> s) {
        int c = 1;
        for (int i = 0; i < 30; i++) code[i] = 0;
        for (int i = 0; i < s.length(); i++) {
            if (code[s[i] - 'a'] == 0) {
                code[s[i] - 'a'] = c, c++;
                if (code[s[i] - 'a'] == 2) code[s[i] - 'a'] = 5;
                else if (code[s[i] - 'a'] == 5) code[s[i] - 'a'] = 2;
                else if (code[s[i] - 'a'] == 6) code[s[i] - 'a'] = 9;
                else if (code[s[i] - 'a'] == 9) code[s[i] - 'a'] = 6;
                else if (code[s[i] - 'a'] == 12) code[s[i] - 'a'] = 15;
                else if (code[s[i] - 'a'] == 15) code[s[i] - 'a'] = 12;
                else if (code[s[i] - 'a'] == 16) code[s[i] - 'a'] = 19;
                else if (code[s[i] - 'a'] == 19) code[s[i] - 'a'] = 16;
                else if (code[s[i] - 'a'] == 22) code[s[i] - 'a'] = 55;
                else if (code[s[i] - 'a'] == 25) code[s[i] - 'a'] = 52;
                else if (code[s[i] - 'a'] == 26) code[s[i] - 'a'] = 59;
                else if (code[s[i] - 'a'] == 29) code[s[i] - 'a'] = 56;
                else if (code[s[i] - 'a'] >= 20) code[s[i] - 'a'] += 30;
            }
            printf("%d", code[s[i] - 'a']);
        }
        printf("\n");
    }
    return 0;
}
