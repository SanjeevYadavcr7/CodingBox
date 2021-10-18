#include<bits/stdc++.h>
using namespace std;

int main(){
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int t;
	scanf("%d", &t);
	
	for(int k=1;k<=t;k++){
		int n,d,c,m;
		scanf("%d %d %d %d", &n, &d, &c, &m);
		string s;
		cin>>s;
		
		int dog = 0, cat = 0;
		for(int i=0;i<n;i++){
			if(s[i] == 'C') cat++;
			else dog++;
		}
		
		if(dog == 0) cout<<"Case "<<"#"<<k<<":"<<" YES\n";
		else if(cat == 0){
			if(d>=dog) cout<<"Case "<<"#"<<k<<":"<<" YES\n";
			else cout<<"Case "<<"#"<<k<<":"<<" NO\n";
		}
		else{
			for(int i=0;i<n;i++){
				if(s[i] == 'D'){
					if(d == 0){ 
						cout<<"Case "<<"#"<<k<<":"<<" NO\n";
						break;
					}
					d = d-1;
					c = c+m;
					dog = dog-1;	
				}
				else if(s[i] == 'C'){
					if(c == 0){
						if(dog == 0){ 
							cout<<"Case "<<"#"<<k<<":"<<" YES\n";
							break;
						}
						cout<<"Case "<<"#"<<k<<":"<<" NO\n";
						break;
					}
					c = c-1;
				}
				if(i == n-1) cout<<"Case "<<"#"<<k<<":"<<" YES\n";
			}
		}
	}
	return 0;
}
