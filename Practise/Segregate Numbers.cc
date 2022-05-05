#include<bits/stdc++.h>
using namespace std;

// Using Merge Sort
void mergeHalves(int l, int m, int r, vector<int>& arr) {
	int i,j,k;
	int n1 = m-l+1;
	int n2 = r-m;
	vector<int> temp1(n1), temp2(n2);
	
	for(int i=0; i<n1; i++) temp1[i] = arr[l+i];
	for(int j=0; j<n2; j++) temp2[j] = arr[j+m+1];
	
	i = j = 0, k = l;	
	while(i < n1 && temp1[i] < 0) arr[k++] = temp1[i++];
	while(j < n2 && temp2[j] < 0) arr[k++] = temp2[j++];
	
	while(i<n1) arr[k++] = temp1[i++];
	while(j<n2) arr[k++] = temp2[j++];
}

void breakIntoHalves(int l, int r, vector<int>& arr) {
	if(l<r) {
		int m = l + (r-l)/2;
		breakIntoHalves(l,m,arr);
		breakIntoHalves(m+1,r,arr);
		mergeHalves(l,m,r,arr);
	}
}

void segregate(vector<int>& arr) {
	breakIntoHalves(0,arr.size()-1,arr);
}

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0; i<n; i++) cin >> arr[i];
	
	segregate(arr);
	for_each(arr.begin(), arr.end(), [](int x){cout << x << " ";});
	cout << endl;

	return 0;
}
