#include<iostream>
using namespace std;

void printSpiral(int** arr, int n, int m){
	int min_row = 0, min_col = 0;
	int max_row = n-1, max_col = m-1;
	
	// down --> right --> top --> left -->repeat 
	
	int visited = 0, total_places = n*m;
	while(visited != total_places){
			for(int i=min_row, j=min_col; i<=max_row && visited < total_places ; i++){
				cout<<arr[i][j]<<"\n";
				visited++;
			} 
			min_col++;
			
			for(int i=max_row, j=min_col;j<=max_col && visited < total_places ; j++){ 
				cout<<arr[i][j]<<"\n";
				visited++;
			}
			max_row--;
			
			for(int i=max_row, j=max_col;i>=min_row && visited < total_places ;i--){ 
				cout<<arr[i][j]<<"\n";
				visited++;
			}
			max_col--;
			
			for(int i=min_row, j=max_col; j>= min_col && visited < total_places; j--){
			 	cout<<arr[i][j]<<"\n";
				visited++;
			}
			min_row++;	
	}
}

int main(){
	int n,m;
	cin>>n>>m;
	int** arr = new int*[n];
	for(int i=0;i<n;i++) arr[i] = new int[m];

	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++) cin>>arr[i][j];
	
	printSpiral(arr, n, m);
	
	return 0;
}


/*
 void printSpiral(int** arr, int n, int m){
	int visited = 0, total_nums = n*m;
	string direction = "down";
	int row = 0, col = 0;
	int beg = 0;
	while(visited != total_nums){
		if(direction == "down"){
			while(row<n-beg){
				cout<<arr[row][col]<<"\n";
				row++;
				visited++;
			}
			direction = "right";
			col++;
			row--;
		}
		else if(direction == "right"){
			while(col<m){
				cout<<arr[row][col]<<"\n";
				col++;
				visited++;
			}
			direction="top";
			row--;
			col--;
		}
		else if(direction == "top"){
			while(row>=beg){
				cout<<arr[row][col]<<"\n";
				row--;
				visited++;
			}
			direction="left";
			row++;
			col--;
			m--;
		}
		else if(direction == "left") {
			beg++;
			while(col>=beg){
				cout<<arr[row][col]<<"\n";
				col--;
				visited++;	
			}
			col++;
			row++;
			direction = "down";
		}
	}
}
*/

