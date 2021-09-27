#include<iostream>
using namespace std;

int main(){
	int n1,m1,n2,m2;
	cin>>n1>>m1;
	int arr1[n1][m1];
	for(int i=0;i<n1;i++)
		for(int j=0;j<m1;j++) cin>>arr1[i][j];

	cin>>n2>>m2;
	int arr2[n2][m2];
	for(int i=0;i<n2;i++)
		for(int j=0;j<m2;j++) cin>>arr2[i][j];
		
	if(m1 != n2) cout<<"Invalid input\n";
	else{
	    int arr3[n1][m2];
    	for(int k=0;k<m2;k++){
    			for(int i=0;i<n1;i++){
    				int ans = 0;
    				for(int j=0;j<n2;j++){
    					ans += (arr1[i][j] * arr2[j][k]);
    				}
    				arr3[i][k] = ans;
    			}	
    	}
    	
    	for(int i=0;i<n1;i++){
    		for(int j=0;j<m2;j++)
    			cout<<arr3[i][j]<<" ";
    		cout<<"\n";
    	}    
	}
	
	
	return 0;	
}

