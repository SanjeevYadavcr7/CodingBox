#include<iostream>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		string str;
		cin>>n>>str;
		int arr[n];
		for(int i=0;i<n;i++) cin>>arr[i];
		if(str == "Dee" && n == 1 && arr[0]%2 == 0) cout<<"Dee\n";
		else cout<<"Dum\n";
	}

	return 0;
}

