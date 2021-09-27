#include<iostream>
using namespace std;

void printPattern(int n){
    for(int i=0;i<n;i++){
        for(int spaces=0;spaces<n-i-1;spaces++) cout<<"  ";
        cout<<"*\n";
    }
}
 

int main(){

    int n;
    cout<<"Enter number of rows = ";
    cin>>n;
    printPattern(n);

    return 0;
}