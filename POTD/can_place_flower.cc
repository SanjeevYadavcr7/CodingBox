#include<bits/stdc++.h>
using namespace std;

bool canPlaceFlowers(vector<int>& flowerbed, int n){
	bool can_place = true;
	int bed_size = flowerbed.size(), cnt = 0;
	
	for(int i=0; i<bed_size; i++){
		if(!flowerbed[i]){
			int prev = (i == 0 || !flowerbed[i-1]) ? 0 : 1;
			int next = (i == n-1 || !flowerbed[i+1]) ? 0 : 1;
			if(!prev && !next){
				flowerbed[i] = 1;
				cnt++;
			}
		}
	}
	if(cnt < n) can_place = false; 
	return can_place;
}

int main(){
	int n;
	cin >> n;
	vector<int> flowerbed(n);
	for(int i=0; i<n; i++) cin >> flowerbed[i];
	
	int k;
	cin >> k;
	
	if(canPlaceFlowers(flowerbed,k)) cout << "true";
	else cout << "false";
	cout << "\n";
	
	return 0;
}
