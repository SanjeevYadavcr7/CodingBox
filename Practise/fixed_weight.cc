#include<bits/stdc++.h>
using namespace std;

int fact(int n){
    if(n == 1) return 1;
    return n*fact(n-1);
}

bool isPerPossible(string str, int x){
    int n = str.size();
    int r = str[n-1] - '0', l = str[0] - '0', min_num = INT_MAX;
    
    if(r < l) return false;
    for(int i=l-1; i<r; i++){
        min_num = min(min_num,str[i]-'0');
    }
    int ans = (r - l + 1) * min_num;
    return (ans == x);
}

void getPermutation(int i,int n,string str, string per, int x, bool& done){
    if(str.size() == 0){
        if(isPerPossible(per,x)) done = true;
        return;
    } 

    int rem = i % n;
    i /= n;
    per += str[rem];
    string new_str = str.substr(0,rem) + ((rem+1 < n) ? str.substr(rem+1) : "");
    getPermutation(i,n,new_str,per,x,done);
}

bool isWeightPossible(int n, int x){
    int total_per = fact(n);
    string str = "";
    for(int i=1; i<=n; i++){
        char ch = i + '0';
        str += ch;
    }
    bool done = false;
    for(int i=0; i<total_per; i++){
        getPermutation(i,n,str,"",x,done);
        if(done) return true;
    }
    return false;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,x; 
        cin >> n >> x;
        if(isWeightPossible(n,x)) cout << "YES";
        else cout << "NO";
        cout << "\n";
    }
     
    return 0;
}