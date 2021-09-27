#include<iostream>
using namespace std;

void printPattern(int n){
    for(int i=0;i<=n/2;i++){
        for(int lst=i;lst<=n/2;lst++)cout<<"* ";
        for(int sp=0;sp<2*i+1;sp++)cout<<"  ";
        for(int rst=i;rst<=n/2;rst++)cout<<"* ";
        cout<<"\n";
    }

    for(int i=0;i<n/2;i++){
        for(int ls=0;ls<=i+1;ls++) cout<<"* ";
        for(int st=0;st<n+(i+1)*(-2);st++) cout<<"  ";
        for(int ls=0;ls<=i+1;ls++) cout<<"* ";
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