/*
  367. Valid Perfect Square - Easy

  Given a positive integer num, write a function which returns True if num is a perfect square else False.

  Follow up: Do not use any built-in library function such as sqrt.
*/

class Solution {
public:
    bool isPerfectSquare(int num) {
        bool output = false;
        
        for (long int i = 0; i * i <= num; i++) {
            if (i * i == num) {
                output = true;
            }
        }
        
        return output;
    }
};