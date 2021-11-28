#include<bits/stdc++.h>
using namespace std;

bool customComparator(pair<int,int> x, pair<int,int> y){
	if(x.first != y.first) return (x.first < y.first); 
	else return (x.second > y.second);
}

int main(){	
	
	vector<pair<int,int>> v;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		v.push_back({x,y});
	}
	
	cout<<"V[] = ";
	for(pair<int,int> i : v){
		cout<<"["<<i.first<<"]->"<<i.second<<" | ";
	}
	cout<<endl;
	
	sort(v.begin(), v.end(), customComparator);
	cout<<"\nV[] = ";
	for(pair<int,int> i : v){
		cout<<"["<<i.first<<"]->"<<i.second<<" | ";
	}
	cout<<endl;
		
	
	return 0;
}

