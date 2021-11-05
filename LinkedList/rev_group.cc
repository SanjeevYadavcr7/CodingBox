#include<iostream>
using namespace std;
int size = 0;

struct Node{
    int data;
    struct Node* next;
};

struct Node* newNode(int data);
struct Node* addFirst(struct Node* head, int data);
struct Node* insertNode(struct Node* head, int node_data);
struct Node* removeFirst(struct Node* head);
void display(struct Node *node);
void displayReverse(struct Node *node);

struct Node* reverseByK(struct Node* head, int k){
    struct Node *prev = NULL, *curr=head, *new_next;
    int cnt = 0;
    while(curr != NULL && cnt<k){
        new_next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = new_next;
        cnt++;
    }
    if(new_next != NULL)
        head->next = reverseByK(new_next, k);
    return prev;
}



int main(){
    int n,k,x;
    cin>>n;
    Node* head = NULL;
    for(int i=0;i<n;i++){
        cin>>x;
        head = insertNode(head,x);
    }
    display(head);
    displayReverse(head); 
    cin>>k;
    head = reverseByK(head, k);
    display(head);
    return 0;
}













struct Node* newNode(int data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void displayReverse(struct Node *node){
    if(node == NULL){
        cout<<endl;
        return;
    } 
    displayReverse(node->next);
    cout<<node->data<<" ";
}

struct Node* insertNode(struct Node* head, int node_data){  
    struct Node *new_node = newNode(node_data), *ptr = head;
    if(head == NULL){
        size++;
        head = new_node;
        return head;
    }
    while(ptr->next != NULL) ptr = ptr->next;
    ptr->next = new_node;
    size++;
    return head;
}

struct Node* removeFirst(struct Node* head){
    if(head == NULL) return NULL;
    head = head->next;
    return head;
}


struct Node* addFirst(struct Node* head, int data){
    struct Node *new_node = newNode(data);
    if(head == NULL){
        head = new_node;
        return head;
    }
    new_node->next = head;
    head = new_node;
    return head;
}

int getFirst(struct Node* head){
    if(head == NULL) return -1;
    return head->data;
}

void display(struct Node *node){
    if(node == NULL){
        cout<<endl;
        return;
    }
    cout<<node->data<<" ";
    display(node->next);
}