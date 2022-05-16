/*
  3. Longest Substring Without Repeating Characters - Medium

  Given a string s, find the length of the longest substring without repeating characters.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s == "") {
            return 0;
        }
        
        int n = s.length();
        unordered_map<char, bool> isInSubstr;
        int start = 0;
        int end = 0;
        int result = 1;
        
        isInSubstr[s[0]] = true;
        isInSubstr[s[0]] = true;
        
        while (end < n - 1) {
            end++;
            
            while (isInSubstr[s[end]]) {
                isInSubstr[s[start]] = false;
                start++;
                
                if (start >= end) {
                    break;
                }
            }
            
            isInSubstr[s[end]] = true;
            result = max(result, end - start + 1);
        }
        
        result = max(result, end - start + 1);
        
        return result;
    }
};