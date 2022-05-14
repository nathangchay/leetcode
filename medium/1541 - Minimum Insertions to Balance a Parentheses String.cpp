/*
  1541. Minimum Insertions to Balance a Parentheses String - Medium

  Given a parentheses string s containing only the characters '(' and ')'. A parentheses string is balanced if:

    Any left parenthesis '(' must have a corresponding two consecutive right parenthesis '))'.
    Left parenthesis '(' must go before the corresponding two consecutive right parenthesis '))'.

  In other words, we treat '(' as an opening parenthesis and '))' as a closing parenthesis.

    For example, "())", "())(())))" and "(())())))" are balanced, ")()", "()))" and "(()))" are not balanced.

  You can insert the characters '(' and ')' at any position of the string to balance it if needed.

  Return the minimum number of insertions needed to make s balanced.
*/

class Solution {
public:
    int minInsertions(string s) {
        vector<char> stack;
        int output = 0;
        int closingCount = 0;
        
        for (int i = 0; i < s.length(); i++) {           
            if (s.at(i) == '(') {
                if (closingCount == 1) {
                    closingCount = 0;
                    
                    if (stack.size() == 0) {
                        output += 2;
                    } else {
                        output++;
                        stack.pop_back();
                    }
                    
                }
                
                stack.push_back('(');
            } else {
                closingCount++;
                
                if (closingCount == 2) {
                    closingCount = 0;
                    
                    if (stack.size() > 0) {
                        stack.pop_back();
                    } else {
                        output++;
                    }
                }
            }
        }
        
        if (closingCount == 1) {
            if (stack.size() > 0) {
                output++;
                stack.pop_back();
            } else {
                output += 2;
            }
        }
        
        output += 2 * stack.size();
        
        return output;
    }
};