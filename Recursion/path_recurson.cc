#include<iostream>
#include<vector>
using namespace std;

vector<string> getStairPaths(int n){
	if(n == 0){
		vector<string> ans{{""}};
		return ans;
	} 	
	else if(n<0){
		vector<string> ans;
		return ans;
	}
	
	vector<string> paths1 = getStairPaths(n-1);
	vector<string> paths2 = getStairPaths(n-2);
	vector<string> paths3 = getStairPaths(n-3);
	
	vector<string> final_paths;
	for(string i : paths1){
		string str = "1"+i;
		final_paths.push_back(str);
	}
	
	for(string i : paths2){
		string str = "2"+i;
		final_paths.push_back(str);
	}
	
	for(string i : paths3){
		string str = "3"+i;
		final_paths.push_back(str);
	}
	return final_paths;
}

int main(){
	int n, cnt=0;
	cin>>n;
	vector<string> arr = getStairPaths(n);
	cout<<"[";
	n = arr.size();
	for(string i : arr){
		cout<<i;
		if(cnt != n-1) cout<<", ";
		cnt++;
	} 
	cout<<"]";
	return 0;
}
