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

void display(Node* node);
Node* constructTree(vector<int> arr);

Node* getNextInorderNode(stack<pair<Node*,int>>& stk){
	while(!stk.empty()){
		auto it = stk.top();
		Node* top_node = it.first;
		int state = it.second;
		if(state == 0){
			stk.top().second++;
			if(top_node->left) stk.push({top_node->left,0});
		}
		else if(state == 1){
			stk.top().second++;
			if(top_node->right) stk.push({top_node->right,0});
			return top_node;
		}
		else stk.pop();
	}
	
	return NULL;
}

Node* getLastNextInorderNode(stack<pair<Node*,int>>& stk){
	while(!stk.empty()){
		auto it = stk.top();
		Node* top_node = it.first;
		int state = it.second;
		if(state == 0){
			stk.top().second++;
			if(top_node->right) stk.push({top_node->right,0});
		}
		else if(state == 1){
			stk.top().second++;
			if(top_node->left) stk.push({top_node->left,0});
			return top_node;
		}
		else stk.pop();
	}
	return NULL;
}


void targetSum(Node* root, int tar){
	stack<pair<Node*,int>> inc, dec;
	pair<Node*,int> p = {root,0};
	inc.push(p);
	dec.push(p);
	
	Node* lc = getNextInorderNode(inc);
	Node* rc = getLastNextInorderNode(dec);
	
	while(lc->data < rc->data){
		if(lc->data + rc->data < tar) lc = getNextInorderNode(inc);
		else if(lc->data + rc->data > tar) rc = getLastNextInorderNode(dec);
		else{
			cout<<lc->data<<" "<<rc->data<<endl;
			lc = getNextInorderNode(inc);
			rc = getLastNextInorderNode(dec);
		}
	}
}



int main(){
	int n;
	cin>>n;
	vector<int> arr;
	for(int i=0;i<n;i++){
		string temp;
		cin>>temp;
		if(temp == "n") arr.push_back(-1);
		else arr.push_back(stoi(temp));
	}
	
  	int target;
  	cin >> target;
  	Node* root = constructTree(arr);
	targetSum(root,target);
	
	return 0;
}





























void display(Node* node){
	if(!node) return;
	
	string str = "";
	str += (!node->left) ? "." : to_string(node->left->data);
	str += " <- " + to_string(node->data) + " -> ";
	str += (!node->right) ? "." : to_string(node->right->data);
	cout<<str<<endl;
	
	display(node->left);
	display(node->right);
}

Node* constructTree(vector<int> arr){
	stack<pair<Node*,int>> stk;
	Node* root = new Node(arr[0]);
	stk.push({root,0});
	int i = 0;
	while(!stk.empty()){
		auto it = stk.top();
		int state = it.second;
		if(state == 0){
			i++;
			stk.top().second++;
			if(arr[i] != -1){
				Node* new_node = new Node(arr[i]); 
				stk.top().first->left = new_node;
				stk.push({new_node,0});
			}
			else stk.top().first->left = NULL;
		}
		else if(state == 1){
			i++;
			stk.top().second++;
			if(arr[i] != -1){
				Node* new_node = new Node(arr[i]); 
				stk.top().first->right = new_node;
				stk.push({new_node,0});
			}
			else stk.top().first->right = NULL;
		}
		else stk.pop();
	}
	return root;
}

