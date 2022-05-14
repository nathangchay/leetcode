/*
  264. Ugly Number II - Medium

  An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

  Given an integer n, return the nth ugly number.
*/

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> uglyNumbers;
        uglyNumbers.push_back(1);
        int next = 0;
        
        int L1 = 0;
        int L2 = 0;
        int L3 = 0;
        
        for (int i = 1; i < n; i++) {
            next = min(uglyNumbers[L1] * 2, uglyNumbers[L2] * 3);
            next = min(next, uglyNumbers[L3] * 5);
            
            // cout << i + 1 << ": " << next << endl;
            // cout << "L1: " << L1 << " L2: " << L2 << " L3: " << L3 << endl;
            
            if (next == uglyNumbers[L1] * 2) {
                L1++;
            }
            
            if (next == uglyNumbers[L2] * 3) {
                L2++;
            }
            
            if (next == uglyNumbers[L3] * 5) {
                L3++;
            }
            
            uglyNumbers.push_back(next);
        }
        
        return uglyNumbers[n - 1];
    }
};