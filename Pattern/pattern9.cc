#include<iostream>
using namespace std;

void printPattern(int n){

    for(int i=0;i<n/2;i++){
        for(int spaces=0;spaces<i;spaces++) cout<<"\t";
        cout<<"*\t";
        for(int spaces=0;spaces<n-2*(i+1);spaces++)cout<<"\t";
        cout<<"*\n";
    }
    for(int spaces=0;spaces<n/2;spaces++) cout<<"\t";
    cout<<"*\n";
    for(int i=0;i<n/2;i++){
        for(int spaces=0;spaces<n/2-i-1;spaces++) cout<<"\t";
        cout<<"*\t";
        for(int spaces=0;spaces<2*i+1;spaces++)cout<<"\t";
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