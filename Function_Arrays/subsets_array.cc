#include<iostream>
#include<string>
using namespace std;

void printSubsets(int* arr, int n){
	int subsets = 1<<n;
	for(int i=0;i<subsets;i++){
		int temp = i;
		string ans ="";
		for(int j=n-1;j>=0;j--){
			int rem = temp % 2;
			temp /= 2;
			if(rem == 0) ans = "-\t"+ans;
			else ans = to_string(arr[j])+"\t" + ans;
		}
		cout<<ans<<"\n";
	}
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	printSubsets(arr, n);
	return 0;
}
