#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    bool mask[101];
    for (int c = 1; c <= T; c++) {
        string S, T;
        cin >> S >> T;
        int c0s = 0, c1s = 0, c0t = 0, c1t = 0;
        for (int i = 0; i < S.length(); i++) {
            if (S[i] == '1') c1s++;
            else if (S[i] == '0') c0s++;
            if (T[i] == '1') c1t++;
            else if (T[i] == '0') c0t++;
            mask[i] = (S[i] != T[i]);
        }
        int res = 0;
        for (int i = 0; i < S.length(); i++) {
            if (S[i] == '?') {
                if (T[i] == '1') {
                    if (c1s < c1t) {
                        c1s++;
                        mask[i] = false;
                    } else c0s++;
                }
                else {
                    if (c0s < c0t) {
                        c0s++;
                        mask[i] = false;
                    } else c1s++;
                }
                res++;
            }
        }
        if (c1s < c1t) {
            for (int i = 0; i < S.length() && c1s < c1t; i++) {
                if (S[i] == '0' && T[i] == '1') {
                    res++;
                    c1s++;
                    c0s--;
                    mask[i] = false;
                }
            }
        }
        printf("Case %d: ", c);
        if (c0s == c0t && c1s == c1t) {
            int auxi = 0;
            for (int i = 0; i < S.length(); i++)
                if (mask[i]) auxi++;
            printf("%d\n", res + auxi/2);
        } else printf("-1\n");
    }
    return 0;
}
