#include<bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& arr){
	int n = arr.size();
	int i = n-2;
	int pivot;
	
	while(i>=0 && arr[i] >= arr[i+1]) i--;
	if(i == -1){
		reverse(arr.begin(),arr.end());
        return;
	} 
	
	pivot = i;
	int just_next_max = INT_MAX, idx;
	for( ;i<n; i++){
		if(arr[i] > arr[pivot]){
			if(just_next_max >= arr[i]){
				just_next_max = arr[i];
				idx = i;
			}
		}
	}
		
	auto swap = [&](int i, int j){
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	};
	
	swap(pivot,idx);
	reverse(arr.begin()+pivot+1,arr.end());
}

void display(vector<int>& arr){
	for(int& i : arr) cout << i << " ";
	cout << "\n";
}

int main(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0; i<n; i++) cin >> arr[i];
	
	nextPermutation(arr);
	display(arr);

	return 0;
}
