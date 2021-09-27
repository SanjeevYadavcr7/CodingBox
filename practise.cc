#include<bits/stdc++.h>
using namespace std;
 
void solve(int n){
    string str = to_string(n);
    cout<<str.length();
}

struct node{
    int data;
    struct node *next;
}

void reverse(head){

struct node *slow=head, *fast=head;
while(slow && fast && fast->next){
    slow = slow->next;
    fast = fast->next->next;
    if(slow == fast) return 1;
}
} 

int main(){
    
    struct node* head = NULL;

    int n,x;
    cin>>n;
    vector<int> arr;
    map<int,int> mp;
    for(int i=0;i<n;i++){
        cin>>x;
        mp.insert({i,x});
    }

    for(auto i: mp)cout<<i.second<<" ";
    cout<<"\n";

return 0;
}