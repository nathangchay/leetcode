/*
  7. Reverse Integer - Medium

  Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then
  return 0.

  Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
*/

class Solution {
public:
    int reverse(int x) {
        int result;
        bool neg = false;
        if (x == -2147483648) {
            return 0;
        }
        
        if (x < 0) {
            neg = true;
            x *= -1;
        }
        
        string xString = to_string(x);
        std::reverse(xString.begin(), xString.end());
         
        try {
            result = std::stoi(xString);
            
            if (neg) {
                result *= -1;
            }
        } catch (...) {
            return 0;
        }
        
        return result;
    }
};