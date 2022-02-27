#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


Node* cloneGraph(Node* node) {
	if(!node) return NULL;
	
	if(!mp[node]){
		mp[node] = new Node(node->val,{});
		for(auto adj : node->neighbors)
			mp[node]->neighbors.push_back(cloneGraph(adj));
	}
	return mp[node];
}