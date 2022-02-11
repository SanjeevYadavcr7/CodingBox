#include<bits/stdc++.h>
using namespace std;


  int xorCal(int k){
        if(k == 1) return 2;
        if((k & (k + 1)) == 0) return k >> 1;
        return -1;   
    }
    
  int main(){
  	int k;
  	cin >> k;
  	int ans = xorCal(k);
  	cout << ans << "\n";
  	
  	return 0;
  }
