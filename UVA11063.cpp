#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
    unordered_set<int> s;
    vector<int> v;
    int N, c = 1;
    while (cin >> N) {
        v.clear();
        s.clear();
        bool ok = true;
        int prev = 0;
        while (N--) {
            int val;
            cin >> val;
            v.push_back(val);
            if (ok) ok = val > prev;
            prev = val;
            for (int i = 0; i < v.size() && ok; i++) {
                ok = !s.count(v[i] + val);
                s.insert(v[i] + val);
            }
        }
        printf("Case #%d: ", c++);
        if (ok) printf("It is a B2-Sequence.\n\n");
        else printf("It is not a B2-Sequence.\n\n");
    }
    return 0;
}
