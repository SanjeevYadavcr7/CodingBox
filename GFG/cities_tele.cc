#include<bits/stdc++.h>
using namespace std;

    int solve (int N,vector<int> &A,int X,int K){
        int i;
        priority_queue<int> pq;
        for(i=1; i<N; i++){
        	//cout << "I = "<< i<<"\n";
            int d = A[i] - A[i-1];
            pq.push(d);
            X -= d;
            if(X < 0){
            	if(K > 0){
            		X += pq.top();
            		pq.pop();
            		K--;
            	}
            	else break;
            }
        }
        return i;
    }

int main(){
	int n,x,k;
	cin >> n >> x >> k;
	vector<int> arr(n);
	for(int i=0;i<n;i++) cin >> arr[i];
	
	int ans = solve(n,arr,x,k);
	cout << ans << "\n";

	return 0;
}







































/*
        int vis = 1;
        vector<int> dis;
        for(int i=1; i<N; i++){
        	int temp_dis = A[i] - A[i-1];
        	dis.push_back(temp_dis);
        }
        sort(dis.begin(),dis.end(),cmp);
		int curr_max = 0;
		
		cout<<"\nDis[] = ";
		for(int i:dis) cout<<i<<" ";
		cout<<"\n";

		
        for(int i=1; i<N; i++){
            int E = abs(A[i] - A[i-1]);
            if((E == dis[curr_max]) && (K > 0)){
            		K--;
            		vis++;
            		curr_max++;
            }
            else if(E <= X){
                X -= E;
                vis++;
            }
            else if(K > 0){
                K--;
                vis++;
            }
            else break;
        	cout << "("<<E<<","<<vis<<","<<dis[curr_max]<<") | ";
        }
        cout<<"\n";
        
        return vis;
*/
