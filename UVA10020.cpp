#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;

int main() {
    int N;
    cin >> N;
    while (N--) {
        int M;
        cin >> M;
        int L, R;
        vector<ii> v;
        while (cin >> L >> R && !(L == 0 && R == 0)) v.push_back(make_pair(L, R));
        sort(v.begin(), v.end());
        vector<ii> sol;
        int last = 0;
        bool covered = false;
        for (int i = 0; i < v.size() && !covered; i++) {
            if (v[i].first > last) break;
            ii maxi = v[i];
            while (i < v.size() && v[i].first <= last) {
                if (v[i].second > maxi.second) maxi = v[i];
                i++;
            }
            if (i < v.size()) i--;
            if (maxi.second > last) {
                last = maxi.second;
                sol.push_back(maxi);
            }
            if (last >= M) covered = true;
        }
        if (covered) {
            printf("%d\n", sol.size());
            for (int i = 0; i < sol.size(); i++) printf("%d %d\n", sol[i].first,  sol[i].second);
        } else printf("0\n");
        if (N != 0) printf("\n");
    }
    return 0;
}
