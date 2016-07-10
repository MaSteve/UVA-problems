#include <iostream>
using namespace std;

int main() {
    long long vals[13];
    int N;
    while (cin >> N && N != 0) {
        int K;
        for (int i = 0; i < N; i++) cin >> vals[i];
        for (int j = 1; j < N; j++)
            for (int i = 0; i < N - j; i++) vals[i] = vals[i+1]-vals[i];
        cin >> K;
        for (int j = 0; j < K; j++)
            for (int i = 1; i < N; i++) vals[i] = vals[i-1]+vals[i];
        printf("Term %d of the sequence is %lld\n", N + K, vals[N-1]);
    }
    return 0;
}
