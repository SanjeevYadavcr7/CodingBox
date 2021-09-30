#include<iostream>
using namespace std;


void pzz(int n){
    if(n == 1){
    	cout<<111;
    	return;
    }
    cout<<n;
    pzz(n-1);
    cout<<n;
    pzz(n-1);
    cout<<n;
}



int main(){
    int n; cin>>n;
    pzz(n);
    cout<<endl;
    return 0;
}

