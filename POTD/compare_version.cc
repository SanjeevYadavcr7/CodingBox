#include<bits/stdc++.h>
using namespace std;

int getNum(string num){
	int ans=0, k=0, n=num.size();
	for(int i=n-1; i>=0; i--){
		ans += ((num[i]-'0')*pow(10,k));
		k++;
	}
	return ans;
}

vector<int> getString(string str){
	int n = str.size();
    vector<int> ans;
    string temp = "", num = "";
    
    int i = 0;
    while(str[i] == '0') i++;
    
    for(;i<n;){
     	char ch = str[i];
        if(ch == '.'){
        	num += temp;
        	if(temp == "") ans.push_back(0);
        	else{
        		int x = getNum(temp);
        		ans.push_back(x);
        	}
            temp = "";
            i++;
            while(str[i] == '0')i++;
        }
        else{
        	temp += ch;
            i++;
        }    
	}
    if(temp.size() > 0){
    	num += temp;
    	int x = getNum(temp);
    	ans.push_back(x);
    }
    if(temp == "") ans.push_back(0);
    
    //cout << num << " | ";
     
    return ans;
}
  
int compareVersion(string version1, string version2) {
	vector<int> num1 = getString(version1);
    vector<int> num2 = getString(version2);
	
	/*	
	cout<<"\n";
	for(int i:num1) cout << i << " "; cout<<"\n";
	for(int i:num2) cout << i << " "; cout<<"\n";
	*/
	
	int i=0, j=0, n=num1.size(), m=num2.size();
	while(i<n && j<m){
		if(num1[i] == num2[j]) i++,j++;
		else if(num1[i] > num2[j]) return 1;
		else return -1;
	}
	
	while(j<m){
		if(num2[j] != 0) return -1;
		j++;
	}
	
	while(i<m){
		if(num1[i] != 0) return 1;
		i++;
	}
	
	return 0;
}
    
int main(){
	string ver1, ver2;
	cin >> ver1 >> ver2;
	
	cout << compareVersion(ver1,ver2) << "\n";
	return 0;
}
