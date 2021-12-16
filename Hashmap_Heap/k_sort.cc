#include <bits/stdc++.h>
using namespace std;

void sortK(int arr[], int n, int k) {
	priority_queue<int, vector<int>, greater<int>> pq;
	int i=0;
	for(;i<n;i++){
		if(i<=k){
			int num = arr[i];
			pq.push(num);
		}
		else{
			int min_num = pq.top();
			pq.pop();
			int min_num_index = i-k-1;
			arr[min_num_index] = min_num;
			int curr_num = arr[i];
			pq.push(curr_num);
		}
	}
	while(!pq.empty()){
		int min_num = pq.top();
		int min_num_index = i-k-1;
		arr[min_num_index] = min_num;
		i++;
		pq.pop();
	}
	//cout<<"Sorted[] = ";
	for(int i=0;i<n;i++) cout<<arr[i]<<"\n";
}

int main()
{
 	int n;
 	cin >> n;
 	int arr[n];
 	for (int i = 0 ; i < n ; i++) {
    	int data;
    	cin >> data;
    	arr[i] = data;
  	}
  	int k;
  	cin >> k;
 	sortK(arr, n, k);
 	return 0;
}
