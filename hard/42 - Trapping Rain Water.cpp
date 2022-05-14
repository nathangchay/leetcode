/*
  42. Trapping Rain Water - Hard

  Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int result = 0;
        int maxLeft = 0;
        int maxRight = 0;
        
        int left = 0;
        int right = n - 1;
        while (left <= right) {
            if (height[left] <= height[right]) {
                if (height[left] >= maxLeft) {
                    maxLeft = height[left];
                } else {
                    result += maxLeft - height[left];
                    // cout << "Added " << maxLeft - height[left] << " from left" << endl;
                }
                
                left++;
            } else {
                if (height[right] >= maxRight) {
                    maxRight = height[right];
                } else {
                    result += maxRight - height[right];
                    // cout << "Added " << maxRight - height[right] << " from right" << endl;
                }
                
                right--;
            }
        }
        
        return result;
    }
};