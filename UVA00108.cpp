#include <cstdio>
using namespace std;

int matrix[100][100];
int v[100];
int N;

int kadane1() {
    int max = -1270000, sum = 0;
    for (int i = 0; i < N; i++) {
        if (v[i] > v[i] + sum) sum = v[i];
        else sum += v[i];
        if (sum > max) max = sum;
    }
    return max;
}

int kadane2() {
    int max = -1270000;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) v[j] = 0;
        for (int j = i; j < N; j++) {
            for (int l = 0; l < N; l++) v[l] += matrix[l][j];
            int sum = kadane1();
            if (sum > max) max = sum;
        }
    }
    return max;
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &matrix[i][j]);
    printf("%d\n", kadane2());
    return 0;
}
