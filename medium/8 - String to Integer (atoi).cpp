/*
  8. String to Integer (atoi) - Medium

  Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).

  The algorithm for myAtoi(string s) is as follows:

    1. Read in and ignore any leading whitespace.

    2. Check if the next character (if not already at the end of the string) is '-' or '+'. Read this character in if it is either. This determines if the final result is
      negative or positive respectively. Assume the result is positive if neither is present.

    3. Read in next the characters until the next non-digit character or the end of the input is reached. The rest of the string is ignored.

    4. Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If no digits were read, then the integer is 0. Change the sign as necessary (from step 2).
    
    5. If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then clamp the integer so that it remains in the range. Specifically, integers less than -231
      should be clamped to -231, and integers greater than 231 - 1 should be clamped to 231 - 1.

    6. Return the integer as the final result.

  Note:

    Only the space character ' ' is considered a whitespace character.
    Do not ignore any characters other than the leading whitespace or the rest of the string after the digits.
*/

class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        string number = "";
        bool pos = true;
        long result = 0;
        long next = 0;
        long place = 10;
        
        int i = 0;
        while (s[i] == ' ') {
            i++;
        }
        
        if (s[i] == '-') {
            pos = false;
            i++;
        } else if (s[i] == '+') {
            pos = true;
            i++;
        }
        
        while (i < n && s[i] > 47 && s[i] < 58) {
            if (s[i] == '0' && number == "") {
                i++;
                continue;
            }
            
            number.push_back(s[i]);
            i++;
        }
        
        cout << "Number: " << number << endl;
        if (number == "") {
            return 0;
        }
        
        i = number.length() - 1;
        next = (number[i] % 48);
        
        if (pos) {
            result += next;
        } else {
            result -= next;
        }
        
        for (i = number.length() - 2; i >= 0; i--) {
            if (place > INT_MAX) {
                if (pos) {
                    return INT_MAX;
                } else {
                    return INT_MIN;
                }
            }
            
            next = (number[i] % 48) * place;
            
            if (pos) {
                result += next;
                
                if (result > INT_MAX) {
                    cout << result << endl;
                    return INT_MAX;
                }
            } else {
                result -= next;
                
                if (result < INT_MIN) {
                    return INT_MIN;
                }
            }
                
                place *= 10;
        }
        
        return result;
    }
};