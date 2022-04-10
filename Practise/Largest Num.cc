#include<bits/stdc++.h>
using namespace std;

    bool cmp(int a,int b){
       return a>b; 
    }
    
    int largestInteger(int num) {
        int largest_num = 0;
        int j=0,k=0;
        vector<char> parity;
		vector<int> odd,even;
                
        while(num != 0){
            int digit = num%10;
            num /= 10;
            if(digit&1){
            	parity.push_back('o');
            	odd.push_back(digit);
            }   
            else{
 	          	parity.push_back('e');
            	even.push_back(digit);
            }   
        }
 		reverse(parity.begin(),parity.end());       
        
        sort(even.begin(),even.end(),cmp);
        sort(odd.begin(),odd.end(),cmp);
        
        for(char ch : parity){
            if(ch == 'o') largest_num = largest_num*10 + odd[j++]; 
            else largest_num = largest_num*10 + even[k++];
        }
        return largest_num;
    }

int main(){
	int n;
	cin >> n;
	
	n = largestInteger(n);
	cout << "N = " << n << "\n";
	
	return 0;
}
