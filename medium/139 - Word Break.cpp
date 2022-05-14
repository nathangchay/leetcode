/*
  139. Word Break - Medium

  Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

  Note that the same word in the dictionary may be reused multiple times in the segmentation.
*/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool> dictHash;
        int n = s.length();
        vector<bool> dp(n + 1);
        
        dp[0] = true;
        
        for (string word : wordDict) {
            dictHash[word] = true;
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && dictHash[s.substr(j, i - j)]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[n];
    }
};