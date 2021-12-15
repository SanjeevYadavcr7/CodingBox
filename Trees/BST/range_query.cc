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
Node* remove(Node* node, int data);
Node* constructTree(vector<int> arr);

void pir(Node* node, int d1, int d2){
	if(!node) return;
	pir(node->left,d1,d2);
	if(node->data >= d1 && node->data <= d2) cout<<node->data<<endl;
	pir(node->right,d1,d2);	
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
	
  	int a, b;
  	cin >> a >> b;
  	Node* root = constructTree(arr);
  	cout<<"Printing.....\n";
	pir(root,a,b);
	
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

Node* remove(Node* node, int data) {
	if(!node) return NULL;
	
	if(node->data > data) node->left = remove(node->left,data);
	else if(node->data < data) node->right = remove(node->right,data);
	else{
		if(node->left && node->right){
			int max_left_data;
			//max_left_data = getLeftMaxValue(node->left);
			node->data = max_left_data;
			node->left = remove(node->left,max_left_data);
			return node;
		}
		else if(node->left) return node->left;
		else if(node->right) return node->right;
		else return NULL;
	}
	return node;
}


