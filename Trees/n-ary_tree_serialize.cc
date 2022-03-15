#include<bits/stdc++.h>
using namespace std;

struct Node{
	int val;
	vector<Node*> children;
	Node(){}
	Node(int val){ this->val = val;}
	Node(int val, vector<Node*> children){
		this->val = val;
		this->children = children;
	}
};
Node* createTree(vector<string>& nodes);
void display(Node* node);

void serialize(Node* root, vector<string>& preOrder){
	preOrder.push_back(to_string(root->val));
	for(Node* child : root->children) serialize(child,preOrder);
	preOrder.push_back("null");
} 

string serialize(Node* root){
	if(!root) return "";
	
	vector<string> preOrder;
	serialize(root,preOrder);
	
	string hash = "";
	for(string str : preOrder) hash += str + " ";
	return hash;
}

Node* deserialize(string s){
	int n = s.size();
	vector<string> preOrder;
	for(int i=0; i<n; i++){
		string word = "";
		while(i<n && s[i] != ' ') word += s[i++];
		preOrder.push_back(word);
	}
	
	n = preOrder.size();
	stack<Node*> stk;
	 
	for(int i=0; i<n-1; i++){
		string curr = preOrder[i];
		if(curr == "null"){
			Node* node = stk.top();
			stk.pop();
			stk.top()->children.push_back(node);
		}
		else{
			Node* node = new Node(stoi(curr));
			stk.push(node);
		}
	}
	return !stk.empty() ? stk.top() : NULL;
}


int main(){
	int n;
	cin >> n;
	vector<string> nodes(n);
	for(int i=0; i<n; i++) cin >> nodes[i];
	
	Node* root = createTree(nodes);
	display(root);
	
	string hash = serialize(root);
	root = deserialize(hash);
	
	cout << "\n------------------------------------\n";
	display(root);
	

	return 0;
}















Node* createTree(vector<string>& nodes){
	int n = nodes.size();
	stack<Node*> stk;
	for(int i=0; i<n-1; i++){
		if(nodes[i] == "null"){
			Node* node = stk.top();
			stk.pop();
			stk.top()->children.push_back(node);	
		}
		else{
			Node* node = new Node(stoi(nodes[i]));
			stk.push(node);
		}
	}
	return !stk.empty() ? stk.top() : NULL;
}


void display(Node* node){
	if(!node) return;
	
	string str = to_string(node->val) + " -> ";
	for(Node* child : node->children) str += to_string(child->val)+" ";	
	cout << str << "\n";
	for(Node* child : node->children) display(child);
}
