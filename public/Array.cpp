#include <stdio.h>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:

    
    // Single Number
   

    int singleNumber(vector<int>& nums) {

        unordered_map<int,int> mp;

        for(int num : nums) {
            mp[num]++;
        }

        for(auto it : mp) {
            if(it.second == 1)
                return it.first;
        }

        return -1;
    }


  
    // Longest Subarray Sum = K
   

    int longestSubarray(vector<int>& nums, int k) {

        unordered_map<int,int> mp;

        int sum = 0;
        int maxi = 0;

        for(int i = 0; i < nums.size(); i++) {

            sum += nums[i];

            // whole array till i
            if(sum == k)
                maxi = i + 1;

            // remaining part
            if(mp.find(sum - k) != mp.end()) {
                maxi = max(maxi, i - mp[sum - k]);
            }

            if(mp.find(sum) == mp.end()) {
                mp[sum] = i;
            }
        }

        return maxi;
    }


    
    // Two Sum
    
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int,int> mp;

        for(int i = 0; i < nums.size(); i++) {

            int need = target - nums[i];

            if(mp.find(need) != mp.end()) {
                return {mp[need], i};
            }

            mp[nums[i]] = i;
        }

        return {};
    }


    
    // Majority Element (HashMap Approach)
    

    int majorityElementHash(vector<int>& nums) {

        unordered_map<int,int> mp;

        int n = nums.size();

        for(int num : nums) {

            mp[num]++;

            if(mp[num] > n/2)
                return num;
        }

        return -1;
    }


    // Majority Element (Moore Voting Algorithm)
    

    int majorityElementMoore(vector<int>& nums) {

        int cnt = 0;
        int ele;

        for(int num : nums) {

            if(cnt == 0) {
                ele = num;
            }

            if(num == ele)
                cnt++;
            else
                cnt--;
        }

        return ele;
    }
};