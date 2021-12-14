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
Node* constructTree(vector<int> arr);
void display(Node* node);

Node* remove(Node* node, int data) {
	if(!node) return NULL;
	
	Node *par, *child, *ptr, *succ, *parsucc;
	par = NULL;
	ptr = node;
	
	// searching node to be deleted
	while(ptr){
		if(ptr->data == data) break;
		par = ptr;
		if(ptr->data > data) ptr = ptr->left;
		else ptr = ptr->right;
	}
	if(!ptr){
		cout<<"Node to be removed is not present in the tree\n";
		return NULL;
	}
	
	// Case 3 :
	if(ptr->left && ptr->right){
		parsucc = ptr;
		succ = ptr->right;
		while(succ->left){
			parsucc = succ;
			succ = succ->left;
		}
		ptr->data = succ->data;
		ptr = succ;
		par = parsucc;
	}
	
	// Case 1 & Case 2 :
	if(ptr->left) child = ptr->left;
	else child = ptr->right;
	
	if(par == NULL) node = child;
	else if(ptr == par->left) par->left = child;
	else par->right = child;
	free(ptr);
	return node;
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
	
	int item;
	cin>>item;
	
	Node* root = constructTree(arr);
	cout<<"Tree --> \n";
	display(root);
	root = remove(root,item);
	cout<<"\nTree : "<<item<<" removed --> \n";
	display(root);
	
	return 0;
}

//15
//10 5 3 n n 7 n n 14 12 n n 16 n n 



























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
