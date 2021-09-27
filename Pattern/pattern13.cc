#include<iostream>
#include<vector>
using namespace std;

void printNumPattern(int n){
    
    vector<int> arr;
    arr.push_back(1);
    for(int i=0;i<n;i++){
        
        for(int num: arr) cout<<num<<" ";
        cout<<"\n";
        
        int arr_size = arr.size();
        if(arr_size < 2) arr.push_back(1);
        else{
            int curr, prev=arr[0];
            for(int j=1;j<arr_size;j++){
                curr = arr[j];
                arr[j] = curr + prev;
                prev = curr;
            }
            arr.push_back(1);
        }
    }
}

void printNumPattern2(int n){
    for(int i=0;i<n;i++){
        int val = 1;
        for(int j=0;j<=i;j++){
            cout<<val<<"  ";
            val = (val * (i-j))/(j+1);
        }
        cout<<"\n";
    }
}



int main(){
    int n;
    cout<<"Enter number of rows = ";
    cin>>n;
    printNumPattern2(n);
    return 0;
}