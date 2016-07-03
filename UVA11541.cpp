#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    getline(cin, s);
    for (int i = 1; i <= n; i++) {
        getline(cin, s);
        char c;
        int acum = 0;
        printf("Case %d: ", i);
        for (int j = 0; j < s.length(); j++) {
            if (isalpha(s[j])) {
                while (acum--) printf("%c", c);
                c = s[j];
                acum = 0;
            } else acum = 10*acum + (s[j]-'0');
        }
        while (acum--) printf("%c", c);
        printf("\n");
    }
    return 0;
}
