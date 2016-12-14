#include <iostream>
#include <utility>
using namespace std;

typedef pair<int, int> ii;

int main() {
    ii gauss[30];
    gauss[0].first = 1;
    gauss[0].second = 0;
    gauss[1].first = -1;
    gauss[1].second = 1;
    for (int i = 2; i < 30; i++) {
        gauss[i].first = -gauss[i-1].first - gauss[i-1].second;
        gauss[i].second = gauss[i-1].first - gauss[i-1].second;
    }
    int p;
    while (cin >> p) {
        ii res = ii(0, 0);
        int i = 0;
        while (p) {
            int b = p&1;
            p >>= 1;
            if (b) res.first += gauss[i].first, res.second += gauss[i].second;
            i++;
        }
        printf("%d %d\n", res.first, res.second);
    }
    return 0;
}
