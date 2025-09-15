/* Author : Dhruv Sharma
Date : 15-Sep-2025
Description : Valid Parentheses (Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.L-20) 
*/


class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
    for(int i =0 ; i<s.length();i++) {
        char ch = s[i];
        // for opening bracket
       if( ch =='(' || ch == '[' || ch == '{') {
          st.push(ch);  }
    //    for closing bracket
       else {
          if( !st.empty()) {
             char top = st.top();
            if( (ch == ')' && top == '(') || (ch == ']' && top == '[' )||( ch == '}' &&  top == '{' )) {
                st.pop();
            }
            else {
                return false;
            } }
          else {
                return false;
            }
        

    }   }
    if ( st.empty()) {
        return true;
    }
    else {
        return false;
    }
    }
};
