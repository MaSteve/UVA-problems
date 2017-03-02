#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, ii> iiii;

int main() {
    int n, test = 1;
    bool mask[9];
    for (int i = 0; i < 9; i++) mask[i] = false;
    while (cin >> n && n != 0) {
        vector<iiii> v;
        for (int i = 0; i < n; i++) {
            int a, b, c, s;
            cin >> a >> b >> c >> s;
            v.push_back(iiii(ii(a-1, b-1), ii(c-1, s)));
        }
        int score = -1;
        for (int i = 0; i < n; i++) {
            iiii pc1 = v[i];
            int acum = pc1.second.second;
            mask[pc1.first.first] = mask[pc1.first.second] = mask[pc1.second.first] = true;
            for (int j = i; j < n; j++) {
                iiii pc2 = v[j];
                if (!(mask[pc2.first.first] || mask[pc2.first.second] || mask[pc2.second.first])) {
                    acum += pc2.second.second;
                    mask[pc2.first.first] = mask[pc2.first.second] = mask[pc2.second.first] = true;
                    for (int k = j; k < n; k++) {
                        iiii pc3 = v[k];
                        if (!(mask[pc3.first.first] || mask[pc3.first.second] || mask[pc3.second.first])) {
                            score = max(score, acum + pc3.second.second);
                        }
                    }
                    mask[pc2.first.first] = mask[pc2.first.second] = mask[pc2.second.first] = false;
                    acum -= pc2.second.second;
                }
            }
            mask[pc1.first.first] = mask[pc1.first.second] = mask[pc1.second.first] = false;
        }
        printf("Case %d: %d\n", test++, score);
    }
    return 0;
}
