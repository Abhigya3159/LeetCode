/* Problem
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.
Example: Input - nums = [2,7,11,15], target = 9 | Output - [0,1]
*/

//MY SOLUTION
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> vec;
        for (int i = 0; i != nums.size(); ++i){
            int num = nums[i], index = i;
            auto iter = find_if(nums.begin() + (index+1), nums.end(), [target, num](const int &val){return num+val == target;}); 
            if (iter != nums.end()){
                vec.push_back(index);
                vec.push_back(iter - nums.begin());
                break;
            }
        }
        return vec;
    }
};

//FASTER SOLUTION (O(n) time complexity) USING MAP
class Solution {
public:
 vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> mp;
        int n=nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(mp.find(target-nums[i])!= mp.end())
            {
                ans.push_back(i);
                ans.push_back(mp[target-nums[i]]);
            }
            else
                mp[nums[i]]=i;
        }
        return ans;
    }
};
