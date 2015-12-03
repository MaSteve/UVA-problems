#include <iostream>
#include <string>

using namespace std;

int views[30];

void proc(int & pos, string & cad){
	char node = cad[pos];
	//cout<<node<<endl;
	int posv = (int) node - 'A';
	if(pos != 0) views[posv]++;
	while(cad[pos+1]!=node){
		pos++;
		proc(pos, cad);
		views[posv]++;
	}
	pos++;
}

int main(){
	int cases;
	cin >> cases;
	for(int i = 0; i<cases; i++){
		string cad;
		cin >> cad;
		//memset(views, 0, 30);
		for(int l = 0; l<30; l++) views[l]=0;
		int pos = 0;
		proc(pos, cad);
		cout << "Case "<<i+1<<endl;
		for(int j = 0; j<30; j++){
			if(views[j]!=0) cout << char ('A'+j) << " = " << views[j] <<endl;
		}
	}
	return 0;
}