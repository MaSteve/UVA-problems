#include <cstdio>
using namespace std;

int main() {
    /*for (int i = 0; i <= 10000; i++) {
        int sqrt = i*i;
        if (sqrt < 100) {
            int aux = sqrt%10 + sqrt/10;
            aux *= aux;
            if (aux == sqrt) printf("%d\n", sqrt);
        } else if (sqrt < 10000) {
            int aux = sqrt%100 + sqrt/100;
            aux *= aux;
            if (aux == sqrt) printf("%d\n", sqrt);
        } else if (sqrt < 1000000) {
            int aux = sqrt%1000 + sqrt/1000;
            aux *= aux;
            if (aux == sqrt) printf("%d\n", sqrt);
        } else if (sqrt < 100000000) {
            int aux = sqrt%10000 + sqrt/10000;
            aux *= aux;
            if (aux == sqrt) printf("%d\n", sqrt);
        }
    }*/
    char* s2 = "00\n01\n81\n"; // 0 and 1 appear in all outputs
    char* s4 = "0000\n0001\n2025\n3025\n9801\n";
    char* s6 = "000000\n000001\n088209\n494209\n998001\n";
    char* s8 = "00000000\n00000001\n04941729\n07441984\n24502500\n25502500\n52881984\n60481729\n99980001\n";
    int n;
    while (scanf("%d", &n) != EOF) {
        if (n == 2) printf("%s", s2);
        else if (n == 4) printf("%s", s4);
        else if (n == 6) printf("%s", s6);
        else if (n == 8) printf("%s", s8);
    }
    return 0;
}
