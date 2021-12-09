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

bst* Bst(Node* node){
	if(!node){
		bst* new_node = new bst(); 
		new_node->isbst = true;
		new_node->max_c = INT_MIN;
		new_node->min_c = INT_MAX;
		return new_node;
	}
	
	bst* l = Bst(node->left);
	bst* r = Bst(node->right);	
	
	bst* ans = new bst();
	ans->isbst = l->isbst && r->isbst && (node->data >= l->max_c && node->data <= r->min_c);
	ans->max_c = max(node->data, max(l->max_c,r->max_c));
	ans->min_c = min(node->data, min(l->min_c,r->min_c));
	return ans;
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
	  bst* r = Bst(root);
	  if(r->isbst) cout<<"true";
	  else cout<<"false";
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

































