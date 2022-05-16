/*
  4. Median of Two Sorted Arrays - Hard

  Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

  The overall run time complexity should be O(log (m+n)).
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> merged(n + m);
        double result = 0;
        
        int i = 0;
        int j = 0;
        int k = 0;
        while (i < m || j < n) {
            if (i < m && j < n) {
                if (nums1[i] <= nums2[j]) {
                    merged[k] = nums1[i];
                    i++;
                } else {
                    merged[k] = nums2[j];
                    j++;
                }
            } else if (i < m) {
                merged[k] = nums1[i];
                i++;
            } else {
                merged[k] = nums2[j];
                j++;
            }
            
            k++;
        }
        
        if ((m + n) % 2 == 1) {
            result = merged[(m + n) / 2];
        } else {
            result = (double) (merged[(m + n) / 2] + merged[((m + n) / 2) - 1]) / 2;
        }
        
        return result;
    }
};