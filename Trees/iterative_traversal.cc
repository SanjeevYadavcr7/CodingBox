#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	vector<Node*> children;
	Node(int node_data){
		data = node_data;
	}
};
struct Node* construct(Node* root, vector<int> arr);
void preOrder(Node* node);

void PreOrder(Node* node);

void iterativePreAndPostOrder(Node* root) {
	vector<int> pre, post;
	stack<pair<Node*, int>> stk;
	stk.push({root,-1});
	
	while(!stk.empty()){
		auto it = stk.top();
		int state = it.second;
		Node* curr_node = it.first;
		if(state == -1){	
			pre.push_back(curr_node->data);
			stk.top().second++;
		}
		else if(state == curr_node->children.size()){
			post.push_back(curr_node->data);
			stk.pop();
		}
		else{
			Node* child = curr_node->children[state];
			stk.top().second++;
			stk.push({child, -1});
		}
	}
	
	cout<<"Pre-order = ";
	for(int i : pre) cout<<i<<" ";
	
	cout<<"\nPost-order = ";
	for(int i : post) cout<<i<<" ";
	cout<<endl;
}

int main(){
	int n;
	cin>>n;
	vector<int> arr;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		arr.push_back(x);
	}
	
	Node* root = construct(root,arr);
	preOrder(root);
	cout<<endl<<endl;
	
	iterativePreAndPostOrder(root);
	
	return 0;
}


//24
//10 20 -50 -70 -1 -1 60 -1 -1 30 -70 110 -1 -1 80 -1 90 -1 -1 40 -100 -1 -1 -1

















void PreOrder(Node* node){
	stack<Node*> stk;
	stk.push(node);
	while(!stk.empty()){
		Node* temp_top = stk.top();
		stk.pop();
		cout<<temp_top->data<<" ";
		for(int i=temp_top->children.size()-1; i >= 0; i--){
			Node* child = temp_top->children[i];
			stk.push(child);
		}
	}
}



struct Node* construct(Node* root, vector<int> arr){
	stack<Node*> stk;
	for(int i=0;i<arr.size();i++){
		int node_data = arr[i];
		if(node_data == -1) stk.pop();
		else{
			Node* new_node = new Node(node_data);
			if(stk.empty()) root = new_node;
			else stk.top()->children.push_back(new_node);
			stk.push(new_node);
		}
	}	
	return root;
}

void preOrder(Node* node){
	cout<<node->data<<" ";
	for(Node* child:node->children) preOrder(child);
}
