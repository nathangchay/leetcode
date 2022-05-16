/*
  38. Count and Say - Medium

  The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

    countAndSay(1) = "1"
    countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), which is then converted into a different digit string.

  To determine how you "say" a digit string, split it into the minimal number of groups so that each group is a contiguous section all of the same character. Then for each group, say the number of characters, then say the character. To convert the saying into a digit string, replace the counts with a number and concatenate every saying.

  For example, the saying and conversion for digit string "3322251":

  Given a positive integer n, return the nth term of the count-and-say sequence.
*/

class Solution {
public:
    string countAndSay(int n) {
        vector<string> countAndSayHistory(n + 1);
        countAndSayHistory[1] = "1";
        char cur;
        int count;
        
        for (int i = 2; i <= n; i++) {
            cur = countAndSayHistory[i - 1][0];
            count = 1;
            
            for (int j = 1; j < countAndSayHistory[i - 1].length(); j++) {
                if (countAndSayHistory[i - 1][j] == cur) {
                    count++;
                } else {
                    countAndSayHistory[i].push_back('0' + count);
                    countAndSayHistory[i].push_back(cur);
                    cur = countAndSayHistory[i - 1][j];
                    count = 1;
                }
            }
            
            countAndSayHistory[i].push_back('0' + count);
            countAndSayHistory[i].push_back(cur);
        }
        
        return countAndSayHistory[n];
    }
};