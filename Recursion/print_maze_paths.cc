#include <iostream>
using namespace std;

void printMazePaths(int sr, int sc, int dr, int dc, string psf){
    
    if(sr>dr || sc>dc) return;
    if(sr == dr && sc == dc){
    	cout<<psf<<"\n";
    	return;
    }
    
    // horizontal move
    string path = psf+"h";
    printMazePaths(sr, sc+1, dr, dc, path);
    
    //vertical move
    path = psf+"v";
    printMazePaths(sr+1, sc, dr, dc, path);
    
    return;
}

int main(){
    int n;
    int m;
    cin >> n >> m;
    printMazePaths(0, 0, n - 1, m - 1, "");
	return 0;
}
