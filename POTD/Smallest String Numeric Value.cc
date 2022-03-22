#include<bits/stdc++.h>
using namespace std;

string getSmallestString(int n, int k){
	string arr(n,'0');
	int idx = n-1;
	while(k > 0){
    	int left = k - (n-1);
        if(left >= 26){
        	arr[idx--] = 'z';
            k -= 26;
        }
        else{
        	char temp = ('a'+(left-1));
            arr[idx--] = temp;
            k = n-1;	
        }
        n--;
	}
    return arr;
}

int main(){
	int n,k;
	cin >> n >> k;
	string str = getSmallestString(n,k);
	cout << str << "\n";	
	
	return 0;
}
