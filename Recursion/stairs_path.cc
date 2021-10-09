#include <iostream>
using namespace std;

void printStairPaths(int n, string path){
	if(n == 0){
		cout<<path<<"\n";
		return;
	}else if(n<0) return;
	
	string temp_path = path+"1";
	printStairPaths(n-1, temp_path);
	
	temp_path = path+"2";
	printStairPaths(n-2, temp_path);
	
	temp_path = path+"3";
	printStairPaths(n-3, temp_path);
    
    return;
}

int main(){
    int n;
    cin >> n;
    printStairPaths(n, "");
	return 0;
}
