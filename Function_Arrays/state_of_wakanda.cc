#include<iostream>
using namespace std;

void printPath(int **arr, int n, int m){
	int visited = 0, total_places = n*m;
	int direction = -1;
	int row = -1, col = 0;
	while(visited != total_places){	
		if(direction == -1){
			row++;
			while(row<n){
				cout<<arr[row][col]<<"\n";
				row++;
				visited++;
			}
			direction = 1;
			col++;
		}
		else{
			row--;
			while(row >= 0){
				cout<<arr[row][col]<<"\n";
				row--;
				visited++;
			}
			direction = -1;
			col++;
		}
	}
}



int main(){
	int n,m;
	cin>>n>>m;
	int** path = new int*[n];
	for(int i=0;i<n;i++) path[i] = new int[m];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++) cin>>path[i][j];
	
	printPath(path,n,m);

	return 0;
}
