#include<iostream>
#include<vector>
using namespace std;

vector <string> getMazePaths(int sr, int sc, int dr, int dc) {
	
	if(sr == dr && sc == dc){
		vector<string> ans{{""}};
		return ans;
	} else if(sr>dr || sc>dc){
		vector<string> ans;
		return ans;
	}
	
	vector<string> h_paths = getMazePaths(sr,sc+1,dr,dc);
	vector<string> v_paths = getMazePaths(sr+1,sc,dr,dc);	
	
	vector<string> ans;
	for(string str : h_paths) ans.push_back("h"+str);
	for(string str : v_paths) ans.push_back("v"+str);
	
	return ans;
}

void display(vector<string>& arr){
    cout << "[";
    for(int i = 0;i < arr.size();i++){
        cout << arr[i];
        if(i < arr.size() -1) cout << ", ";
    }
    
    cout << "]"<<endl;
}


int main() {
    int n,m; cin >> n >> m;
    vector<string> ans = getMazePaths(0,0,n-1,m-1);
    display(ans);

    return 0;
}
