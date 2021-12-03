#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	vector<Node*> children;
	Node(int node_data){
		data = node_data;
	}
};
Node* insert(Node* root, vector<int> arr);
void preOrder(Node* node);

int maxSum;
int maxSumNode;
int maxSubTreeSum(Node* node){
	int sum = node->data;
	for(Node* child: node->children){
		int cSum = maxSubTreeSum(child);
		sum += cSum; 
	}
	if(sum > maxSum){
		maxSum = sum;
		maxSumNode = node->data;
	}
	return sum;
}

int main(){
	//vector<int> arr = {10, 20, -1, 30, -1, 40, -1, -1};
	int n;
	cin>>n;
	vector<int> arr;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		arr.push_back(x);
	}
	Node* root = insert(root,arr);
	
	maxSum = INT_MIN;
	maxSubTreeSum(root);
	cout<<maxSumNode<<"@"<<maxSum<<endl;
	return 0;
}

























Node* insert(Node* root, vector<int> arr){
	stack<Node*> stk;
	for(int i=0;i<arr.size();i++){
		int node_data = arr[i];
		Node* new_node = new Node(node_data);
		if(node_data == -1) stk.pop();
		else{
			if(stk.empty()) root = new_node;
			else stk.top()->children.push_back(new_node);
			stk.push(new_node);
		}
	}
	return root;
}



void preOrder(Node* node){
	cout<<node->data<<" ";
	for(Node* child: node->children) preOrder(child);
}
