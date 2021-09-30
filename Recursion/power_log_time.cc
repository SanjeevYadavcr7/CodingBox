#include<iostream>
using namespace std;

int powerLogarithmic(int x,int n){
    if(n == 0) return 1;
    int xn = powerLogarithmic(x, n/2) * powerLogarithmic(x, n/2);
    if(n&1) xn *= x;
    return xn;
}

int main(){
    int x,n; cin>>x>>n;
    cout<<powerLogarithmic(x,n);
}
