#include<bits/stdc++.h>
using namespace std;

int doTiling(int n, int m){
    if(n >= m) return 1;
    if(n == m) return 2;    
    m = m-n;
    int prev_tiles_ways = 1, curr_tiles_ways = 2;
    while(m--){
        int temp = curr_tiles_ways;
        curr_tiles_ways += prev_tiles_ways;
        prev_tiles_ways = temp;
    }
    return curr_tiles_ways;
}

int main(){
    int n,m;
    cin>>n>>m;
    int tiling_ways = doTiling(n,m);
    cout<<tiling_ways<<"\n";
    
    return 0;
}
