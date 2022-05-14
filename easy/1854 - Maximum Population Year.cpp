/*
  1854. Maximum Population Year - Easy

  You are given a 2D integer array logs where each logs[i] = [birthi, deathi] indicates the birth and death years of the ith person.

  The population of some year x is the number of people alive during that year. The ith person is counted in year x's population if x is in the inclusive range
  [birthi, deathi - 1]. Note that the person is not counted in the year that they die.

  Return the earliest year with the maximum population.
*/

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> years(100, 0);
        
        for (int i = 0; i < logs.size(); i++) {
            for (int j = logs[i][0]; j < logs[i][1]; j++) {
                years[j - 1950]++;
            }
        }
        
        int max_year = 1950;
        int max_year_pop = 0;
        
        for (int i = 0; i < 100; i++) {
            if (years[i] > max_year_pop) {
                max_year_pop = years[i];
                max_year = i + 1950;
            }
        }
        
        return max_year;
    }
};