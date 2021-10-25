#include<iostream>
#include<string>
using namespace std;

class customStack{
	public:
		int *data;
		int top;
		int capacity;
		customStack(int cap) {
		  data = new int[cap];
		  capacity = cap;
		  top = -1;
		}

		int size() {
			return top+1;
		}

		void display() {
			for(int i=top;i>=0;i--) cout<<data[i]<<" ";
			cout<<endl;
		}

		void push(int val) {
			if(top+1 == capacity){
				cout<<"Stack overflow\n";
				return;
			}
			top++;
			data[top] = val;
		}

		int pop() {
			top--;
			return top;
		}

		int getTop() {
			return data[top];
		}
};

int main(){
	int n;
	cin>>n;
	customStack obj(n);
	string str;
	getline(cin, str);
	
	while(str != "quit"){

		if(str == "quit") break;
		else if(str[1] == 'u'){
			string temp_num = str.substr(5,2);
			int num = stoi(temp_num);
			obj.push(num);
		}
		else if(str[0] == 'd') obj.display();
		else if(str[0] == 't') cout<<obj.getTop()<<endl;
		else if(str == "pop") obj.pop();
		else cout<<obj.size()<<endl;
		
		getline(cin, str);
	
	}

	return 0;
}
