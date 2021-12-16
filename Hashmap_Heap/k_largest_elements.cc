#include <bits/stdc++.h>
using namespace std;

/*
int findKthLargest(vector<int> const& arr, int k) {
	
	priority_queue<int> pq;
	int n = arr.size();
	for(int i=0;i<n;i++){
		int num = arr[i];
		pq.push(num);
	}
	while(k>1){
		//cout<<"Popping "<<pq.top()<<"\n";
		pq.pop();
		k--;
	} 
	return pq.top();
}
*/

void findKLargestElement(vector<int>& arr, int k){
	priority_queue<int, vector<int>, greater<int>> pq;
	int n = arr.size();
	for(int i=0;i<n;i++){
		int curr_num = arr[i];
		if(i<k) pq.push(curr_num);
		else{
			int min_num = pq.top();
			if(curr_num > min_num){
				pq.pop();
				pq.push(curr_num);
			} 
		}
	}
	
	while(!pq.empty()){
		cout<<pq.top()<<" ";
		pq.pop();
	}
}


int main()
{
  vector<int>arr;
  int n;
  cin >> n;
  for (int i = 0 ; i < n; i++) {
    int data;
    cin >> data;
    arr.push_back(data);
  }
  int k;
  cin >> k;
  findKLargestElement(arr,k);
  /*
  for (int i = k; i > 0; i--)
    cout << findKthLargest(arr, i) << endl;
  */
  return 0;

}
