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
// rearrange array by sign
vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,0);
        int pos=0, neg=1;
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                ans[neg]=nums[i];
                neg+=2;
            }else{
                ans[pos]=nums[i];
                pos+=2;
            }
        }
        return ans;
        
    };
    // maxSubarray sum

    int maxSubArray(vector<int>& nums) {
         int currSum=nums[0];
         int maxSum=nums[0];
         for(int i=1;i<nums.size();i++){
            currSum=max(nums[i],nums[i]+currSum);
            maxSum=max(maxSum,currSum);
         }
     return maxSum;
         
        
    }
    //sort colors

    void sortColors(vector<int>& nums) {
        int z=0;
        int t=nums.size()-1;
        int i=0;
                    while(i<=t){
                    if(nums[i]==0){
                    swap(nums[i],nums[z]);
                    z++;
                    i++;
                    }else if (
                        nums[i]==1){

                        i++;}
                        
                        else if
                           ( nums[i]==2){
                            swap(nums[i],nums[t]);
                            t--;}
                            
                        }

                    }

  //best time to buy and sell stocks
   int maxProfit(vector<int>& prices) {
        int minimum=prices[0];
        int profit=0;
        for(int i=1;i<prices.size();i++){
            profit=max(profit,prices[i]-minimum);
            minimum=min(minimum,prices[i]);
        }
        return profit;
        
    }                
    //leaders in an array
    vector<int> leaders(vector<int>& arr) {
    vector<int> res;
    int n = arr.size();
    
    for (int i = 0; i < n; i++) {
        int j;

        
        for (j = i + 1; j < n; j++) {

            // If a larger element is found,
            // break the loop
            if (arr[i] < arr[j])
                break;
        }

        
        if (j == n) 
            res.push_back(arr[i]);
    }
    
    return res;
}




