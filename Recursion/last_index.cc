#include <iostream>
using namespace std;

int lastIndex(int arr[], int idx, int x, int n){
    int found = -1;
    if(idx == n) return found;
	if(arr[idx] == x) found = idx;
	found = max(found, lastIndex(arr, idx+1, x, n));
	return found;
}

int main(){
    int n;
    cin >> n;
    int d;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> d;
    int p = lastIndex(arr, 0, d, n);
    cout << p << endl;
	return 0;
}
