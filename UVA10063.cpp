#include <iostream>
using namespace std;

string s;

void proc(char p[12], int l) {
    char next[12];
    if (l == s.length()) {
        for (int i = 0; i < l; i++) printf("%c", p[i]);
        printf("\n");
    } else {
        for (int i = 0; i < l; i++) next[i+1] = p[i];
        next[0] = s[l];
        for (int i = 0; i <= l; i++) {
            proc(next, l + 1);
            char auxi = next[i];
            next[i] = next[i+1];
            next[i+1] = auxi;
        }
    }
}

int main() {
    char p[12];
    bool first = false;
    while (cin >> s) {
        if (first) printf("\n");
        else first = true;
        proc(p, 0);
    }
    return 0;
}
