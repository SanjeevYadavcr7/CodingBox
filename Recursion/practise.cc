#include<bits/stdc++.h>
using namespace std;

int main(){
	vector<string> str = {"anjeev", "anju"};
	string name = "Sanjeev";
	cout<<"Preprocessing...\n";
	
	for(string i:str) cout<<i<<", ";
	cout<<"\n";
	
	cout<<"\nProcessing...\n";
	int n = str.size();
	for(int i=0;i<n;i++){
		cout<<"i = "<<str[i]<<" || ";
		string str3 = name[0] + str[i];
		cout<<"str3 = "<<str3<<"\n";
		str.push_back(str3);
	} 
	
	
	cout<<"\n";
	cout<<"Postprocessing...\n";
	for(string i:str) cout<<i<<", ";
	cout<<"\n";
	
	return 0;
}
