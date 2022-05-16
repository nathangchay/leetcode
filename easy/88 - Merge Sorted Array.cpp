/*
  88. Merge Sorted Array - Easy

  You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2
  respectively.

  Merge nums1 and nums2 into a single array sorted in non-decreasing order.

  The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the
  first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = 0;
        int p2 = 0;
        
        while (nums1.back() == 0 && nums1.size() > m) {
            nums1.pop_back();
            
            if (nums1.size() == 0) {
                nums1 = nums2;
                return;
            }
        }
        
        while (p2 < n) {
            while (p1 < nums1.size() && nums2[p2] > nums1[p1]) {
                p1++;
            }
        
            nums1.insert(nums1.begin() + p1, nums2[p2]);
            p2++;
        }
    }
};