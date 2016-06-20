#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int M, W;
        cin >> M >> W;
        vector<int> v;
        for (int i = 0; i < M; i++){
            int w;
            cin >> w;
            v.push_back(w);
        }
        sort(v.begin(), v.end());
        int w = 0, cont = 0;
        for (int i = 0; i < M; i++) {
            if (v[i] + w <= W) {
                cont++;
                w += v[i];
            } else break;
        }
        printf("%d\n", cont);
    }
    return 0;
}
