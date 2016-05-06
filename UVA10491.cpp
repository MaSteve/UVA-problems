#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    double ncows, ncars, nshow; //It's necessary to use double.
    while (cin >> ncows >> ncars >> nshow/*scanf("%f %f %f", &ncows, &ncars, &nshow) != EOF*/) {
        printf("%.5f\n", (ncars*(ncars-1+ncows))/((ncows+ncars)*(ncows+ncars-nshow-1)));
    }
    return 0;
}
