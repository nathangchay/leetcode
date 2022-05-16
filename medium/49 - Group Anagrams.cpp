/*
  49. Group Anagrams - Medium

  Given an array of strings strs, group the anagrams together. You can return the answer in any order.

  An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, int> charMap;
        int n = strs.size();
        string sortedWord;
        
        for (int i = 0; i < n; i++) {
            sortedWord = strs[i];
            sort(sortedWord.begin(), sortedWord.end());
            
            if (charMap[sortedWord] == 0) {
                vector<string> newGroup = { strs[i] };
                result.push_back(newGroup);
                charMap[sortedWord] = result.size();
            } else {
                result[charMap[sortedWord] - 1].push_back(strs[i]);
            }
        }
        
        return result;
    }
};