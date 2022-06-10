/*
  9. Palindrome Number - Easy

  Given an integer x, return true if x is palindrome integer.

  An integer is a palindrome when it reads the same backward as forward.

    For example, 121 is a palindrome while 123 is not.
*/

class Solution {
public:
    bool isPalindrome(int x) {
        string str_x = to_string(x);
        string str_x_rev = to_string(x);
        
        reverse(str_x_rev.begin(), str_x_rev.end());
        
        return (str_x == str_x_rev);
    }
};