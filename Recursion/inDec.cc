#include<iostream>
using namespace std;

void printIncreasing(int n){
    if(n == 0) return;
    printIncreasing(n-1);
    cout<<n<<"\n";
}

void printDecreasing(int n){
    if(n == 0) return;
    cout<<n<<"\n";
    printDecreasing(n-1);
}


void printIncDec(int n){
    printDecreasing(n);
    printIncreasing(n);
}


int main(){
    int n; cin>>n;
    printIncDec(n);
}

