#include<iostream>
using namespace std;

void printNumPattern(int n){

        int prev_prev=0, prev=1;
        for(int i=1;i<=n;i++){
            if(i == 1) cout<<prev_prev;
            else{
                for(int j=1;j<=i;j++){
                    if(i == 2 && j == 1) cout<<prev<<" ";
                    else{
                        int curr = prev_prev+prev; 
                        cout<<curr<<" ";
                        prev_prev = prev;
                        prev = curr;
                    }
                }   
            }
            cout<<"\n";
        }

}

int main(){
    int n;
    cin>>n;
    printNumPattern(n);
    return 0;
}