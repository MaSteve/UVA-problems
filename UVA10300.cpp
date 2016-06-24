#include <cstdio>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int f;
        scanf("%d", &f);
        int budget = 0, size, animals, EFvalue;
        while (f--) {
            scanf("%d %d %d", &size, &animals, &EFvalue);
            budget += size*EFvalue;
        }
        printf("%d\n", budget);
    }
    return 0;
}
