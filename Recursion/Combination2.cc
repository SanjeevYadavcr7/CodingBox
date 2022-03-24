#include<bits/stdc++.h>
using namespace std;

void combine(int cb, int tb, int usf, int ti, string psf){
	if(cb >= tb || usf == ti){
		if(usf == ti) cout << psf << "\n";
		return;
	}
	
	for(int nb=cb+1; nb<tb; nb++){
		psf[nb] = 'i';
		combine(nb,tb,usf+1,ti,psf);
		psf[nb] = '-';
	}
}

void getCombinations(int n, int r){
	string str(n,'-');
	combine(-1,n,0,r,str);
}

int main(){	
	int n,r;
	cin >> n >> r;
	
	getCombinations(n,r);
	
	return 0;
} 
