#include<iostream>
using namespace std;


void printMazePaths(int sr, int sc, int dr, int dc, string psf) {
	
	if(sr>dr || sc>dc) return;
    if(sr == dr && sc == dc){
    	cout<<psf<<"\n";
    	return;
    }

    string path;
    for(int h=1;h<=dc-sc;h++){
    	path = psf+"h"+to_string(h);
    	printMazePaths(sr, sc+h, dr, dc, path);
    }
    
    for(int v=1;v<=dr-sr;v++){
    	path = psf+"v"+to_string(v);
    	printMazePaths(sr+v, sc, dr, dc, path);
    }
    
    for(int d=1;d<=dr-sr && d<=dc-sc;d++){
    	path = psf+"d"+to_string(d);
    	printMazePaths(sr+d, sc+d, dr, dc, path);
    }
     return;   
}

int main() {
	int n, m;
	cin>>n>>m;
    printMazePaths(0, 0, n - 1, m - 1, "");
	return 0;
}
