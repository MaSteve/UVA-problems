#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    while (cin >> N && N != 0) {
        int best = 0;
        double db = 0;
        for (int i = 1; i <= N; i++) {
            double w, h;
            cin >> w >> h;
            double mini = min(w, h), maxi = max(w, h);
            double t = max(mini/2, min(maxi/4, mini));
            if (t > db) db = t, best = i;
        }
        printf("%d\n", best);
    }
    return 0;
}
