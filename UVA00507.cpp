#include <iostream>
using namespace std;

int main() {
    int b;
    cin >> b;
    for (int c = 1; c <= b; c++) {
        int s, ini, count, bini, bend, bcount;
        count = bini = bend = bcount = 0;
        ini = 1;
        cin >> s;
        for (int i = 1; i < s; i++) {
            int val;
            cin >> val;
            if (val > count + val) ini = i, count = val;
            else count += val;
            if (count > bcount || (count == bcount && i+1-ini > bend - bini)) bcount = count, bini = ini, bend = i + 1;
        }
        if (bini != 0) printf("The nicest part of route %d is between stops %d and %d\n", c, bini, bend);
        else printf("Route %d has no nice parts\n", c);
    }
    return 0;
}
