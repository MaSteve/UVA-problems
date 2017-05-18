#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int N, K, inc;

int proc(int i, int j) {
    if (inc > K) return K + 10;
    if (i == j) return 0;
    if (i == j - 1) return v[i] == v[j]? 0: 1;
    int sol;
    if (v[i] == v[j]) sol = proc(i+1, j-1);
    else {
        inc++;
        sol = min(proc(i+1, j), proc(i, j-1)) + 1;
        inc--;
    }
    return sol;
}

int main() {
    int T;
    cin >> T;
    for (int c = 1; c <= T; c++) {
        v.clear();
        cin >> N >> K;
        inc = 0;
        for (int i = 0; i < N; i++) {
            int val;
            cin >> val;
            v.push_back(val);
        }
        int sol = proc(0, v.size() - 1);
        if (sol == 0) printf("Case %d: Too easy\n", c);
        else if (sol <= K) printf("Case %d: %d\n", c, sol);
        else printf("Case %d: Too difficult\n", c);

    }
    return 0;
}
