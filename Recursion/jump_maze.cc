#include<iostream>
#include<vector>
using namespace std;

vector <string> getMazePaths(int sr, int sc, int dr, int dc) {
	
	if(sr == dr && sc == dc){
		vector<string> ans{{""}};
		return ans;
	}else if(sr>dr || sc>dc){
		vector<string> ans;
		return ans;
	}	
	
	vector<string> ans;
	for(int ms = 1; ms <= dc-sc; ms++){
		vector<string> h_paths = getMazePaths(sr, sc+ms, dr, dc);
		for(string str : h_paths) ans.push_back("h"+to_string(ms)+str);
	}	
	for(int ms = 1; ms <= dr-sr; ms++){
		vector<string> v_paths = getMazePaths(sr+ms, sc, dr, dc);
		for(string str : v_paths) ans.push_back("v"+to_string(ms)+str);
	}	
	for(int ms = 1; ms <= dr-sr && ms <= dc-sc; ms++){
		vector<string> d_paths = getMazePaths(sr+ms, sc+ms, dr, dc);
		for(string str : d_paths) ans.push_back("d"+to_string(ms)+str);
	}	
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
