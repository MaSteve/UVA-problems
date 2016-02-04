// las12uvas contest PROBLEM C 2015
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

int main() {
    int cases;
	cin >>cases;
	long long mat[301][301];
	for (int i = 0; i < cases; i++) {
		bool sim = true;
		int n;
		char trash;
		cin >> trash >> trash;
		cin >> n;
		for(int j = 0; j < n; j++){
			for (int l = 0; l < n; l++)
			{
				cin >> mat[j][l];
				if (mat[j][l]<0) sim = false;	
			}
		}
		for(int j = 0; j < n && sim; j++){
			for (int l = 0; l < n && sim; l++)
			{
				if(mat[j][l] != mat[n-1-j][n-1-l]) {
					sim = false;
				}
			}
		}
		printf("Test #%d: ", i+1);
		if (sim)printf("Symmetric.\n");
		else printf("Non-symmetric.\n");
	}
    return 0;
}