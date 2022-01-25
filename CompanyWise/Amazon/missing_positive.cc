#include<bits/stdc++.h>
using namespace std;

int firstMissingPositive(vector<int>& nums) {
    int max_num = *max_element(nums.begin(),nums.end());
    cout << max_num << "\n";

    return 0;  
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];

    int ans = firstMissingPositive(arr);
    cout << ans << "\n";

    return 0;
}