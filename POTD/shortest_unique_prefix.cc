#include<bits/stdc++.h>
using namespace std;

struct Node{
    int freq;
    Node* child[26];
    Node(){
        freq = 0;
        memset(child,0,sizeof(child));
    }
};

void insertWord(Node* root, string str, int idx){
    if(idx == str.size()) return;

    int index = str[idx] - 'a';
    if(!root->child[index]) root->child[index] = new Node();
    root->child[index]->freq++;
    insertWord(root->child[index],str,idx+1);
}

int find(Node* root, string str, int idx){
    int index = str[idx] - 'a';
    if(root->child[index]->freq == 1) return idx;
    
    if(root->child[index]) return find(root->child[index],str,idx+1);
    return -1;
}

vector<string> findPrefixes(string arr[], int n){
    vector<string> ans;
    Node* root = new Node();
    for(int i=0; i<n; i++){
        string curr_word = arr[i];
        insertWord(root,curr_word,0);
    }

    for(int i=0; i<n; i++){
        int idx = find(root,arr[i],0);
        string str = "";
        for(char ch : arr[i]){
            if(idx < 0) break;
            str += ch;
            idx--;
        }
        ans.push_back(str);
    }
    return ans;
}

int main(){
    int n; 
    cin >> n;
    string arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];
    
    vector<string> ans = findPrefixes(arr,n);
    for(string str : ans) cout << str << " ";
    cout << "\n";
 
    return 0;
}