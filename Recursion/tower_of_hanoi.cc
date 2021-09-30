#include<iostream>
using namespace std;

void toh(int n, int s, int d, int t){
    if(n == 1){
    	cout<<n<<"["<<s<<"->"<<d<<"]\n";
    	return;
    }
    toh(n-1, s, t, d);
    cout<<n<<"["<<s<<"->"<<d<<"]\n";
    toh(n-1, d, s, t);
}

int  main() {
    int n;
    cin >> n;
    int n1,n2,n3;
    cin >> n1 >> n2 >> n3;
    toh(n, n1, n2, n3);
  	return 0;
  }
