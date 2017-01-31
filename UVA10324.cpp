#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v;
    string s;
    int c = 1;
    while (cin >> s) {
        v.clear();
        v.push_back(0);
        for (int i = 1; i < s.length(); i++) {
            if (s[i] != s[i-1]) v.push_back(i);
        }
        printf("Case %d:\n", c);
        int n;
        cin >> n;
        while (n--) {
            int i, j, auxi;
            cin >> i >> j;
            auxi = min(i, j);
            j = max(i, j);
            i = auxi;
            int p1 = upper_bound(v.begin(), v.end(), i) - v.begin();
            int p2 = upper_bound(v.begin(), v.end(), j) - v.begin();
            if (p1 == p2) printf("Yes\n");
            else printf("No\n");
        }
        c++;
    }
    return 0;
}
