#include<bits/stdc++.h>
using namespace std;

int fabonacci(int n){
    if(n < 0) return 0;
    if(n == 0 || n == 1){
        cout << n << " ";
        return n;
    }
    
    int c = fabonacci(n-1) + fabonacci(n-2);
    cout << c << " ";
    return c;
} 

int main(){
    int n; 
    cin >> n;
    
    fabonacci(n);
    
    return 0;
}