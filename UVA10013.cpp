#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    while (N--) {
        int M;
        cin >> M;
        vector<char> v1(M), v2(M);
        for (int i = 0; i < M; i++) {
            cin >> v1[i] >> v2[i];
        }
        bool carry = false;
        for (int i = M - 1; i >= 0; i--) {
            int val = v1[i] + v2[i] - '0' - '0';
            if (carry) val++;
            v1[i]= val%10 + '0';
            carry = val >= 10;
        }
        if (carry) printf("1");
        for (int i = 0; i < M; i++) printf("%c", v1[i]);
        printf("\n");
        if (N) printf("\n");
    }
    return 0;
}
