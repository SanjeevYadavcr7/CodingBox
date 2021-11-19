#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	vector<struct Node*> children;
	Node(int node_data){
		data = node_data;
	}
};

void levelOrder(struct Node* root);
void levelOrder2(struct Node* root);


int main(){
	vector<int> arr = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
	
	struct Node* root;
	stack<struct Node*> stk;
	
	for(int i=0;i<arr.size();i++){
		if(arr[i] == -1) stk.pop();
		else{	
			int node_data = arr[i];
			Node* new_node = new Node(node_data);
			if(stk.empty()) root = new_node;
			else stk.top()->children.push_back(new_node);
			stk.push(new_node);
		}
	}
	
	levelOrder2(root);

	return 0;
}









void levelOrder2(struct Node* root){
	queue<Node*> q;
	q.push(root);
	q.push(new Node(-1));
	
	while(!q.empty()){
		Node* node = q.front();
		q.pop();
		if(node->data != -1){
			cout<<node->data<<" ";
			for(Node* child : node->children) q.push(child);
		}
		else{
			if(!q.empty()){
				q.push(new Node(-1));
				cout<<endl;
			} 
		}
	}
}



void levelOrderHelper(struct Node* node, queue<struct Node*> q){
	queue<struct Node*> temp_q;
	while(!q.empty()){
		struct Node* node = q.front();
		cout<<node->data<<" ";
		q.pop();
		for(Node* child: node->children){
			temp_q.push(child);
		}
	}
	cout<<endl;
	if(!temp_q.empty()) levelOrderHelper(node, temp_q); 
}

void levelOrder(struct Node* root){
	queue<struct Node*> q;
	q.push(root);
	levelOrderHelper(root, q);	
}







