#include<bits/stdc++.h>
using namespace std;

int firstMissingPositive(vector<int>& arr) {
	int i, n = arr.size();
	for(int i=0; i<n; i++){
		while((arr[i] >= 1 && arr[i] <= n) && arr[i] != arr[arr[i]-1]){
			swap(arr[i], arr[arr[i]-1]);
		}
	}
	
	for(i=0;i<n;i++){
		if(arr[i] != i+1) return i+1;
	}
	return i+1;
}

int main(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0; i<n; i++) cin >> arr[i];
		
	int num = firstMissingPositive(arr);
	cout << num << "\n";		

	return 0;
}
