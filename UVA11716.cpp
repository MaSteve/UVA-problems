#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    getline(cin, s);
    while (n--) {
        getline(cin, s);
        int r = floor(sqrt(s.length()));
        if (r*r == s.length()) {
            for (int i = 0; i < r; i++)
                for (int j = 0; j < r; j++)
                    printf("%c", s[j*r + i]);
            printf("\n");
        } else printf("INVALID\n");
    }
    return 0;
}
