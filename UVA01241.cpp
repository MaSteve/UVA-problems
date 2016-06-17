#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int cont;

void func(unordered_set<int> & wd, int N) {
    if (N == 0) return;
    unordered_set<int> wdn;
    for (int i = 0; i < (1<<(N-1)); i++) {
        if (wd.count((i << 1)) && wd.count((i << 1)+1)) {
            wdn.insert(i);
        } else if (wd.count((i << 1)) || wd.count((i << 1)+1)) {
            cont++;
        }
    }
    if (wdn.size() != 0) func(wdn, N-1);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        unordered_set<int> wd;
        while (M--) {
            int p;
            cin >> p;
            wd.insert(p-1);
        }
        cont = 0;
        func(wd, N);
        printf("%d\n", cont);
    }
    return 0;
}
