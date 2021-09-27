#include<iostream>
using namespace std;

void printPattern(int n){
    for(int i=0;i<=n/2;i++){
        for(int ls=0;ls<n/2-i;ls++) cout<<"  ";
        for(int st=1;st<=2*i+1;st++) cout<<"* ";
        cout<<"\n";
    }

    for(int i=0;i<n/2;i++){
        for(int ls=0;ls<=i;ls++) cout<<"  ";
        for(int st=0;st<n+(i+1)*(-2);st++) cout<<"* ";
        cout<<"\n";
    }
}

int main(){

    int n;
    cout<<"Enter no. of rows = ";
    cin>>n;
    printPattern(n);
    return 0;
}