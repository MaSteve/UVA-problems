#include <cstdio>
using namespace std;

int matrix[75][75];
int v[75];
int N;

int kadane1() {
    int max = -1000000, sum, start;
    bool stop = false;
    for (int k = 0; k < N; k++) {
        start = k;
        sum = 0;
        for (int i = start; /*i < 2*N &&*/ i < start + N && start < N; i++) {
            if (v[i%N] > v[i%N] + sum) { sum = v[i%N]; start = i; }
            else sum += v[i%N];
            if (sum > max) max = sum;
        }
    }
    return max;
}

int kadane2() {
    int max = -1000000, start = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) v[j] = 0;
        for (int j = i; j < i + N; j++) {
            for (int l = 0; l < N; l++) v[l] += matrix[l][j%N];
            int sum = kadane1();
            if (sum > max) max = sum;
        }
    }
    return max;
}

int main() {
    int cases;
    scanf("%d", &cases);
    while (cases--) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                scanf("%d", &matrix[i][j]);
        printf("%d\n", kadane2());
    }
    return 0;
}
