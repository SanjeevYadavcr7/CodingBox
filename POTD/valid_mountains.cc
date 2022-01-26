#include<bits/stdc++.h>
using namespace std;

bool isIncLeft(vector<int>& arr,int idx){
	for(int i=1; i<=idx; i++){
		if(arr[i] > arr[i-1]) continue;
		else return false;
	}
	return true;
}

bool isDecRight(vector<int>& arr,int idx){
	for(int i=idx; i<arr.size()-1; i++){
		if(arr[i] > arr[i+1]) continue;
		else return false;
	}
	return true;
}

bool validMountainArray(vector<int>& arr){
	int n = arr.size();
	if(n < 3) return false;
	
	int i = 1;
	while(i<n && arr[i-1] < arr[i]) i++;
	if(i == 1) return false;
	
	while(i<n && arr[i-1] > arr[i]) i++;
	
	if(i == n) return true;
	/*
	for(int i=1; i<n-1; i++){
		if(isIncLeft(arr,i) && isDecRight(arr,i)){
			cout << i << "\n";
			return true;
		} 
	}
	*/
	return false;
}

int main(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0; i<n; i++) cin >> arr[i];
	
	if(validMountainArray(arr)) cout << "true";
	else cout << "false";
	cout << "\n";

	return 0;
}
