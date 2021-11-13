#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	vector<struct Node*> children;
	Node(int node_data){
		data = node_data;
		children = {};
	}
}; 

void display(struct Node* node){
	string str = to_string(node->data) + " -> ";
	for(struct Node* child: node->children){
		str += to_string(child->data) + " ";
	}
	cout<<str<<endl;
	
	for(struct Node* child: node->children){
		display(child);
	}
}

int cntNodes(Node* node){
	int cnt = 0;
	for(Node* child: node->children){
		int child_noes = cntNodes(child);
		cnt += child_noes;	
	}
	cnt += 1;
	return cnt;
}

int main(){

	vector<int> arr = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
		int n = arr.size();
	struct Node* root;	
	stack<struct Node*> stk;
	
	for(int i=0;i<n;i++){
		if(arr[i] == -1) stk.pop();
		else{
			int node_data = arr[i];
			struct Node* new_node = new Node(node_data);
			//new_node.data = node_data;
			if(stk.empty()) root = new_node;
			else stk.top()->children.push_back(new_node);
			stk.push(new_node);
		}
	}	
	
	//display(root);
	int no_of_nodes = cntNodes(root);
	cout<<no_of_nodes<<endl;
	
	return 0;
}
