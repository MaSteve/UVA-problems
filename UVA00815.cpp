#include <iostream>
#include <algorithm>
using namespace std;

int v[910];

int main() {
    int n, m, c = 1;
    while (cin >> n >> m && !(n == 0 && m == 0)) {
        for (int i = 0; i < n*m; i++) cin >> v[i];
        int maxVol;
        cin >> maxVol;
        sort(v, v + (n*m));
        int a = 0, vol = 0, i = 0;
        double lev = v[0];
        for (; i < n*m - 1 && vol < maxVol; i++) {
            a++;
            if (a * 100 * (v[i+1] - v[i]) + vol > maxVol) {
                lev = v[i] + ((maxVol - vol) / (a*100.0));
                vol = maxVol;
            }
            else {
                vol += a * 100 * (v[i+1] - v[i]);
            }
        }
        if (vol < maxVol) a++, lev = v[i] + ((maxVol - vol) / (a*100.0));
        printf("Region %d\n", c++);
        printf("Water level is %.2lf meters.\n", lev);
        printf("%.2lf percent of the region is under water.\n\n", 100*a/double(n*m));
    }
    return 0;
}
