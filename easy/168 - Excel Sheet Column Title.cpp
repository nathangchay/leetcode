/*
  168. Excel Sheet Column Title - Easy

  Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.

  For example:
    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
    ...
*/

class Solution {
public:
    string getLetter(int num) {
        string key[26] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
        
        return key[num];
    }
    
    string convertToTitle(int columnNumber) {
        string title = "";
        
        while (columnNumber > 0) {
            columnNumber -= 1;
            
            title = getLetter(columnNumber % 26) + title;
            
            columnNumber = columnNumber / 26;
        }
        
        return title;
    }
};