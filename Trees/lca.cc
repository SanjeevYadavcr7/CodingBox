#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	vector<struct Node*> children;
	Node(int node_data){
		data = node_data;
	}
};

void display(Node* node);
void preOrder(Node* root);

bool getPath(Node* node, int item, vector<int> &path){
	if(node->data == item){
		path.push_back(item);
		return true;
	}
	for(Node* child: node->children){
		if(getPath(child, item, path)){
			path.push_back(node->data);
			return true;
		} 
	}
	return false;
}

int lca(Node* node, int data1, int data2)
{
	vector<int> path1, path2;
	getPath(node, data1, path1);
	getPath(node, data2, path2);
	int n1 = path1.size(), n2 = path2.size(), ans = 0;
	for(int i=n1, j=n2; i>=0, j>=0, i--, j--;){
		if(path1[i] == path2[j]) ans = path1[i];
		else break;
	}
	return ans;
}

int main(){	
	int x,y;
	vector<int> arr = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
	struct Node* root;
	stack<Node*> stk;
	for(int i=0;i<arr.size();i++){
		int node_data = arr[i];
		Node* new_node = new Node(node_data);
		if(arr[i] == -1) stk.pop();
		else{
			if(stk.empty()) root = new_node;
			else stk.top()->children.push_back(new_node);
			stk.push(new_node);
		}
	}

	preOrder(root);
	cout<<endl;
	cin>>x>>y;
	int ans = lca(root,x,y);	
	cout<<ans<<endl;
	return 0;
}






















void display(Node* root){
	string path = to_string(root->data) + " -> ";
	for(Node* child: root->children){
		path += to_string(child->data) + ", ";
	}
	cout<<path<<".\n";
	for(Node* child: root->children) display(child);
}

void preOrder(Node* root){
	if(!root) return;
	cout<<root->data<<" ";
	for(Node* child: root->children){
		preOrder(child);
	}
}	
