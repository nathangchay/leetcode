/*
  22. Generate Parentheses - Medium

  Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result = {"()"};
        string newCombination;
        vector<string> newResult;
        
        if (n == 1) {
            return result;
        }
        
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < result.size(); j++) {
                for (int k = 0; k < result[j].length(); k++) {
                    newCombination = result[j];
                    newCombination.insert(k, "()");
                    
                    if (find(newResult.begin(), newResult.end(), newCombination) == newResult.end()) {
                        newResult.push_back(newCombination);
                    }
                }
            }
            
            result = newResult;
            newResult.clear();
        }
        
        return result;
    }
};