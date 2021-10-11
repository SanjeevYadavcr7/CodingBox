#include<bits/stdc++.h>
using namespace std;

int findMex(vector<int> a){
	sort(a.begin(), a.end());
	int ans = -1;
	for(int i=0;i<a.size();i++){
		if(a[i] != i){
			ans = i;
			break;
		}
	}
	if(ans == -1) return a.size();
	return ans;
}	

int solve(int arr[], int n, int k){
	
	for(int i=0;i<n;i++){
		vector<int> ans;
		for(int j=i;j<=n;j++){
			ans.push_back(arr[j]);	
		}
		cout<<"arr[] = ";
		for(int i : ans) cout<<i<<" ";
		int mex = findMex(ans);
		cout<<" || Mex = "<<mex<<endl;
	}
	return 0;
}	

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int arr[n];
		for(int i=0;i<n;i++) cin>>arr[i];
		
		int ans = solve(arr, n, k);
		cout<<ans<<endl;		
	}

	return 0;
}
