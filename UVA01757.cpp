#include <iostream>
using namespace std;

int *curr, *nextc, *auxi;

int main() {
    curr = new int[30];
    nextc = new int[30];
    int m, n;
    while (cin >> m >> n) {
        for (int i = 0; i < 30; i++)
            curr[i] = 1 << i, nextc[i] = 0;
        for (int i = 0; i < m; i++) {
            char a, b;
            cin >> a >> b;
            curr[a-'a'] |= 1 << (b-'a');
        }
        bool change = true;
        while (change) {
            change = false;
            for (int i = 0; i < 30; i++) {
                nextc[i] = curr[i];
                for (int j = 0; j < 30; j++) {
                    if ((curr[i]>>(j)) & 1) {
                        nextc[i] |= curr[j];
                    }
                }
                change = change || nextc[i] != curr[i];
            }
            auxi = nextc;
            nextc = curr;
            curr = auxi;
        }
        for (int i = 0; i < n; i++) {
            string s1, s2;
            cin >> s1 >> s2;
            bool ok = false;
            if (s1.length() == s2.length()) {
                ok = true;
                for (int j = 0; j < s1.length() && ok; j++) {
                    if (!((curr[s1[j]-'a'] >> (s2[j]-'a')) & 1)) ok = false;
                }
            }
            if (ok) printf("yes\n");
            else printf("no\n");
        }
    }
    delete[] nextc;
    delete[] curr;
    return 0;
}
