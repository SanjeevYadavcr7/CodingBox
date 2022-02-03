#include<bits/stdc++.h>
using namespace std;
int cnt = 1;

void getPairingWays(int i, int n, vector<bool>& vis, string p){
    if(i>n){
        cout << cnt << "." << p << "\n";
        cnt++;
        return;
    }

    if(vis[i]) getPairingWays(i+1,n,vis,p);
    else{
        vis[i] = i;
        getPairingWays(i+1,n,vis,p + " (" + to_string(i) + ") ");
        for(int j=i+1; j<=n; j++){
            if(vis[j]) continue;
            vis[j] = true;
            getPairingWays(i+1,n,vis,p+" (" + to_string(i) + "," + to_string(j) + ") ");
            vis[j] = false;
        }
        vis[i] = false;
    }

}

int main(){
    int n;
    cin >> n;
    vector<bool> vis(n+1,false);
    getPairingWays(1,n,vis,"");
    
    return 0;
}

