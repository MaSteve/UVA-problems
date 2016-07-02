#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string s;
    while (getline(cin, s)) {
        if (isdigit(s[0])) {
            for (int i = s.length() - 2; i >= 0; i -= 2) {
                char c = char(10*(s[i+1] - '0') + (s[i] - '0'));
                if (s[i+1] == '1') c = 10*c + (s[i-1] - '0'), i--;
                printf("%c", c);
            }
        } else {
            for (int i = s.length() - 1; i >= 0; i--) {
                int val = s[i] - 'A' + 65;
                if (val >= 100) printf("%d%d1", val%10, (val/10)%10);
                else printf("%d%d", val%10, val/10);
            }
        }
        printf("\n");
    }
    return 0;
}
