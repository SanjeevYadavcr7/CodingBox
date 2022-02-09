#include<bits/stdc++.h>
using namespace std;

int getSetBits(int num){
   	int cnt = 0;
    while(num > 0){
       	cnt += (num & 1);
    	num >>= 1; 
    }
	return cnt;
}
 
bool cmp(pair<int,int> a, pair<int,int> b){
	return a.second > b.second;
}
   
void sortBySetBitCount(int arr[], int n){
	map<int,int> bit_map;
    for(int i=0; i<n; i++){
    	int set_bits = getSetBits(arr[i]);
        bit_map[arr[i]] = set_bits;
    }
    
    vector<pair<int,int>> sorted;
    for(auto it:bit_map) sorted.push_back(it);
    sort(sorted.begin(), sorted.end(), cmp);
	
	for(auto it : sorted) cout << it.first << " ";
    cout << "\n";
}

int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i=0; i<n; i++) cin >> arr[i];
	
	sortBySetBitCount(arr,n);

	return 0;
}
