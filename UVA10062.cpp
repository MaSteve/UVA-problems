#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main() {
    string s;
    bool first = true;
    while (getline(cin, s)) {
        if (first) first = false;
        else printf("\n");
        vector<pair<int, char> > v(96, make_pair(0, 0));
        for (int i = 0; i < 96; i++) v[i].second = -(i + 32);
        for (int i = 0; i < s.length(); i++) v[s[i] - 32].first++;
        sort(v.begin(), v.end());
        for (int i = 0; i < 96; i++) {
            if (v[i].first == 0) continue;
            printf("%d %d\n", -v[i].second, v[i].first);
        }
    }
    return 0;
}
