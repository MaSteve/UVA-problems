#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
    int D, c = 1;
    unordered_set<int> set;
    vector<int> v, v1;
    while (cin >> D) {
        set.clear();
        v1.assign(D, 0);
        int last = -1;
        bool ok = true;
        int i = 0;
        for (; i < D && ok; i++) {
            int val;
            cin >> val;
            v1[i] = val;
            if (val > last && !set.count(val)) {
                last = val;
                v.clear();
                for (auto it = set.begin(); it != set.end(); ++it) {
                    v.push_back((*it) + val);
                }
                for (int j = 0; j < v.size(); j++) set.insert(v[j]);
                set.insert(val);
            } else ok = false;
        }
        for (; i < D; i++) cin >> v1[i];
        printf("Case #%d:", c++);
        for (int i = 0; i < v1.size(); i++) printf(" %d", v1[i]);
        printf("\n");
        if (ok) printf("This is an A-sequence.\n");
        else printf("This is not an A-sequence.\n");
    }
    return 0;
}
