#include<bits/stdc++.h>
using namespace std;

vector<int> data;

int size() {
	return data.size();
}

void upheapify(){
	int i = data.size()-1;
	int par = (i-1)/2;
	while(par >= 0 && data[par] > data[i]){
		swap(data[par],data[i]);
		i = par;
		par = (i-1)/2;
	}
}

void downheapify(){
	int n = data.size();
	swap(data[0],data[n-1]);
	data.pop_back();
	n = data.size();
	if(n<=1) return;
	int par = 0;
	int l = 2*par+1;
	int r = 2*par+2;
	int child;
	if(data[l] <= data[par]) child = l;
	if(r<n && data[l] > data[r]) child = r;
	
	while(par < child && data[par] > data[child]){
		swap(data[par],data[child]);
		par = child;
		l = 2*par+1;
		r = 2*par+2;
		if(r<n || l<n){
			if(data[l] <= data[par]) child = l;
			if(r<n && data[l] > data[r]) child = r;
		}
	}
}

void add(int val) {
	data.push_back(val);
	upheapify();
	//cout<<"Heap[] = ";
	//for(int &i : data) cout<<i<<" ";
	//cout<<endl;
}

int remove() {
	if(size() == 0){
		cout<<"Underflow\n";
		return -1;
	}	
	int erased_val = data[0];
	downheapify();
	
	cout<<"Heap[] = ";
	for(int &i : data) cout<<i<<" ";
	cout<<endl;
	return erased_val;
}

int peek() {
	int min_val = data[0];
	return min_val;
}



int main(){

	string str;
	cin>>str;
	while(str != "quit"){
		if(str == "add"){
			int val;
			cin>>val;
			add(val);
		}
		else if(str == "remove"){
			int val = remove();
			if(val != -1) cout<<val<<"\n";
		} 
		else if(str == "peek") cout<<peek()<<"\n";
		else if(str == "size") cout<<size()<<"\n";
		cin>>str;
	}

	return 0;
}
