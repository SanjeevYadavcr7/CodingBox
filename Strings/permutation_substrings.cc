#include<iostream>
using namespace std;

int factorial(int n){
	if(n == 0) return 1;
	return n*factorial(n-1);
}

void printAllPerutations(string str){
	int n = str.length();
	int total_per = factorial(n);
	for(int i=0;i<total_per;i++){
		int index = i, rem;
		string temp = str, ans = "";
		for(int j=n;j>0;j--){
			rem = index%j;
			index = index/j;
			ans = ans+temp[rem];
			temp.erase(rem, 1);
		}
		cout<<ans<<endl;
	}
}

int main(){
	string str;
	cin>>str;
	printAllPerutations(str);
	return 0;
}
