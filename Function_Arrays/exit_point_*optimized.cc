#include<iostream>
using namespace std;

void findExitPoint(int** arr, int n, int m){
	
	int dir = 0;
	while(true){
		dir = (dir + arr[i][j])%4;
		if(dir == 0) j++;   // east
		else if(dir == 1) i++;  // south 
		else if(dir == 2) j--;  // west
		else i--;  // north
		
		if(i<0){
			i++;
			break;
		}
		else if(j<0){
			j++;
			break;
		}
		else if(i == n){
			i--;
			break;
		}
		else if(j == m){
			j--;
			break;
		}
	}	
	cout<<i<<"\n"<<j;	
}
	
	
int main(){
	int n,m;
	cin>>n>>m;	
	int** arr = new int*[n];
	for(int i=0;i<n;i++) arr[i] = new int[m];

	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++) cin>>arr[i][j];
	
	findExitPoint(arr, n, m);

	return 0;
}
