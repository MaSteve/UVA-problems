#include <iostream>
using namespace std;

typedef unsigned long long ll;

ll pot[31];
string s;

ll proc(int pos) {
    if (pos == 0) return 0;
    ll res = 0;
    switch (s[s.length() - pos]) {
        case 'A': res = 0 * pot[pos-1]; break;
        case 'C': res = 1 * pot[pos-1]; break;
        case 'G': res = 2 * pot[pos-1]; break;
        case 'T': res = 3 * pot[pos-1]; break;
    }
    res += proc(pos - 1);
    return res;
}

int main() {
    pot[0] = 1;
    for (int i = 1; i < 31; i++) pot[i] = 4*pot[i - 1];
    int T;
    cin >> T;
    for (int c = 1; c <= T; c++) {
        cin >> s;
        ll res = proc(s.length());
        printf("Case %d: (%lu:%llu)\n", c, s.length(), res);
    }
    return 0;
}
