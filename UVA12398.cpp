#include <iostream>
using namespace std;

inline bool limits(int i, int j) {
    return i >= 0 && i < 3 && j >= 0 && j < 3;
}

int main() {
    int mat[3][3], c = 1;
    string s;
    while (getline(cin, s)) {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                mat[i][j] = 0;
        for (int k = 0; k < s.length(); k++) {
            int val = s[k] - 'a';
            int i = val/3, j = val%3;
            mat[i][j]++, mat[i][j]%=10;
            if (limits(i-1, j)) mat[i-1][j]++, mat[i-1][j]%=10;
            if (limits(i+1, j)) mat[i+1][j]++, mat[i+1][j]%=10;
            if (limits(i, j-1)) mat[i][j-1]++, mat[i][j-1]%=10;
            if (limits(i, j+1)) mat[i][j+1]++, mat[i][j+1]%=10;
        }
        printf("Case #%d:\n", c++);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (j != 0) printf(" ");
                printf("%d", mat[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
