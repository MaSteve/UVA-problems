#include <iostream>
#include <unordered_set>
using namespace std;

int mat[90][90]; // -1 not processed, 1 palindrome, 0 otherwise
unordered_set<string> pal;
string s;

int check(int i, int j) {
    if (j < i) return 0;
    if (mat[i][j] == -1) {
        if (i == j) {
            mat[i][j] = 1;
            pal.insert(s.substr(i, 1));
        } else {
            mat[i][j] = 0;
            check(i, j-1);
            check(i+1, j);
            if (s[i] == s[j] && (j - i == 1 || check(i+1, j-1))) {
                mat[i][j] = 1;
                pal.insert(s.substr(i, j - i + 1));
            }
        }
    } return mat[i][j];
}

int main() {
    while (cin >> s) {
        pal.clear();
        for (int i = 0; i < s.length(); i++)
            for (int j = i; j < s.length(); j++)
                mat[i][j] = -1;
        check(0, s.length()-1);
        printf("The string '%s' contains %lu palindromes.\n", s.c_str(), pal.size());
    }
    return 0;
}
