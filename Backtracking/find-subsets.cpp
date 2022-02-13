/*
Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.
*/

class Solution {
public:
    void find_set(vector<int>& nums, int i, vector<int> sset, vector<vector<int>>& pset) {
        if(i == nums.size()) {
            pset.push_back(sset);
            return;
        }
        
        find_set(nums, i + 1, sset, pset);
        sset.push_back(nums[i]);
        find_set(nums, i + 1, sset, pset);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> pset;
        vector<int> sset;
        
        find_set(nums, 0, sset, pset);
        return pset;
    }
};
