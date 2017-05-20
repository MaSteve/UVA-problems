#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string line;
    while (getline(cin, line) && line != "*") {
        stringstream st(line);
        string s;
        bool ok = true;
        st >> s;
        char ref = s[0];
        if (isupper(ref)) ref = tolower(ref);
        while (st >> s) {
            char c = s[0];
            if (isupper(c)) c = tolower(c);
            ok = ok && (c == ref);
        }
        if (ok) printf("Y\n");
        else printf("N\n");
    }
    return 0;
}
