#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

typedef pair<int, char> ic;

int main() {
    unsigned long long fact[21], k;
    fact[0] = 1;
    for (int i = 1; i < 21; i++) fact[i] = fact[i-1]*i;
    ic p[21];
    bool mask[21];
    int T;
    string s;
    cin >> T;
    for (int c = 1; c <= T; c++) {
        cin >> s >> k;
        for (int i = 0; i < s.length(); i++) {
            p[i].second = s[i];
            mask[i] = false;
        }
        k--;
        for (int i = 0; i < s.length(); i++) {
            int j, f, last;
            for (j = 0, f = 1, last = 0; j < s.length(); j++) {
                if (!mask[j]) {
                    last = j;
                    if (fact[s.length()-(i+1)]*f > k) break;
                    f++;
                }
            }
            mask[last] = true;
            p[i].first = last+1;
            k -= fact[s.length()-(i+1)]*(f-1);
        }
        sort(p, p + s.length());
        printf("Case %d: ", c);
        for (int i = 0; i < s.length(); i++) printf("%c", p[i].second);
        printf("\n");
    }
    return 0;
}
