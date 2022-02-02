#include<bits/stdc++.h>
using namespace std;

int findPosition(int N) {
	if(N == 0) return -1;
        int set_bits = 0, i = 0;
        while(N > 0){
            int curr_bit = N & 1;
            if(curr_bit == 1) set_bits++;
            N = N>>1;
            //cout << curr_bit << "| "<< N << "\n";
            i++;
        }
        if(set_bits > 1) return -1;
        return i;
}


int main(){
	int n;
	cin >> n;
	
	int pos = findPosition(n);
	cout << pos << "\n";
	
	return 0;
}
