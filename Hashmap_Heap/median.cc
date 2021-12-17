#include <iostream>
#include <queue>
using namespace std;

class MedianPriorityQueue {
public:
  priority_queue <int> left;
  priority_queue <int, vector<int>, greater<int>> right;
 
  void push(int val) {
    if(right.empty() || right.top() > val) left.push(val);
    else right.push(val);
    
    int l_size = left.size(), r_size = right.size();
    int len_diff = abs(l_size - r_size);
    if(len_diff > 1){
        if(l_size > r_size){
            int temp_val = left.top();
            left.pop();
            right.push(temp_val);
        }
        else{
            int temp_val = right.top();
            right.pop();
            left.push(temp_val);
        }
    }
  }

  int pop() {
    int med = this->top();
    if(left.size() >= right.size()) left.pop();
    else right.pop();
    return med;
  }

  int top() {
    if(left.size() >= right.size()) return left.top();
    return right.top();
  }

  int size() {
    int n = left.size() + right.size();
    if(n == 0){
        cout<<"Underflow\n";
        n = -1;
    }
    return n;
  }
};

int main() {
  MedianPriorityQueue pq;

  string str;
  cin >> str;
  while (str != "quit") {
    if (str == "add") {
      int val;
      cin >> val;
      pq.push(val);
    }
    else if (str == "remove") {
      int val = pq.pop();
      if (val != -1) {
        cout << val << endl;
      }
    }
    else if (str == "peek") {
      int val = pq.top();
      if (val != -1) {
        cout << val << endl;
      }
    }
    else if (str == "size") {
      cout << pq.size() << endl;
    }
    cin >> str;
  }

  return 0;
}
