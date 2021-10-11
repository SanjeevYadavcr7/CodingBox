#include<iostream>
#include<math.h>
using namespace std;


int digitIndex(int n,int d){
	int res = -1;
	while(n != 0){
		int rem = n%10;
		if(rem == d) return 1;
		n /= 10;
	}
	return res;
}


int solve(int n, int d){
	int temp = n, cnt=0, ans=0;
	while(temp != 0){
		int rem = temp%10;
		temp /= 10;
		cnt++;
		if(rem == d){
			temp = temp*pow(10,cnt) + (rem+1)*pow(10,cnt-1);
			ans = temp-n;
			cnt = 0;
		}
	}
	return ans;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		// cout<<"N = "<<n<<" || D ="<<d<<endl;
		int ans = solve(n,d);
		cout<<ans<<"\n";
	}

	return 0;
}
