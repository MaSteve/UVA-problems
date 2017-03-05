#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;

int main() {
    int p;
    cin >> p;
    vector<ii> v;
    while (p--) {
        v.clear();
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int val;
            cin >> val;
            if (val < 0) v.push_back(ii(-val, 0));
            else v.push_back(ii(val, 1));
        }
        sort(v.begin(), v.end());
        int c1 = 0, c2 = 0;
        for (int i = 0; i < n; i++) {
            if (v[i].second == c1%2) c1++;
        }
        for (int i = 0; i < n; i++) {
            if (v[i].second != c2%2) c2++;
        }
        printf("%d\n", max(c1, c2));
    }
    return 0;
}
