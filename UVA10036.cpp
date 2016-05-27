#include <iostream>
#include <unordered_set>
using namespace std;

int num[10002];
int N, K;

unordered_set<int> proc(int ini, int fin) {
    if (ini < fin) {
        unordered_set<int> s1 = proc(ini, (ini + fin)/2), s2 = proc((ini + fin)/2 + 1, fin), r;
        for (auto it1 = s1.begin(); it1 != s1.end(); ++it1) {
            for (auto it2 = s2.begin(); it2 != s2.end(); ++it2) {
                r.insert((*it1 + *it2)%K);
                r.insert((*it1 - *it2 + K)%K);
            }
        }
        return r;
    } else {
        unordered_set<int> r;
        r.insert(((num[ini]%K)+K)%K);
        return r;
    }
}

int main() {
    int M;
    cin >> M;
    while (M--) {
        cin >> N >> K;
        for (int i = 0; i < N; i++) {
            cin >> num[i];
        }
        unordered_set<int> r = proc(0, N-1);
        if (r.count(0)) printf("Divisible\n");
        else printf("Not divisible\n");
    }
    return 0;
}
