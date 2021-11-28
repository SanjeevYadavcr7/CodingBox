#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	vector<struct Node*> children;
	Node(int node_data){
		data = node_data;	
	}
};

void mirror(Node* root);
void preOrder(Node* root);
bool areSimilar(Node* root1, Node* root2);
Node* insert(Node* root, vector<int> arr);
bool areMirrors(Node* root1, Node* root2);
  
bool issym(Node* node){
	
	int n = node->children.size();
	for(int i=0;i<n/2;i++){
		Node* child1 = node->children[i];
		Node* child2 = node->children[n-i-1];
		if(!areMirrors(child1, child2)) return false;
	}
	return true;
}  
  
int main(){
	vector<int> arr1, arr2;
	int n1,x;
	cin>>n1;
	for(int i=0;i<n1;i++){
		cin>>x;
		arr1.push_back(x);
	}
	struct Node *root1, *root2;
	root1 = insert(root1, arr1);
	if(issym(root1)) cout<<"true\n";
	else cout<<"false\n";
	
	return 0;
}




//10 20 50 -1 60 -1 -1 30 70 -1 80 -1 90 -1 -1 40 100 -1 -1 -1
























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


void mirror(Node* root){
	for(Node* child: root->children) mirror(child);
	reverse(root->children.begin(), root->children.end());
}

void preOrder(Node* node){
	cout<<node->data<<" ";
	for(Node* child: node->children){
		preOrder(child);
	}
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

bool areMirrors(Node* root1, Node* root2){
	mirror(root1);
	return areSimilar(root1, root2);
}
