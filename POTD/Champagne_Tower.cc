#include<bits/stdc++.h>
using namespace std;

double champagneTower(int poured, int query_row, int query_glass){
	int n = 101;
	vector<vector<double>> glass(n,vector<double>(n,0.0));
	
	glass[0][0] = poured;
	for(int i=0; i<100; i++){
		for(int j=0; j<=i; j++){
			if(glass[i][j] >= 1){
				glass[i+1][j] += (glass[i][j] - 1) / 2.0;
				glass[i+1][j+1] += (glass[i][j] - 1) / 2.0;
				glass[i][j] = 1;
			}
		}
	}
	return glass[query_row][query_glass];
}

int main(){
	int poured, query_row, query_glass;
	cin >> poured >> query_row >> query_glass;
	
	double champagne = champagneTower(poured,query_row,query_glass);
	cout << champagne << "\n";

	return 0;
}

   
