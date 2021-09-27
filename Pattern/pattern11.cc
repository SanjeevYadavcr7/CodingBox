#include<iostream>
using namespace std;

void printNumPattern(int n){
    int cnt=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++) cout<<cnt++<<" ";
        cout<<"\n";
    }
}

int main(){
    
    int n;
    cout<<"Enter number of rows = ";
    cin>>n;

    printNumPattern(n);
    return 0;

}