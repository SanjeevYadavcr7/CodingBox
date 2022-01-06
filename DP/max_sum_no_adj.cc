#include<bits/stdc++.h>
using namespace std;

int getMaxSum(int arr[], int n){
    int ex = 0, in = 0;
    for(int i=0;i<n;i++){
        int temp = ex + arr[i];
        ex = max(in,ex);
        in = temp;
    }
    int ans = max(in,ex);
    return ans;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];

    int ans = getMaxSum(arr,n);
    cout<<ans<<"\n";

    return 0;
}