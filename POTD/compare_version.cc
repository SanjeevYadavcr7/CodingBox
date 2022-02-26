#include<bits/stdc++.h>
using namespace std;

vector<int> getNumArr(string str){
	vector<int> arr;
   	int num = 0;
   	for(char ch : str){
   		if(ch == '.'){
   			arr.push_back(num);
   			num = 0;
   		}
   		else num = num*10 + (ch-'0');
   	}
 	
 	if(num || arr.empty()) arr.push_back(num);
    return arr;
}

void display(vector<int> arr){
	for(int &i : arr) cout << i << " ";
	cout << "\n";
}
  
int compareVersion(string version1, string version2) {
	vector<int> arr1 = getNumArr(version1);
    vector<int> arr2 = getNumArr(version2);
	
	display(arr1);
	display(arr2);
	
	int n = arr1.size(), m = arr2.size();
	int max_len = max(n,m);
	for(int i=0; i<max_len; i++){
		int val1 = (i<n) ? arr1[i] : 0;
		int val2 = (i<m) ? arr2[i] : 0;
	
		if(val1 > val2) return 1;
		if(val1 < val2) return -1;
	}
	
	return 0;
}
    
int main(){
	string ver1, ver2;
	cin >> ver1 >> ver2;
	
	cout << compareVersion(ver1,ver2) << "\n";
	return 0;
}
