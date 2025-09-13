// Author : Dhruv sharma
// Date : 12-Sep-2015
// Description : stack using stl


#include<iostream>
#include<stack>
using namespace std;

int main() {
    stack<int> s; //creation of stack
//    push operation
    s.push(2);
   s.push(3);
//    pop operation
    s.pop();
  cout<<"printing top element "<< s.top() <<endl;
if(s.empty()) {
    cout<<"stack is empty"<<endl;
}
else {
   cout<< "stack is not empty"<<endl;
}
cout<<"size of stack is "<<s.size()<<endl;
}
