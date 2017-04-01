#include <iostream>
using namespace std;

int mat1[101][101], mat2[101][101];
int r, c, n;

inline bool limits(int i, int j) {
    return i < r && j < c && i >= 0 && j >= 0;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> r >> c >> n;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                char c;
                cin >> c;
                if (c == 'R') mat1[i][j] = 0;
                else if (c == 'S') mat1[i][j] = 1;
                else if (c == 'P') mat1[i][j] = 2;
            }
        }
        auto mat = mat1, next = mat2;
        for (int t = 0; t < n; t++) {
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    next[i][j] = mat[i][j];
                }
            }
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    if (limits(i+1, j) && (mat[i][j]+1)%3 == mat[i+1][j]) next[i+1][j] = mat[i][j];
                    if (limits(i-1, j) && (mat[i][j]+1)%3 == mat[i-1][j]) next[i-1][j] = mat[i][j];
                    if (limits(i, j+1) && (mat[i][j]+1)%3 == mat[i][j+1]) next[i][j+1] = mat[i][j];
                    if (limits(i, j-1) && (mat[i][j]+1)%3 == mat[i][j-1]) next[i][j-1] = mat[i][j];
                }
            }
            auto auxi = mat;
            mat = next;
            next = auxi;
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                char ch;
                if (mat[i][j] == 0) ch = 'R';
                else if (mat[i][j] == 1) ch = 'S';
                else if (mat[i][j] == 2) ch = 'P';
                printf("%c", ch);
            }
            printf("\n");
        }
        if (T) printf("\n");
    }
    return 0;
}
