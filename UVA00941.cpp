#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    unsigned long long fact[21], k;
    fact[0] = 1;
    for (int i = 1; i < 21; i++) fact[i] = fact[i-1]*i;
    char p[21];
    bool mask[21];
    queue<char> q;
    int T;
    string s;
    cin >> T;
    while (T--) {
        cin >> s >> k;
        for (int i = 0; i < s.length(); i++) p[i] = s[i], mask[i] = false;
        sort(p, p + s.length());
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
            q.push(p[last]);
            k -= fact[s.length()-(i+1)]*(f-1);
        }
        for (int i = 0; i < s.length(); i++) printf("%c", q.front()), q.pop();
        printf("\n");
    }
    return 0;
}
