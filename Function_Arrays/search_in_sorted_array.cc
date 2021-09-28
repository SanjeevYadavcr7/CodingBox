#include<iostream>
using namespace std;

int binarySearch(int** arr, int ri, int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[ri][mid] == x) return mid;
        if (arr[ri][mid] > x) return binarySearch(arr,ri, l, mid - 1, x);
        return binarySearch(arr,ri, mid + 1, r, x);
    }
    return -1;
}
  

void searchSortedArray(int** arr, int n, int x){

	int beg = 0, end = n-1, found = 0;
	int selected_row;
	while(beg<=end){
		int mid = beg+(end-beg)/2;
		if(arr[mid][0] == x){
			found = 1;
			selected_row = mid;
			break;
		}
		else if(arr[mid][0] > x) end = mid-1;
		else beg = mid+1;
	}
	int ans;
	if(!found){
		selected_row = beg-1;
		ans = binarySearch(arr, selected_row, 0, n-1, x);
	} 
	else{
		ans = binarySearch(arr, selected_row, 0, n-1, x);
	}
	if(ans == -1) cout<<"Not found!\n";
	else cout<<selected_row<<"\n"<<ans<<"\n";
	
}

int main(){
	int n;
	cin>>n;
	int** arr = new int*[n];
	for(int i=0;i<n;i++) arr[i] = new int[n];
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++) cin>>arr[i][j];
	
	int search_item;
	cin>>search_item;
	
	searchSortedArray(arr, n, search_item);
		
	return 0;
}
