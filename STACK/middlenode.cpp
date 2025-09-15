/* Author : Dhruv Sharma
Date : 15-Sep-2025
Description :  Delete middle element from stack 
Example :-
INPUT : ARR [ ] = [ 1 , 2 , 3 , 4 , 5 ] , N = 4
OUTPUT: ARR [ ] = [ 1 , 2 , 4,  5 ] */


#include <bits/stdc++.h> 

void solve(stack<int>&inputStack,int count, int N) {
// base case
if(count == N/2) {
 inputStack.pop();
 return;
}   
// restore top element
int num = inputStack.top();
inputStack.pop();
// recurive call
solve(inputStack, count+1, N);
// put element back in stack 
inputStack.push(num);

}

void deleteMiddle(stack<int>&inputStack, int N){
int count = 0;
solve(inputStack, count, N);	
 
   
}
