#include<iostream>
using namespace std;

void printPattern(int n){

    int j=0;
    for(int i=0;i<=n/2;i++){
        for(int spaces=0;spaces<n/2-i;spaces++) cout<<"  ";
        cout<<"* ";
        for(int spaces=0;spaces<2*(i-1)+1;spaces++) cout<<"  ";
        if(i>0)cout<<"*\n";
        else cout<<"\n";
        j++;
    }
    for(int i=0;i<n/2;i++){
        for(int spaces=0;spaces<=i;spaces++) cout<<"  ";
        cout<<"* ";
        for(int spaces=0;spaces<n-2*(i+2);spaces++) cout<<"  ";
        if(i+j+1 != n) cout<<"*\n";
        else cout<<"\n";
    }

}


int main(){

    int n;
    cout<<"Enter number of rows = ";
    cin>>n;

    printPattern(n);

    return 0;
}