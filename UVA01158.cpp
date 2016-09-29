#include <iostream>
#include <unordered_map>
#include <cmath>
using namespace std;

unordered_map<int, int> map;
unordered_map<int, int> pyramids;
unordered_map<int, int> cubes;

int proc(int N) {
    if (N == 0) return 0;
    if (!map.count(N)) {
        int mini = 100000000;
        for (int i = floor(cbrt(N)); i >= 1; i--) {
            int val = proc(N - i*i*i) + 1;
            if (val < mini) mini = val;
        }
        for (int i = 106; i >= 1; i--) {
            if (pyramids[i] > N) continue;
            int val = proc(N - pyramids[i]) + 1;
            if (val < mini) mini = val;
        }
        map[N] = mini;
    }
    return map[N];
}

int main() {
    int val1 = 0;
    for (int i = 0; val1 <= 400000; i++) {
        val1 += i*i;
        pyramids[i] = val1;
    }
    int N;
    while (cin >> N && N != -1) {
        printf("%d\n", proc(N));
    }
    return 0;
}
