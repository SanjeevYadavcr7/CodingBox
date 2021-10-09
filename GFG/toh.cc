#include<iostream>
using namespace std;



long long toh(int N, int from, int to, int aux) {
	int cnt = 0;
	if(N == 0){
		return 0;
	}
	cnt += toh(N-1, from, aux, to);
	cout<<"move disk "<<N<<" from rod "<<from<<" to rod "<<to<<"\n";
	cnt++;
	cnt += toh(N-1, aux, to, from);
	return cnt;
}
    
int main(){
	int n;
	cin>>n;
	int n_steps = toh(n,1,3,2);
	cout<<n_steps<<endl;
	return 0;
}
