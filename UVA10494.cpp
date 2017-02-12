#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int main() {
    string S;
    char * D;
    while (cin >> S) {
        char * D = new char[S.length() + 3];
        strcpy (D, S.c_str());
        D[S.length()] = 0;
        char * C = new char[S.length() + 3];
        int posC = 0;
        for (int i = 0; i < S.length() + 3; i++) C[i] = 0;
        char sign;
        long long d;
        cin >> sign >> d;
        int l = floor(log10(d));
        int ini = 0, i = l;
        while (i < S.length()) {
            long long val = 0;
            for (int j = ini; j <= i; j++) {
                val *= 10;
                val += D[j] - '0';
            }
            if (val < d) {
                if (i + 1 < S.length()) {
                    i++;
                    val *= 10;
                    val += D[i] - '0';
                    if (val < d) {
                        C[posC] = '0';
                        posC++;
                        continue;
                    }
                } else break;
            }
            C[posC] = (val / d) + '0';
            posC++;
            long long rem = val % d;
            int prev = ini;
            ini = i;
            while (rem != 0) {
                D[ini] = (rem % 10) + '0';
                rem /= 10;
                ini--;
            }
            ini++;
        }
        if (sign == '/') {
            if (posC != 0) printf("%s\n", C);
            else printf("0\n");
        }
        else {
            for (int j = ini; j < S.length(); j++) printf("%c", D[j]);
            if (ini >= S.length()) printf("0");
            printf("\n");
        }
    }
    return 0;
}
