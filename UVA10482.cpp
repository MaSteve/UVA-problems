#include <iostream>
#include <unordered_map>
using namespace std;

typedef unordered_map<unsigned long long, int> uli;

uli map;

int N;
int candies[34];

int proc(int w1, int w2, int w3, int i) {
    if (i >= N) {
        int maxi = max(w1, max(w2, w3)), mini = min(w1, min(w2, w3));
        return maxi - mini;
    }
    if (!map.count(i + 100*(w3 + 1000*(w2 + 1000*(w1))))) {
        int d1 = proc(w1 + candies[i], w2, w3, i+1);
        int d2 = proc(w1, w2 + candies[i], w3, i+1);
        int d3 = proc(w1, w2, w3 + candies[i], i+1);
        map[i + 100*(w3 + 1000*(w2 + 1000*(w1)))] = min(d1, min(d2, d3));
    }
    return map[i + 100*(w3 + 1000*(w2 + 1000*(w1)))];
}

int main() {
    int T;
    cin >> T;
    for (int c = 1; c <= T; c++) {
        cin >> N;
        map.clear();
        for (int i = 0; i < N; i++) cin >> candies[i];
        printf("Case %d: %d\n", c, proc(0, 0, 0, 0));
    }
    return 0;
}
