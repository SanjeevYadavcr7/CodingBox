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

bool isLeaf(Node* node){
	if(node && !node->left && !node->right) return true;
	return false;
}

Node* removeLeaves(Node* node) {
	if(!node) return NULL;
	if(isLeaf(node)){
		free(node);
		return NULL;
	}
	Node* lc = removeLeaves(node->left);
	node->left = lc;
	Node* rc = removeLeaves(node->right);
	node->right = rc; 
	return node;
}

/*
int height(Node* node){
	if(!node) return -1;
	int lh = height(node->left);
	int rh = height(node->right);
	int h = max(lh,rh)+1;
	return h;
}
*/

int height(Node* node){
	return (!node) ? -1 : max(height(node->left), height(node->right))+1;
}

int temp = 0;

int diameter(Node* node){
	if(!node) return -1;
	
	if(node){
		int ld = diameter(node->left);
		if(ld>temp) temp = ld;
		int rd = diameter(node->right);
		if(rd>temp) temp = rd;
	}
	
	int lh = height(node->left);
	int rh = height(node->right);
	
	int h = lh+rh+2;
	if(h>temp) temp = h;
	return temp;	
}

int diameter1(Node* node){
	if(!node) return 0;
	int ld = diameter1(node->left);
	int rd = diameter1(node->right);
	int h = height(node->left) + height(node->right) + 2;
	int dia = max(h, max(ld,rd));
	return dia;
}

pair<int,int> diameterHelper(Node* node){
	if(!node){
		pair<int,int> p = {-1,0};
		return p;
	}
	
	pair<int,int> lp = diameterHelper(node->left);
	pair<int,int> rp = diameterHelper(node->right);
	
	int h = lp.first + rp.first + 2;
	int dia = max(h, max(lp.second, rp.second));
	int hei = max(lp.first,rp.first)+1;
	pair<int,int> p = {hei,dia};
	return p;
}

int getDiameter(Node* node){
	pair<int, int> dia = diameterHelper(node);
	int d = dia.second;
	return d;
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
  	  int dia = 0;
  	  dia = diameter(root);
  	  cout << dia;
  
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

































