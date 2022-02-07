#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int _data){
        data = _data;
        left = right = NULL;
    }
};

vector<int> postOrder(Node* node) {
    vector<int> post_order;
    stack<pair<Node*,int>> stk;
    stk.push({node,0});
    
    while(!stk.empty()){
        auto it = stk.top();
        int state = it.second;
        Node* curr_node = it.first;
        if(state == 0){
            stk.top().second = 1;
            if(curr_node->left) stk.push({curr_node->left,0});
        }
        else if(state == 1){
            stk.top().second = 2;
            if(curr_node->right) stk.push({curr_node->right,0});
        }
        else {
            post_order.push_back(it.first->data);
            stk.pop();
        }
    }
    return post_order;
}

int main(){
    Node* root = new Node(8);
    root->left = new Node(1);
    root->left->right = new Node(7);
    root->left->right->right = new Node(10);
    root->right = new Node(5);
    root->right->left = new Node(10);
    root->right->left->left = new Node(6);
    root->right->right = new Node(6);


    vector<int> post_order = postOrder(root);
    for(int &i : post_order) cout << i << " ";
    cout << "\n";

    return 0;
}