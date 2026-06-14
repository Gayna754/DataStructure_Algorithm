#include <stdio.h>
#include <vector>
#include <unordered_map>
#include<unordered_set>
#include <algorithm>
#include <queue>
#include <iostream>
#include<stack>
using namespace std;
class Solution {
public:

    int climbStairs(int n) {
        if (n <= 2) return n;

        int prev2 = 1;
        int prev1 = 3;

        for (int step = 3; step <= n; step++) {
            int current = prev1 + prev2;
            prev2 = prev1;
            prev1 = current;
        }

        return prev2;
    }
    vector<int> dailyTemperatures(vector<int>& temperatures) {
       int n=temperatures.size();
        vector<int>ans(n,0);
        stack<int>st;
       
        
        for(int i=0;i<n;i++){
           
            
            while(!st.empty()&&temperatures[st.top()]<temperatures[i]){
            int idx=st.top();
                st.pop();
                ans[idx]=i-idx;}
            
            st.push(i);
        }
        return ans;
        
    }
     int minCost(vector<int>& height) {
        int n = height.size();

        int prev2 = 0; 
        int prev1 = 0; 

        for (int i = 1; i < n; i++) {
            int oneStep = prev1 + abs(height[i] - height[i - 1]);

            int twoStep=INT_MAX;
              if (i>1)
              
               int twoStep = prev2 + abs(height[i] - height[i - 2]);

            int curr = min(oneStep, twoStep);

            prev2 = prev1;
            prev1 = curr    ;
        }

        return prev1
        
        ;

    }
    int f(int ind,vector<int>&height,vector<int>&dp){
      if(ind==0)return 0;
      if(dp[ind]!=-1)return dp[ind];
      int left=f(ind-1,height,dp)+abs(height[ind]-height[ind-1]);
      int right=INT_MAX;
      if(ind>1) right=f(ind-2,height,dp)+abs(height[ind]-height[ind-2]);
      return dp[ind]=min(left,right);
      
      
  }
  int minCost(vector<int>& height) {
        int n=height.size();
        vector<int>dp(n+1,-1);
        return f(n-1,height,dp);
        
        
    }
     int maxJump(vector<int>& stones) {
        int ans = stones[1] - stones[0];

        for (int i = 2; i < stones.size(); i++) {
            ans = max(ans, stones[i] - stones[i - 2]);
        }

        return ans;
    }
     int maxi(int ind,vector<int>&arr,vector<int>&dp){
       if(ind==0)return arr[ind];
       if(ind<1)return 0;
       if(dp[ind]!=-1)return dp[ind];
       int pick=arr[ind]+maxi(ind-2,arr,dp);
       int nonpick=0+maxi(ind-1,arr,dp);
       return max(pick,nonpick);
   }
   
    int findMaxSum(vector<int>& arr, int n) {
        vector<int>dp(n,-1);
        return maxi(n-1,arr,dp);
    }
     int findMaxSum(vector<int>& arr, int n) {
        int prev=arr[0];
        int prev2=0;
        for(int i=1;i<n;i++){
            int pick=arr[i];
            if(i>1)pick+=prev2;
            int notpick=0+prev;
            int curr=max(pick,notpick);
            prev2=prev;
            prev=curr;
           
        }
    
        return prev;}
        int findMaxSum(vector<int>& nums) {
        int prev=nums[0];
        int prev2=0;
        int n=nums.size();
        for(int i=1;i<n;i++){
            int pick=nums[i];
            if(i>1)pick+=prev2;
            int notpick=0+prev;
            int curr=max(pick,notpick);
            prev2=prev;
            prev=curr;
           
        }
    
        return prev;}
        int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp1;
        vector<int>temp2;
        if(n==1)return nums[0];
        for(int i=0;i<nums.size();i++){
            if(i!=0)temp1.push_back(nums[i]);
            if(i!=n-1)temp2.push_back(nums[i]);
            


        }
        return max(findMaxSum(temp1),findMaxSum(temp2));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        dp[0][0] = grid[0][0];

      
        for (int j = 1; j < n; j++)
            dp[0][j] = dp[0][j - 1] + grid[0][j];

        for (int i = 1; i < m; i++)
            dp[i][0] = dp[i - 1][0] + grid[i][0];

        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = grid[i][j] +
                           min(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[m - 1][n - 1];
    }
};