#include <iostream>
using namespace std;

int main() {
    int T;
    bool first = false;
    cin >> T;
    while (T--) {
        if (first) printf("\n");
        else first = true;
        string s;
        cin >> s;
        int i = 1;
        for (; i < s.length(); i++) {
            if (s.length() % i == 0) {
                bool ok = true;
                for (int j = 0; j < i && ok; j++) {
                    for (int k = 1; k * i + j < s.length() && ok; k++) {
                        ok = (s[j] == s[j + k * i]);
                    }
                }
                if (ok) break;
            }
        }
        printf("%d\n", i);
    }
    return 0;
}
