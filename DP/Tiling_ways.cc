#include<bits/stdc++.h>
using namespace std;

int doTiling(int n){
    if(n < 4) return n;
    n = n-3;
    int prev_tiles_ways = 2, curr_tiles_ways = 3;
    while(n--){
        int temp = curr_tiles_ways;
        curr_tiles_ways += prev_tiles_ways;
        prev_tiles_ways = temp;
    }
    return curr_tiles_ways;
}

int main(){
    int n;
    cin>>n;
    int tiling_ways = doTiling(n);
    cout<<tiling_ways<<"\n";
    
    return 0;
}
