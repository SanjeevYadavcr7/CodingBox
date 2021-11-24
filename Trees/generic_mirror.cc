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
	
	levelOrder(root);
	mirrorTree(root);
	
	return 0;
}


























void levelOrder(struct Node* root){
	queue<Node*> q;
	q.push(root);

	while(q.size() > 0){
		int cnt = q.size();
		for(int i=0;i<cnt;i++){
			Node* node = q.front();
			q.pop();
			for(Node* child: node->children) q.push(child);
			cout<<node->data<<" ";
		}
		cout<<endl;
	}
}

