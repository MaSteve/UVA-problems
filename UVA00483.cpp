#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string s;
    while (getline(cin, s)) {
        for (int i = 0; i < s.length(); i++) {
            if (isspace(s[i])) {
                for (int j = i-1; j >= 0 && !isspace(s[j]); j--) printf("%c", s[j]);
                printf("%c", s[i]);
            }
        }
        if (!isspace(s[s.length()-1])) {
            for (int j = s.length()-1; j >= 0 && !isspace(s[j]); j--) printf("%c", s[j]);
        }
        printf("\n");
    }
    return 0;
}
