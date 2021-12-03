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

int dia = 0;
int customGetTreeHeight(Node* root){
	int max_h = -1, sec_max_h = -1;
	for(Node* child : root->children){
		int ch = customGetTreeHeight(child);
		if(ch > max_h){
			sec_max_h = max_h;
			max_h = ch;
		} 
		else if(ch > sec_max_h) sec_max_h = ch;
	}
	int temp_h = max_h + sec_max_h + 2;
	if(dia < temp_h) dia = temp_h;
	max_h += 1;
	return max_h;
}

int diameter(Node* root) {
	return customGetTreeHeight(root);
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
	cout<<endl;
	
	diameter(root);
	cout<<dia<<endl;	
		
	return 0;
}


//24
//10 20 -50 -70 -1 -1 60 -1 -1 30 -70 110 -1 -1 80 -1 90 -1 -1 40 -100 -1 -1 -1














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
