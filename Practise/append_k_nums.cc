#include<bits/stdc++.h>
using namespace std;
 
long long minimalKSum(vector<int>& nums, int k){
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int &i : nums) pq.push(i);

    long long ans = 0;
    int i = 1;
    while(k>0 && !pq.empty()){
        int num = pq.top();
        if(num == i){
            i++;
            pq.pop();
        }
        else{
            ans += i;
            i++;
            k--;
        }
    }
    while(k--){
        ans += i;
        i++;
    }
    return ans;
}

int main(){
    int n,k; 
    cin >> n;
    vector<int> arr(n,0);
    for(int i=0; i<n; i++) cin >> arr[i];
    cin >> k;

    long long ans = minimalKSum(arr,k);
    cout << ans << "\n";

    return 0;
}