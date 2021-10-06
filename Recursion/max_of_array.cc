#include <iostream>
using namespace std;

int max(int arr[], int idx, int n){
    int max_num = -1;
    if(idx == n) return -1;
    max_num = max(arr, idx+1, n);
    max_num = (max_num > arr[idx]) ? max_num : arr[idx];
    return max_num;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    int p = max(arr, 0, n);
    cout << p << endl;
    return 0;
}

