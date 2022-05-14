/*
  1413. Minimum Value to Get Positive Step by Step Sum - Easy

  Given an array of integers nums, you start with an initial positive value startValue.

  In each iteration, you calculate the step by step sum of startValue plus elements in nums (from left to right).

  Return the minimum positive value of startValue such that the step by step sum is never less than 1.
*/

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int startValue = 1;
        int sum = startValue;
        bool solutionFound = false;
        bool brokeLoop;
        
        while (!solutionFound) {
            brokeLoop = false;
            
            for (int i = 0; i < nums.size(); i++) {
                sum += nums[i];
                cout << "Sum: " << sum << endl;

                if (sum < 1) {
                    startValue++;
                    sum = startValue;
                    brokeLoop = true;
                    
                    break;
                }
            }
            
            if (brokeLoop) {
                continue;
            }
            
            solutionFound = true;
        }
        
        return startValue;
    }
};