#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<unsigned int, int> Cat;
    long long lastC = 1;
    for (int i = 1; true; i++) {
        unsigned int next = (lastC*(4*i-2))/(i+1);
        if (next >= lastC) Cat[next] = i, lastC = next;
        else break;
    }
    unsigned int N;
    while (cin >> N) {
        printf("%d\n", Cat[N]);
    }
    return 0;
}
