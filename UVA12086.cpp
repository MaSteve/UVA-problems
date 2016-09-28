#include <iostream>
#include <vector>
#include <assert.h>
#include <cstdlib>
#include <ctime>
using namespace std;

typedef vector<int> vi;

inline int LSOne(int i) {
    return (i & (-i));
}

struct Fenwick {
    vi ft, values;

    Fenwick(int n) {
        ft.assign(n + 1, 0);
        values.assign(n, 0);
    }

    int rsq(int b) {
        b++;
        int sum = 0;
        for (; b; b -= LSOne(b)) sum += ft[b];
        return sum;
    }

    int rsq(int a, int b) {
        return rsq(b) - (a == 0 ? 0 : rsq(a - 1));
    }

    void insert(int pos, int val) {
        int diff = val - values[pos], k = pos + 1;
        values[pos] = val;
        for (; k < (int)ft.size(); k += LSOne(k)) ft[k] += diff;
    }

    void insertDiff(int val, int diff) {
        insert(val - 1, values[val-1] + diff);
    }
};

int main() {
    int N, c = 1;
    while (cin >> N && N != 0) {
        if (c != 1) printf("\n");
        Fenwick fen(N);
        for (int i = 0; i < N; i++) {
            int aux;
            cin >> aux;
            fen.insert(i, aux);
        }
        string s;
        printf("Case %d:\n", c);
        while (cin >> s && s != "END") {
            int a, b;
            cin >> a >> b;
            if (s == "S") {
                fen.insert(a - 1, b);
            } else {
                printf("%d\n", fen.rsq(a - 1, b - 1));
            }
        }
        c++;
    }
    return 0;
}
