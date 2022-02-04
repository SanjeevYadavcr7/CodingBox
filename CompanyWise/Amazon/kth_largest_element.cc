#include<bits/stdc++.h>
using namespace std;

vector<int> kthLargest(vector<int>& arr, int n, int k){
    priority_queue<int, vector<int>, greater<int>> pq;
    int i = 0;
    vector<int> ans;
    while(i<k-1){
        pq.push(arr[i]);
        ans.push_back(-1);
        i++;
    }
    pq.push(arr[i]);
    ans.push_back(pq.top());
    i++;
    for(;i<n;i++){
        pq.push(arr[i]);
        pq.pop();
        ans.push_back(pq.top());
    }    
    return ans;
}

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> arr(n,0);
    for(int i=0; i<n; i++) cin >> arr[i];

    vector<int> ans = kthLargest(arr,n,k);
    for(int i:ans) cout << i << " ";
    cout << "\n";

    return 0;
}