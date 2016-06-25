#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<int> v;
        for (int i = 0; i < n; i++) {
            int s;
            cin >> s;
            v.push_back(s);
        }
        sort(v.begin(), v.end());
        bool ok = true;
        for (int i = 1; i < n && ok; i++) {
            if (v[i]-v[i-1] > 200) ok = false;
        }
        if (ok && 1422 - v[n-1] <= 100) printf("POSSIBLE\n");
        else printf("IMPOSSIBLE\n");
    }
    return 0;
}
