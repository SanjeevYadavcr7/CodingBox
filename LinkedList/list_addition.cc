#include<iostream>
using namespace std;

struct node{
	int data;
	struct node* next;
};
void display(struct node* ptr);
int getListLength(struct node* ptr);
struct node* new_node(int node_data);
struct node* insert_node(struct node* head, int data);

void add(struct node* head1, struct node* head2, int &carry){
	if(!head1 && !head2) return;
	add(head1->next, head2->next, carry);
	int res = head1->data + head2->data + carry;
	if(res > 9){
		carry = res/10;
		res = res%10;
	}
	else carry = 0;
	head1->data = res;
}

struct node* addList(struct node* head1, struct node* head2){
	int carry = 0;
	int len1 = getListLength(head1);
	int len2 = getListLength(head2);

	if(len1 >= len2){
		int diff = len1-len2, lim=diff;
		struct node* ptr = head1;
		while(diff>0){
			ptr = ptr->next;
			diff--;
		} 
		add(ptr, head2,carry);
		
		int cnt = lim;
		while(carry > 0 && lim > 0){
			struct node* temp = head1;
			while(cnt>1){
				temp = temp->next;
				cnt--;
			} 
			temp->data += carry;
			if(temp->data > 9){
				carry = temp->data/10;
				temp->data %= 10;
			}
			else carry = 0;
			cnt = lim-1;
			lim--;
		}
		if(carry>0){
			struct node* carry_node = new_node(carry);
			carry_node->next = head1;
			head1 = carry_node;
		}
		return head1;
	}
	else{
		int diff = len2-len1, lim=diff;
		struct node* ptr = head2;
		while(diff>0){
			ptr = ptr->next;
			diff--;
		} 
		add(ptr, head1,carry);
		
		int cnt = lim;
		while(carry > 0){
			struct node* temp = head2;
			while(cnt>1){
				temp = temp->next;
				cnt--;
			} 
			temp->data += carry;
			if(temp->data > 9){
				carry = temp->data/10;
				temp->data %= 10;
			}
			else carry = 0;
			cnt = lim-1;
			lim--;
			if(lim == 0) break;
		}
		if(carry>0){
			struct node* carry_node = new_node(carry);
			carry_node->next = head2;
			head2 = carry_node;
		}
		return head2;
	}
	return head1;
}



int main(){
	int n,x;
	cin>>n;
	struct node* head1 = NULL;
	struct node* head2 = NULL;
	for(int i=0;i<n;i++){
		cin>>x;
		head1 = insert_node(head1, x);
	}
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x;
		head2 = insert_node(head2, x);
	}
	head1 = addList(head1, head2);
	display(head1);
	return 0;
}



















void display(struct node* ptr){
	if(ptr == NULL){
		cout<<endl;
		return;
	} 
	cout<<ptr->data<<" ";
	display(ptr->next);
}

struct node* new_node(int node_data){
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = node_data;
	temp->next = NULL;
	return temp;
}


struct node* insert_node(struct node* head, int data){
	struct node* temp = new_node(data);
	if(head == NULL){
		head = temp;
		return head;
	}
	struct node* ptr = head;
	while(ptr->next) ptr = ptr->next;
	ptr->next = temp;
	return head;
}

int getListLength(struct node* ptr){
	int cnt = 0;
	while(ptr != NULL){
		ptr = ptr->next;
		cnt++;
	}
	return cnt;
}




