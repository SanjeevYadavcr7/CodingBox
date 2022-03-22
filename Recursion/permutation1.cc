#include<bits/stdc++.h>
using namespace std;

void display(vector<int>& box){
	for(int i=0; i<box.size(); i++) cout << box[i];
	cout << "\n";
}

void placeBoxes(vector<int>& box, int idx, int r){
	if(idx > r){
		display(box);
		return;
	} 
	
	for(int i=0; i<box.size(); i++){
		if(box[i] == 0){
			box[i] = idx;
			placeBoxes(box,idx+1,r);
			box[i] = 0;
		}
	}
}

int main(){
	int n,r;
	cin >> n >> r;
	vector<int> boxes(n,0);
	placeBoxes(boxes,1,r);

	return 0;
}
