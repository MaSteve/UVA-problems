#include <iostream>
#include <unordered_set>
using namespace std;

typedef unordered_set<int> ui;

int maxOff, P, N;

void proc(ui & sym, int c, int mask, int off) {
    ui newSym;
    for (int i = c; i < P; i++) {
        newSym.clear();
        int newMask = mask & (~(1 << i));
        for (auto it = sym.begin(); it != sym.end(); ++it) {
            int val = (*it) & newMask;
            if (!newSym.count(val)) newSym.insert(val);
            else break;
        }
        if (newSym.size() == sym.size()) {
            maxOff = max(maxOff, off + 1);
            if (i + 1 < P) proc(newSym, i + 1, newMask, off + 1);
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> P >> N;
        ui symbol;
        for (int i = 0; i < N; i++) {
            int sym = 0;
            for (int j = 0; j < P; j++) {
                sym <<= 1;
                int val;
                cin >> val;
                if (val) sym |= 1;
            }
            symbol.insert(sym);
        }
        int off = maxOff = 0;
        int mask = (1 << P) - 1;
        proc(symbol, 0, mask, off);
        printf("%d\n", P - maxOff);
    }
    return 0;
}
