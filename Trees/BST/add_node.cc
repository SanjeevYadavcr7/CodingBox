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
Node* construct(vector<int>& arr);
void display(Node* node);
int min(Node* node);
int max(Node* node);
int sum(Node* node);
int size(Node* node);
bool find(Node* node, int data);

Node* add(Node* node, int val){
	if(!node){
		Node* new_node = new Node(val);
		return new_node;
	}
	if(node->data > val) node->left = add(node->left,val);
	else if(node->data < val) node->right = add(node->right,val);
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
	
	Node* root = construct(arr);
	root = add(root, item);
	display(root);
	
	return 0;
}























int min(Node* node){
	if(node && !node->left && !node->right) return node->data;
	int ans = min(node->left);
	return ans;
}

int max(Node* node) {
	if(node && !node->left && !node->right) return node->data;
	int ans = max(node->right);
	return ans;
}

int sum(Node* node) {
	if(!node) return 0;
	return (node->data + sum(node->left) + sum(node->right));		
}

int size(Node* node) {
	if(!node) return 0;
	return (size(node->left) + size(node->right) + 1);
}

bool find(Node* node, int data) {
	if(!node) return false;
	if(node->data > data) return find(node->left,data);
	else if(node->data < data) return find(node->right,data);
	else return true;	
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


Node* construct(vector<int>& arr) {
  Node* root = new Node(arr[0]);
  pair<Node*, int> p = {root, 1};

  stack<pair<Node*, int>> st;
  st.push(p);

  int idx = 1;
  while (!st.empty()) {

    if (st.top().second == 1) {
      st.top().second++;
      if (arr[idx] != -1) {
        st.top().first->left = new Node(arr[idx]);
        pair<Node*, int> lp = {st.top().first->left, 1};
        st.push(lp);
      }
      else {
        st.top().first->left = nullptr;
      }
      idx++;
    }
    else if (st.top().second == 2) {
      st.top().second++;
      if (arr[idx] != -1) {
        st.top().first->right = new Node(arr[idx]);
        pair<Node*, int> rp = {st.top().first->right, 1};
        st.push(rp);
      } else {
        st.top().first->right = nullptr;
      }
      idx++;
    }
    else {
      st.pop();
    }

  }
  return root;
}
