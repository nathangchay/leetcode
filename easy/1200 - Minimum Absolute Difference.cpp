/*
  1200. Minimum Absolute Difference - Easy

  Given an array of distinct integers arr, find all pairs of elements with the minimum absolute difference of any two elements.

  Return a list of pairs in ascending order(with respect to pairs), each pair [a, b] follows

    a, b are from arr
    a < b
    b - a equals to the minimum absolute difference of any two elements in arr
*/

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> out;
        int minDiff;
        
        sort(arr.begin(), arr.end());
        
        minDiff = (arr[1] - arr[0]);
        out.push_back({arr[0], arr[1]});
        
        for (int i = 2; i < arr.size(); i++) {
            if (arr[i] - arr[i - 1] == minDiff) {
                out.push_back({arr[i - 1], arr[i]});
            } else if (arr[i] - arr[i - 1] < minDiff) {
                minDiff = (arr[i] - arr[i - 1]);
                out.clear();
                out.push_back({arr[i - 1], arr[i]});        
            }
        }

        return out;
    }
};