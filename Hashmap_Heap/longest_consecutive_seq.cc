#include<bits/stdc++.h>
using namespace std;

void longestConsecutive(vector<int>& num) {
	unordered_map<int,int> m;
	for(int &i: num) m[i] = 1;
	int max_freq = 0, beg;
	for(int i=14;i>=0;i--){
			if(m[i] != 0){
				m[i] = m[i+1] + 1;
				if(max_freq < m[i]){
					max_freq = m[i];
					beg = i;
				}
			} 
	}
	
	for(int i=beg;i<beg+max_freq;i++) cout<<i<<" ";
	cout<<endl;
	
}

int main()
{
  vector<int>arr;
  int n;
  cin >> n;
  for (int i = 0 ; i < n; i++) {
    int data;
    cin >> data;
    arr.push_back(data);
  }
  longestConsecutive(arr);

  return 0;
}
