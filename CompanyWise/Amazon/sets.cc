#include<bits/stdc++.h>
using namespace std;

int minimumGroups(vector<int> &arr, int k){
    int n = arr.size();
    sort(arr.begin(),arr.end());
    int min_idx = 0, cnt = 1;
    for(int i=0; i<n; i++){
        int curr = arr[i];
        if(curr - arr[min_idx] > k){
            min_idx = i;
            cnt += 1;
        }
    }
    return cnt;
}

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];

    int ans = minimumGroups(arr,k);
    cout << ans << "\n";

    return 0;
}