/*
  6. Zigzag Conversion - Medium

  The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

    P   A   H   N
    A P L S I I G
    Y   I   R

  And then read line by line: "PAHNAPLSIIGYIR"

  Write the code that will take a string and make this conversion given a number of rows:

    string convert(string s, int numRows);
*/

class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> lines(numRows, "");
        int n = s.length();
        int curLine = 0;
        bool reverse = false;
        string result = "";
        
        if (numRows == 1) {
            return s;
        }
        
        for (int i = 0; i < n; i++) {
            lines[curLine].push_back(s[i]);
            
            if (curLine == 0) {
                reverse = false;
            } else if (curLine == numRows - 1) {
                reverse = true;
            }
            
            if (reverse) {
                curLine--;
            } else {
                curLine++;
            }
        }
        
        for (int i = 0; i < lines.size(); i++) {
            result += lines[i];
        }
        
        return result;
    }
};