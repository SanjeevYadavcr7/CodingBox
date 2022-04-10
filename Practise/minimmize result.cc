#include<bits/stdc++.h>
using namespace std;

struct customPair{
	int mul;
	int rem;
	customPair(int _mul, int _rem){
		mul = _mul;
		rem = _rem;
	}
};

int getPivot(string str){
	int n = str.size();
	for(int i=0; i<n; i++){
		if(str[i] == '+') return i;
	}
	return -1;
}

vector<customPair*> getLeftNumbers(string str, int pivot){
	int k = pivot;
	int left_num = stoi(str.substr(0,pivot));
	vector<customPair*> left;
	
	while(k){
		int mul = left_num / pow(10,k);
		int rem = left_num % (int)pow(10,k);
		left.push_back(new customPair(mul,rem));
		k--;
	}	
	return left;
}

vector<customPair*> getRightNumber(string str, int pivot){
	int k = str.size() - pivot - 1;
	int right_num = stoi(str.substr(pivot+1));
	vector<customPair*> right;
	int i = 0;
	while(i<k){
		int mul = right_num % (int)pow(10,i);
		int rem = right_num / pow(10,i);
		right.push_back(new customPair(mul,rem));
		i++;
	}
	return right;
}

string minimizeResult(string str){
	int n = str.size();
	int pivot;
	int min_val = INT_MAX;
	string res = str;
	
	pivot = getPivot(str);
	vector<customPair*> left,right;
	
	left = getLeftNumbers(str,pivot);
	right = getRightNumber(str,pivot);
	
	for(auto i : left){
		for(auto j : right){
			int a = (i->mul == 0) ? 1 : i->mul;
			int d = (j->mul == 0) ? 1 : j->mul;
			int b = i->rem;
			int c = j->rem;
			int exp_val = a*(b+c)*d;
			if(exp_val < min_val){
				min_val = exp_val;
				res = ((i->mul == 0) ? "" : to_string(a)) + "(" + to_string(b) + "+" + to_string(c) + ")" + ((j->mul == 0) ? "" : to_string(d));
			}
		}
	}
	
	return res;
}

int main(){
	string str;
	cin >> str;
	
	string min_num = minimizeResult(str);
	cout << "Min = " << min_num << "\n";
	
	return 0;
}
