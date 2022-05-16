/*
  20. Valid Parentheses - Easy

  Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

  An input string is valid if:

    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.
*/

class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                stack.push_back(s[i]);
            } else {
                if (stack.empty()) {
                    return false;
                }
                
                if ((s[i] == ')' && stack.back() == '(') || (s[i] == ']' && stack.back() == '[') || (s[i] == '}' && stack.back() == '{')) {
                    stack.pop_back();
                } else {
                    return false;
                }
            }
        }
        
        return stack.empty();
    }
};