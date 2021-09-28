#include<iostream>
using namespace std;

void findExitPoint(int** arr, int n, int m){
	
	int row = 0, col = -1, min_row = 0, min_col = 0, max_row = n-1, max_col = m-1;
	bool exit = false;
	string direction = "right";

	while(!exit){
		if(direction == "right"){
			col++;
			while(col<=max_col){
				if(arr[row][col] == 0){ 
					col++;
					if(col>max_col){
						col--;
						exit = true;
						break;
					}
				}
				else{
					direction = "down";
					break;
				}	
			}
		}
		else if(direction == "down"){
			row++;
			while(row<=max_row){
				if(arr[row][col] == 0){
					row++;
					if(row>max_row){
						row--;
						exit = true;
						break;
					} 
				} 
				else{
					direction = "left";
					break;
				}
			}
		}
		else if(direction == "left"){
			while(col>=0){
				col--;
				if(arr[row][col] == 0){
					if(col<0){
						col++;
						exit = true;
						break;
					}	
				}
				else{
					direction = "top";
					break;
				}
			}
		}
		else if(direction == "top"){
			while(row>=0){
				row--;
				if(arr[row][col] == 0){
					if(row<0){
						row++;
						exit = true;
						break;
					}	
				}
				else{
					direction = "right";
					break;
				}
			}
		}
	}
	cout<<row<<"\n"<<col<<"\n";
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
