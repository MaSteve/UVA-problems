#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<int, int> v, p;
    int N;
    while (cin >> N) {
        for (int i = 0; i < (1<<N); i++) {
            cin >> v[i];
        }
        for (int i = 0; i < (1<<N); i++) {
            p[i] = 0;
            for (int j = 0; j < N; j++) {
                p[i] += v[(i ^ (1<<j))];
            }
        }
        int maxi = -1;
        for (int i = 0; i < (1<<N); i++) {
            for (int j = 0; j < N; j++) {
                if (p[i] + p[(i ^ (1<<j))] > maxi) maxi = p[i] + p[(i ^ (1<<j))];
            }
        }
        printf("%d\n", maxi);
    }
    return 0;
}
