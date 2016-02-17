// las12uvas contest PROBLEM D 2015
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <algorithm> // max...
#include <utility> // pair
#include <complex>
#include <climits> // int, ll...
#include <limits> // double...
#include <cmath> // abs, atan...
#include <cstring> // memset
#include <string>
#include <functional> // greater, less...
#include <bitset>
#include <cctype>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef map<int, int> mii;
typedef vector<ii> vii;
typedef vector<dd> vdd;
typedef vector<ll> vll;
typedef vector<vi> vvi;

bool proc(int mat[11][11], int s, int dim, int & sum) {
	if(s > dim/2) return false;
	if( dim % 2 == 0 && s == dim/2) return false;
	sum = 0;
	if(s == dim/2 && dim%2 == 1) {sum = mat[s][s]; return true;}
	for(int i = s; i < dim - s; i++) {sum += mat[i][s] + mat[i][dim-s-1];}
	for(int i = s + 1; i < dim-s-1; i++) {sum += mat[s][i] + mat[dim-s-1][i];}
	return true;
}

int main() {
    int vec[11];
    int mat[11][11];
    int cases = 1;
    int n;
	while (scanf("%d", &n) && n!=0) {
		for (int i = 0; i < 11; i++) vec[i] = 0;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) scanf("%d", &mat[i][j]);

		printf("Case %d:", cases++);
		for (int i = 0; i < n/2 + 1; i++) {	
			int sum;
			bool ok = proc(mat, i, n, sum);
			if (ok) printf(" %d", sum);
		}
		printf("\n");
	}
    return 0;
}