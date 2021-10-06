#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int arr[3], d;
		for(int i=0;i<3;i++) cin>>arr[i];
		cin>>d;
		sort(arr, arr+3);
		int sum = 0, ans = 1;
		for(int i=0;i<3;i++){
			sum += arr[i];
			if(sum > d) ans += 1;
		}
		cout<<ans<<"\n";
	}

	return 0;
}
