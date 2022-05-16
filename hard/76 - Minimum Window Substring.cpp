/*
  76. Minimum Window Substring - Hard

  Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the
  window. If there is no such substring, return the empty string "".

  The testcases will be generated such that the answer is unique.

  A substring is a contiguous sequence of characters within the string.
*/

class Solution {
public:
    string minWindow(string s, string t) {
        string result = "";
        string window;
        int resultLength = INT_MAX;
        unordered_map<char, int> count;
        unordered_map<char, int> expected;
        bool hasAll;
        int left = 0;
        int right = 0;
        int n = s.length();
        
        for (char c: t) {
            expected[c]++;
        }
        cout << endl;
        
        while (left <= n && right <= n) {
            hasAll = true;
            
            unordered_map<char, int>::iterator it;
            for (it = expected.begin(); it != expected.end(); it++) {
                if (count[it->first] < it->second) {
                    hasAll = false;
                    break;
                }
            }
            
            if (hasAll) {
                window = s.substr(left, right - left);
                if (window.length() < resultLength) {
                    result = window;
                    resultLength = window.length();
                }
                
                count[s[left]]--;
                left++;
            } else {
                count[s[right]]++;
                right++;
            }
        }
        
        return result;
    }
};