/*
  1400. Construct K Palindrome Strings - Medium

  Given a string s and an integer k, return true if you can use all the characters in s to construct k palindrome strings or false otherwise.
*/

class Solution {
public:
    bool canConstruct(string s, int k) {
        map<char, int> charCount;
        int oddCounts = 0;
        
        if (s.length() < k) {
            return false;
        }
        
        for (int i = 0; i < s.length(); i++) {
            charCount[s[i]]++;
            
            if (charCount[s[i]] % 2 == 1) {
                oddCounts++;
            } else {
                oddCounts--;
            }
        }
        
        if (oddCounts > k) {
            return false;
        }
        
        return true;
    }
};