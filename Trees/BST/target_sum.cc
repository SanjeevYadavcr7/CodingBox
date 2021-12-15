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
void travelAndPrint(Node* root, Node* node, int tar);
bool search(Node* node, Node* blocker, int data);

void getNodesInArray(Node* node, vector<int> & arr){
	if(!node) return;
	getNodesInArray(node->left,arr);
	arr.push_back(node->data);
	getNodesInArray(node->right,arr);
}

void targetSum(Node* root, int tar){
	vector<int> node_arr;
	getNodesInArray(root,node_arr);
	int beg = 0, end = node_arr.size()-1;
	while(beg<end){
		if(node_arr[beg] + node_arr[end] == tar){
			cout<<node_arr[beg]<<" "<<node_arr[end]<<endl;
			beg++;
			end--;
		} 
		else if(node_arr[beg] + node_arr[end] < tar) beg++;
		else end--;
	}
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
	
  	int target;
  	cin >> target;
  	Node* root = constructTree(arr);
	targetSum(root,target);
	
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

bool search(Node* node, Node* blocker, int data){
	if(!node) return false; 
	
	if(node->data == data && node != blocker){
		node->data = INT_MIN;
		return true;
	} 
	else if(node->data > data) return search(node->left,blocker,data);
	else if(node->data > data) return search(node->right,blocker,data);
	else return (search(node->left,blocker,data) || search(node->right,blocker,data));		
}


void travelAndPrint(Node* root, Node* node, int tar) {
	if(!node) return;
	int co_pair = tar - node->data;
	if(search(root,node,co_pair)){
		cout<<node->data<<" "<<co_pair<<endl;
		node->data = INT_MIN;
	} 
	travelAndPrint(root, node->left, tar);
	travelAndPrint(root, node->right, tar);
}
