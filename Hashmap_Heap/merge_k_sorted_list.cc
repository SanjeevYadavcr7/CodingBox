#include<bits/stdc++.h>
using namespace std;
typedef pair<int, pair<int,int> > pip;

vector<int>mergeKSortedLists(vector<vector<int>>& lists) {
	vector<int> res;
	priority_queue<pip, vector<pip>, greater<pip>> pq;
	
	int k = lists.size();
	for(int i=0;i<k;i++){
		int first_val = lists[i][0];
		pq.push({first_val,{i,0}});
	}
	
	int i=0;
	while(!pq.empty()){
		auto it = pq.top();
		int curr_min_val = it.first;
		int curr_list = it.second.first;
		int curr_index = it.second.second;
		pq.pop();
		
		res.push_back(curr_min_val);
		
		int next_index = curr_index+1;
		int curr_list_size = lists[curr_list].size();
		if(next_index < curr_list_size){
			int next_val = lists[curr_list][next_index];
			pq.push({next_val,{curr_list,next_index}});	
		}
	}
	
	return res; 	
}

int main() {
  int k;
  cin >> k;
  vector<vector<int>>lists;
  for (int i = 0; i < k; i++) {
    vector<int>list;

    int n;
    cin >> n;
    for (int j = 0; j < n; j++) {
      int data;
      cin >> data;
      list.push_back(data);
    }

    lists.push_back(list);
  }

  vector<int> mlist = mergeKSortedLists(lists);
  for (int val : mlist) {
    cout << val << " ";
  }
  cout << endl;
  return 0;
}





















































