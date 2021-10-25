#include<iostream>
using namespace std;

class Person{
	public:
		int age;
		string name;
		
		void saysHi(){
			cout<<name<<"["<<age<<"]"<<" says: Hi!\n";
		}
};


int main(){
	Person obj1;
	obj1.age = 24;
	obj1.name = "Sanjeev";
	obj1.saysHi();
	
	Person obj2;
	obj2.age = 23;
	obj2.name = "Ayush";
	obj2.saysHi();
	
	Person obj3 = obj1;
	obj3.age = 30;
	obj3.saysHi();
	obj1.saysHi();
	
	return 0;
}
