#include <iostream>
using namespace std;

int main() {
    int * kingdom1 = new int[10000], * kingdom2 = new int[10000];
    int N, R, C, K;
    while (cin >> N >> R >> C >> K && !(N == 0 && R == 0 && C == 0 && K == 0)) {
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                cin >> kingdom1[i*100 + j];
                
        for (int b = 0; b < K; b++) {
            int * k1 = (b & 1 ? kingdom2: kingdom1);
            int * k2 = (b & 1 ? kingdom1: kingdom2);
            for (int i = 0; i < R; i++)
                for (int j = 0; j < C; j++) {
                    int attacked = 0, auxi = (k1[i*100 + j] + N - 1) % N;
                    if (i > 0) attacked |= k1[(i-1)*100 + j] == auxi;
                    if (j > 0) attacked |= k1[i*100 + j-1] == auxi;
                    if (i < R - 1) attacked |= k1[(i+1)*100 + j] == auxi;
                    if (j < C - 1) attacked |= k1[i*100 + j+1] == auxi;
                    if (attacked) k2[i*100 + j] = auxi;
                    else k2[i*100 + j] = k1[i*100 + j];
                }
        }
        int * k = (K & 1 ? kingdom2: kingdom1);
        for (int i = 0; i < R; i++) {
            bool first = false;
            for (int j = 0; j < C; j++) {
                if (first) printf(" ");
                else first = true;
                printf("%d", k[i*100 + j]);
            }
            printf("\n");
        }
    }
    delete [] kingdom1;
    delete [] kingdom2;
    return 0;
}
