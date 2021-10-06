#include <iostream>
#include <vector>
using namespace std;

/*
vector<int> allIndex(vector<int>& arr, int idx, int data, int count){	
	vector<int> ans;
	if(idx == arr.size()) return ans;
	if(arr[idx] == data) ans.push_back(idx);
	vector<int> temp = allIndex(arr, idx+1, data, count);
	if(temp.size() > 0){
		for(int i: temp) ans.push_back(i);
	}
	return ans;
}
*/

vector<int> allIndex(vector<int>& arr, int idx, int data, int count){
	
	if(idx == arr.size()){
		vector<int> temp(count);	
		return temp;
	}   
	if(arr[idx] == data){
		vector<int> ans = allIndex(arr, idx+1, data, count+1);
		ans[count] = idx;
		return ans;
	}
	else{
		vector<int> ans = allIndex(arr, idx+1, data, count);
		return ans;
	}
}
	

int main() {
  int n ;
  cin >> n;
  vector<int> arr;
  for (int i = 0; i < n; i++) {
    int d;
    cin >> d;
    arr.push_back(d);
  }
  int data;
  cin >> data;
  vector<int> ans = allIndex(arr, 0, data, 0);
  if (ans.size() == 0) {
    cout << endl;
    return 0;
  }
  for (int ele : ans) cout << ele << endl;

  return 0;
}
