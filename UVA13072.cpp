#include <iostream>
#include <string>
#include <stack>
using namespace std;

int grid[1004][1004];

int main() {
    string s;
    while (cin >> s) {
        int n = s.length();
        for (int i = 0; i < n; i++) grid[0][i] = 1;
        for (int i = 0; i < n - 1; i++) grid[1][i+1] = s[i] == s[i+1]? 2: 1;
        for (int i = 2; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (s[j] == s[j-i]) grid[i][j] = 2 + grid[i-2][j-1];
                else {
                    grid[i][j] = max(grid[i-1][j-1], grid[i-1][j]);
                }
            }
        }
        int l = n-1, p = n-1;
        stack<char> st;
        while (l >= 0) {
            if (s[p] == s[p-l]) {
                printf("%c", s[p]);
                if (l != 0) st.push(s[p]);
                l -= 2, p--;
            } else {
                if (grid[l-1][p-1] > grid[l-1][p]) p--;
                l--;
            }
        }
        while (!st.empty()) printf("%c", st.top()), st.pop();
        printf("\n");
    }
    return 0;
}
