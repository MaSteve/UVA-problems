#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

char s[12];
char per[12];
bool mask[12];
int len;

void proc(int i) {
    if (i == len) {
        for (int j = 0; j < len; j++) {
            printf("%c", per[j]);
        }
        printf("\n");
    }
    int last = -1;
    for (int j = 0; j < len; j++) {
        if (last >= 0 && s[j] == s[last]) continue;
        if (!mask[j]) {
            mask[j] = true;
            per[i] = s[j];
            proc(i+1);
            mask[j] = false;
            last = j;
        }
    }
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        scanf("%s", s);
        len = strlen(s);
        sort(s, s+len);
        proc(0);
        printf("\n");
    }
    return 0;
}
