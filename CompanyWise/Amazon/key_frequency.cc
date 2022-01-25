#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr, int k){ 
    auto it1 = lower_bound(arr.begin(), arr.end(), k);
    auto it2 = upper_bound(arr.begin(), arr.end(), k);
    int freq = (*it1 == 0) ? (it2 - it1) : (it2 - it1 );
    return freq;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];

    int freq = solve(arr,k);
    cout << freq << "\n";

    return 0;
}