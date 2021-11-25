#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	vector<struct Node*> children;
	Node(int node_data){
		data = node_data;	
	}
};

Node* insert(Node* root, vector<int> arr);
void preOrder(Node* root);
vector<int> getNodePath(Node* node, int node_data);

bool isLeaf(Node* root1){
	if(root1->children.size() == 0) return true;
	return false;
}

bool areSimilar(Node* root1, Node* root2){

	if(root1->children.size() != root2->children.size()) return false;
	
	for(int i=0;i<root1->children.size();i++){
		Node* child1 = root1->children[i];
		Node* child2 = root2->children[i];
		if(!areSimilar(child1, child2)) return false;
	}	
	return true;
}    

  
int main(){
	//vector<int> arr1 = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
	//vector<int> arr2 = {1, 2, 5, -1, 6, -1, -1, 3, 7, -1, 8, 11, -1, 12, -1, -1, 9, -1, -1, 4, 10, -1, -1, -1};
	vector<int> arr1, arr2;
	int n1,n2,x;
	cin>>n1;
	for(int i=0;i<n1;i++){
		cin>>x;
		arr1.push_back(x);
	}
	cin>>n2;
	for(int i=0;i<n2;i++){
		cin>>x;
		arr2.push_back(x);
	}
	struct Node *root1, *root2;
	root1 = insert(root1, arr1);
	root2 = insert(root2, arr2);	
	//preOrder(root1);
	//cout<<endl;
	//preOrder(root2);
	//cout<<endl;
	if(areSimilar(root1, root2)) cout<<"true\n";
	else cout<<"false\n";
	
	return 0;
}








































void preOrder(Node* node){
	cout<<node->data<<" ";
	for(Node* child: node->children){
		preOrder(child);
	}
}


Node* insert(Node* root, vector<int> arr){
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
	return root;
}

vector<int> getNodePath(Node* node, int node_data){
	if(node->data == node_data){
		vector<int> path = {node_data};
		return path;
	}
	for(Node* child: node->children){
		vector<int> path = getNodePath(child,node_data);
		if(path.size() > 0){
			path.push_back(node->data);
			return path;
		}
	}
	vector<int> path;
	return path;
}
