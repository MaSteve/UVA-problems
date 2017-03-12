#include <iostream>
using namespace std;

int value(char c) {
    int val = c - 'A';
    if (val < 0) return c - '0';
    return val + 10;
}

long long eval(string & s, int base) {
    long long ret = 0, pot = 1;
    for (int i = s.length()-1; i >= 0; i--) {
        ret += value(s[i]) * pot;
        pot *= base;
    }
    return ret;
}

int main() {
    string s1, s2;
    while (cin >> s1 >> s2) {
        int b1 = 2, b2 = 2;
        for (int i = 0; i < s1.length(); i++) b1 = max(b1, value(s1[i]) + 1);
        for (int i = 0; i < s2.length(); i++) b2 = max(b2, value(s2[i]) + 1);
        bool ok = false;
        for (int i = b1; i <= 36 && !ok; i++) {
            for (int j = b2; j <= 36 && !ok; j++) {
                if (eval(s1, i) == eval(s2, j)) {
                    printf("%s (base %d) = %s (base %d)\n", s1.c_str(), i, s2.c_str(), j);
                    ok = true;
                }
            }
        }
        if (!ok) printf("%s is not equal to %s in any base 2..36\n", s1.c_str(), s2.c_str());
    }
    return 0;
}
