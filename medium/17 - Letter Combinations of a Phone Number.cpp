/*
  17. Letter Combinations of a Phone Number - Medium

  Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

  A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

  https://upload.wikimedia.org/wikipedia/commons/thumb/7/73/Telephone-keypad2.svg/200px-Telephone-keypad2.svg.png
*/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, vector<string>> hash;
        vector<string> result;
        vector<string> resultNew;
        int n = digits.length();
        
        hash['2'] = {"a", "b", "c"};
        hash['3'] = {"d", "e", "f"};
        hash['4'] = {"g", "h", "i"};
        hash['5'] = {"j", "k", "l"};
        hash['6'] = {"m", "n", "o"};
        hash['7'] = {"p", "q", "r", "s"};
        hash['8'] = {"t", "u", "v"};
        hash['9'] = {"w", "x", "y", "z"};
        
        for (int i = 0; i < hash[digits[0]].size(); i++) {
            result.push_back(hash[digits[0]][i]);
        }
        
        cout << digits[0];
        
        for (int i = 1; i < n; i++) {
            resultNew.clear();
            
            for (int j = 0; j < result.size(); j++) {
                for (int k = 0; k < hash[digits[i]].size(); k++) {
                    resultNew.push_back(result[j] + hash[digits[i]][k]);
                }
            }
            
            result = resultNew;
        }
        
        return result;
    }
};