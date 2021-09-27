#include<iostream>
using namespace std;

void printPattern(int n){
    for(int i=0;i<n;i++){
        for(int j=n-i;j>0;j--){
            cout<<"* ";
        }
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