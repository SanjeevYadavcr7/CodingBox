#include<bits/stdc++.h>
using namespace std;

bool sortByVal(pair<int,int>& a, pair<int,int>& b){
	return a.first < b.first;
}

int minSwaps(vector<int> &arr){
	int n = arr.size(), swaps = 0;
	vector<bool> vis(n);
	vector<pair<int,int>> temp;
	
	for(int i=0; i<n; i++) temp.push_back({arr[i],i});
	sort(temp.begin(),temp.end(),sortByVal);
	
	for(int i=0; i<n; i++){
		if(vis[i] || temp[i].second == i) continue;
		int clen = 0, j = i;
		while(!vis[j]){
			vis[j] = true;
			clen++;
			j = temp[j].second;
		}
		swaps += (clen-1);
	}	
	return swaps;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    
    cout<<minSwaps(arr)<<"\n";
    
    return 0;
}
