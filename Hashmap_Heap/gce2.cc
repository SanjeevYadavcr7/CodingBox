#include <bits/stdc++.h>
using namespace std;

void printCommon(int n1, int arr1[], int n2, int arr2[]){
	map<int,int> m1;
	for(int i=0;i<n1;i++) m1[arr1[i]]++;
	for(int i=0;i<n2;i++){
		int key = arr2[i];
		if(m1[key] > 0){
			cout<<key<<endl;
			m1[key]--;
		}
	}
}

int main() {
  int n1, n2;
  cin >> n1;
  int arr1[n1];
  for (int i = 0; i < n1; i++) cin >> arr1[i];
  cin >> n2;
  int arr2[n2];
  for (int i = 0; i < n2; i++) cin >> arr2[i];
  
  cout<<"\nPrinting...\n";
  
  printCommon(n1,arr1,n2,arr2);
  
  return 0;
}
