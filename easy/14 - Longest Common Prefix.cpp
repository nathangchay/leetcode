/*
  14. Longest Common Prefix - Easy

  Write a function to find the longest common prefix string amongst an array of strings.

  If there is no common prefix, return an empty string "".
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = strs[0];
        int length = strs[0].length();
        int p1 = 0;
        int p2 = 0;
        
        for (int i = 1; i < strs.size(); i++) {
            p1 = 0;
            p2 = 0;
            
            if (result[p1] != strs[i][p2]) {
                return "";
            }
            
            while (p1 < result.length() && p2 < strs[i].length() && result[p1] == strs[i][p2]) {
                p1++;
                p2++;
            }
            
            result = result.substr(0, p1);
        }
        
        return result;
    }
};