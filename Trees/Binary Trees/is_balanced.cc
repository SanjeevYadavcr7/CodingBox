#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
	Node(int node_data){
		data = node_data;
		left = right = NULL;
	}
};

Node* contructBinaryTree(Node* root,vector<int> arr);
void display(Node* node);

struct bst{
	bool isbst;
	int max_c;
	int min_c;
	bst(){
		isbst = true;
		max_c = 0;
		min_c = 0;
	}
};

int height(Node* node){
	return (!node) ? -1 : ( max( height(node->left), height(node->right) ) + 1 );
}

pair<int,int> isBalanceHelper(Node* node){
	if(!node){
		pair<int,int> ln = {0,1};
		return ln;
	}
	
	pair<int,int> lp = isBalanceHelper(node->left);
	pair<int,int> rp = isBalanceHelper(node->right);
	
	pair<int,int> ans;
	ans.first = max(lp.first,rp.first)+1;
	int h = abs(lp.first-rp.first);
	ans.second = (lp.second && rp.second && h<=1) ? 1 : 0;
	return ans;
}


int isbalance(Node* node){
	pair<int,int> p = isBalanceHelper(node);
	return p.second;
}


int main(){
	  vector<int> arr;
	  int n;
	  cin>>n;
	  for (int i = 0; i < n; i++) {
	    string inp;
	    cin >> inp;
	    if (inp != "n") arr.push_back(stoi(inp));
	    else arr.push_back(-1);
	  }
		
	  Node* root = contructBinaryTree(root,arr);
	  int r = isbalance(root);
      if (r == 1) cout << "true";
	  else cout << "false";
	  cout<<endl;
	  	 
	  return 0;
}

























void display(Node* node){
	if(!node) return;
	
	string str = "";
	str += (!node->left) ? "." : to_string(node->left->data);
	str += " <- " + to_string(node->data) + " ->";
	str += (!node->right) ? "." : to_string(node->right->data); 
	cout<<str<<endl;
	
	display(node->left);
	display(node->right);
}




Node* contructBinaryTree(Node* root, vector<int>arr){
	stack<pair<Node*,int>> stk;
	root = new Node(arr[0]);
	stk.push({root,1});
	
	int i = 0;
	while(!stk.empty()){
		auto it = stk.top();
		int state = it.second;
		if(state == 1){
			i++;
			stk.top().second++;
			if(arr[i] != -1){
				Node* new_node = new Node(arr[i]);
				stk.top().first->left = new_node;
				stk.push({new_node,1});
			}
			else stk.top().first->left = NULL;
		}
		else if(state == 2){
			i++;
			stk.top().second++;
			if(arr[i] != -1){
				Node* new_node = new Node(arr[i]);
				stk.top().first->right = new_node;
				stk.push({new_node,1});
			}
			else stk.top().first->right = NULL;
		}
		else stk.pop();
	}
	return root;
}

































