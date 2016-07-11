#include <iostream>
#include <cmath>
using namespace std;

int main() {
    printf("         6         8\n        35        49\n       204       288\n      1189      1681\n      6930      9800\n     40391     57121\n    235416    332928\n   1372105   1940449\n   7997214  11309768\n  46611179  65918161\n");
    return 0;
}

/*
import math;
for i in range(2, 1000000000):
    s1 = ((i - 1) * i) /2;
    val = math.floor((-1 + math.sqrt(1 + 8*(2*s1 + i)))/2);
    if (s1 == ((val*(val+1)/2) - s1 - i)):
        print (i, val);
*/
