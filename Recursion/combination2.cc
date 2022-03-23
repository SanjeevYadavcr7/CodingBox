#include<bits/stdc++.h>
using namespace std;

void combine(int cb, int tb, int usf, int ti, string psf){
	if(cb > tb){
		if(usf == ti) cout << psf << "\n";
		return;
	}
	
	combine(cb+1,tb,usf+1,ti,psf+"i");
	combine(cb+1,tb,usf,ti,psf+"-");
}

void getCombinations(int boxes, int items){
	combine(1,boxes,0,items,"");
}

int main(){
	int n,r;
	cin >> n >> r;
	getCombinations(n,r);
	return 0;
}
