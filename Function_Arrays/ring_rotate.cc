#include<iostream>
using namespace std;

void ringRotate(int** arr, int n, int m, int s, int r){
	int beg_r = s-1, beg_c = s-1;
	int end_r = n-s, end_c = m-s;
	
	int inner_ring_elements = (end_r-beg_r-1) * (end_c-beg_c-1);
	int ring_elements = (end_r-beg_r+1)*(end_c-beg_c+1) - inner_ring_elements;
	
	if(r == 0 || r % ring_elements == 0){
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++) cout<<arr[i][j]<<" ";
			cout<<"\n";
		}
		return;
	}
	r = r % ring_elements;
	if(r<0) r += ring_elements;
	int min_r = s-1, min_c = s-1, max_r = n-s, max_c = m-s;
	while(r--){
		int min_r = s-1, min_c = s-1, max_r = n-s, max_c = m-s;
		int temp, num = arr[min_r][min_c+1];
		for(int i=min_r, j=min_c; i<=max_r; i++){
			temp = arr[i][j];
			arr[i][j] = num;
			num = temp;					
		}
		min_c++;
		for(int i=max_r, j=min_c; j<=max_c; j++){
			temp = arr[i][j];
			arr[i][j] = num;
			num = temp;		
		}		
		max_r--;		
		for(int i=max_r, j=max_c; i>=min_r; i--){
			temp = arr[i][j];
			arr[i][j] = num;
			num = temp;
		}	
		max_c--;
		for(int i=min_r, j=max_c; j>=min_c; j--){
			temp = arr[i][j];
			arr[i][j] = num;
			num = temp;
		}	
			
	}
	
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++) cout<<arr[i][j]<<" ";
			cout<<"\n";
		}


}

int main(){
	int n,m;
	cin>>n>>m;	
	int** arr = new int*[n];
	for(int i=0;i<n;i++) arr[i] = new int[m];

	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++) cin>>arr[i][j];
	
	int s,r;
	cin>>s>>r;
	
	ringRotate(arr, n, m, s, r);
	
	return 0;
}
