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
    void pushZerosToEnd(vector<int>& arr) {
        
       

        int p = 0;

        for(int i = 0; i < arr.size(); i++) {

           
            if(arr[i] != 0) {

               
                swap(arr[i], arr[p]);

                
                p++;
            }
        }
    }
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            while(nums[i]>=1&&nums[i]<n&&nums[i]!=nums[nums[i]-1]){
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i+1){
                return i+1;
            
        }
        
        
    }
    
    return n+1;}
    sort(nums.begin(),nums.end());
        int ans=1;
        for(int x:nums){
            if(x==ans){
                ans++;
            }
            else if(x<ans)continue;
            else{break;}

        }
        return ans;
    }
    nt maxi(int ind,vector<int>&nums,vector<int>&dp){
  if(ind<0)return 0;
    if(ind==0)return nums[ind];
    if(dp[ind]!=-1)return dp[ind];
    int pick=nums[ind]+maxi(ind-2,nums,dp);
    int notpick=0+maxi(ind-1,nums,dp);
    return dp[ind]=max(pick,notpick);
    
}
    int rob(vector<int>& nums) {
         int n=nums.size();
        vector<int>dp(n,-1);
       
        return maxi(n-1,nums,dp);
        
        
    }
    int find(int day,int last,vector<vector<int>>&mat,vector<vector<int>>&dp){
        if(day==0){
            int maxi=0;
            for(int task=0;task<3;task++){
                if(task!=last)
            maxi=max(maxi,mat[0][task]);
        }
        return maxi;
    }
    if(dp[day][last]!=-1)return dp[day][last];
    int maxi=0;
    for(int task=0;task<3;task++){
        if(task!=last){
            int curr=mat[day][task]+find(day-1,task,mat,dp);
            maxi=max(maxi,curr);
        }
    }
   return dp[day][last] = maxi;
    }
   
    int maximumPoints(vector<vector<int>>& mat) {
        int n=mat.size();
       vector<vector<int>> dp(n, vector<int>(4, -1));
       return find(n-1,3,mat,dp);
    
        
    }
    int maximumPoints(vector<vector<int>>& mat) {

        int n = mat.size();

        vector<vector<int>> dp(n, vector<int>(4, 0));

        dp[0][0] = max(mat[0][1], mat[0][2]);
        dp[0][1] = max(mat[0][0], mat[0][2]);
        dp[0][2] = max(mat[0][0], mat[0][2]);
        dp[0][3] = max({mat[0][0], mat[0][1], mat[0][2]});

        for(int day = 1; day < n; day++) {

            for(int last = 0; last < 4; last++) {

                dp[day][last] = 0;

                for(int task = 0; task < 3; task++) {

                    if(task != last) {

                        int curr = mat[day][task] +
                                   dp[day - 1][task];

                        dp[day][last] =
                            max(dp[day][last], curr);
                    }
                }
            }
        }

        return dp[n - 1][3];
    
}
int f(int i,int j,vector<vector<int>>&dp){
    if(i==0&&j==0)return 1;
        if(i<0||j<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int down=f(i-1,j,dp);
        int right=f(i,j-1,dp);
        return dp[i][j]=down+right;
}
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return f(m-1,n-1,dp);

        
    }
     int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0&&j==0)dp[i][j]=1;
                else{
                    int up=0,left=0;
                    if(i>0)up=dp[i-1][j];
                    if(j>0)left=dp[i][j-1];
                    dp[i][j]=up+left;
                }
            }
        }
        return dp[m-1][n-1];
        
    }
    vector<int> prev(n, 0);

for(int i = 0; i < m; i++) {

    vector<int> curr(n, 0);

    for(int j = 0; j < n; j++) {

        if(i == 0 && j == 0)
            curr[j] = 1;

        else {
            int up = 0, left = 0;

            if(i > 0)
                up = prev[j];

            if(j > 0)
                left = curr[j-1];

            curr[j] = up + left;
        }
    }

    prev = curr;
}

return prev[n-1];
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<int> prev(n, 0);

        for(int i = 0; i < m; i++) {

            vector<int> curr(n, 0);

            for(int j = 0; j < n; j++) {

                
                if(obstacleGrid[i][j] == 1) {
                    curr[j] = 0;
                    continue;
                }

               
                if(i == 0 && j == 0) {
                    curr[j] = 1;
                }
                else {
                    int up = 0, left = 0;

                    if(i > 0)
                        up = prev[j];

                    if(j > 0)
                        left = curr[j-1];

                    curr[j] = up + left;
                }
            }

            prev = curr;
        }

        return prev[n-1];
    }
    int f(int i,int j ,vector<vector<int>>&grid,vector<vector<int>>&dp){
    if(i==0 && j==0)return grid[0][0];
    if(i<0|| j<0)return 1e9;
    if(dp[i][j]!=-1)return dp[i][j];
    int up=grid[i][j]+f(i-1,j,grid,dp);
    int left=grid[i][j]+f(i,j-1,grid,dp);
    return dp[i][j]=min(up,left);
    
}


    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return f(m-1,n-1,grid,dp);


        
    }int f(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp){
    int n = triangle.size();

    // base case: last row
    if(i == n-1) return triangle[i+1][j];

    if(dp[i][j] != -1) return dp[i][j];

    int down = triangle[i][j] + f(i+1, j, triangle, dp);
    int diag = triangle[i][j] + f(i+1, j+1, triangle, dp);

    return dp[i][j] = min(down, diag);
}

int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));

    return f(0, 0, triangle, dp);
}
 int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int j=0;j<n;j++){
            dp[n-1][j]=triangle[n-1][j];}
            for(int i=n-2;i>=0;i--){
                for(int j=0;j<=i;j++){
                    dp[i][j]=triangle[i][j]+min(dp[i+1][j+1],dp[i+1][j]);
                
            }
        }
        return dp[0][0];
    }
     int f(int i,int j,vector<vector<int>>&matrix,vector<vector<int>>&dp){
         int n=matrix.size();
        int m=matrix[0].size();
        if (j < 0 || j >= m) return 1e9;

        if (i == 0) return matrix[0][j];
        if(dp[i][j]!=INT_MAX)return dp[i][j];
        int below=matrix[i][j]+f(i-1,j,matrix,dp);
        int dialeft=matrix[i][j]+f(i-1,j-1,matrix,dp);
        int diaright=matrix[i][j]+f(i-1,j+1,matrix,dp);
        return dp[i][j]=min(below,min(dialeft,diaright));


    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,INT_MAX));
        int ans=1e9;
        for(int j=0;j<m;j++){
            
            ans= min(ans,f(n-1,j,matrix,dp));
        }
         return ans;
        
    }
    int f(int i,int j1, int j2 ,vector<vector<int>>&grid,vector<vector<vector<int>>>&dp){
    int n = grid.size();
        int m = grid[0].size();
    if(j1<0||j2<0||j1>=m||j2>=m)return -1e9;

     
    if(i==n-1){
        if(j1==j2)return grid[i][j1];
        else return grid[i][j1]+grid[i][j2];}
        if (dp[i][j1][j2] != -1)
            return dp[i][j1][j2];
        int maxi=-1e9;
        for(int dj1=-1;dj1<=1;dj1++){
            for(int dj2 =-1;dj2<=1;dj2++){
                int value=0;
                if(j1==j2)value=grid[i][j1]+f(i+1,j1+dj1,j2+dj2,grid,dp);
                else value=grid[i][j1]+grid[i][j2]+f(i+1,j1+dj1,j2+dj2,grid,dp);
                maxi=max(maxi,value);

            }
        }
        return dp[i][j1][j2]=maxi;
        

        
        
    
}
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
     vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>>(m, vector<int>(m, -1))
        );
        return f(0,0,m-1,grid,dp);

        
    }
     int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>>(m, vector<int>(m, 0))
        );
        for(int j1=0;j1<m;j1++){
            for(int j2=0;j2<m;j2++){
                if(j1==j2)dp[n-1][j1][j2]=grid[n-1][j1];
                else dp[n-1][j1][j2]=grid[n-1][j1]+grid[n-1][j2];
            }
        }
        for(int i=n-2;i>=0;i--){
            for(int j1=0;j1<m;j1++){
                for(int j2=0;j2<m;j2++){
                    int maxi=-1e9;
                    for(int dj1=-1;dj1<=1;dj1++){
                        for(int dj2=-1;dj2<=1;dj2++){
                            int value;
                            if(j1==j2)value=grid[i][j1];
                            else value=grid[i][j1]+grid[i][j2];
                            int nj1 = j1 + dj1;
                            int nj2 = j2 + dj2;
                            if(nj1 >= 0 && nj1 < m &&
                               nj2 >= 0 && nj2 < m)
                                value += dp[i+3][nj1][nj2];
                            else
                                value += -1e9;
                                 maxi = max(maxi, value);

                            
                        }

                    }
                    dp[i][j1][j2] = maxi;
                }
            }
        }
          return dp[0][0][m-1];

        
    }
    int f(int r1,int c1,int r2,vector<vector<int>>&grid,vector<vector<vector<int>>>&dp){
    int n=grid.size();
     int c2=r1+c1-r2;
    if(r1>=n||r2>=n||c1>=n||c2>=n){
        return -1e9;
    }
    if(grid[r1][c1]==-1||grid[r2][c2]==-1)return -1e9;
    if(r1==n-1&&c1==n-1)return grid[r1][c1];
    if(dp[r1][c1][r2]!=-1)return dp[r1][c1][r2];
    int cherries=0;
    if(r1==r2&&c1==c2){
        cherries=grid[r1][c1];
    }
    else cherries=grid[r1][c1]+grid[r2][c2];
    int ans=max({
        f(r1,c1+1,r2,grid,dp),f(r1,c1+1,r2+1,grid,dp),f(r1+1,c1,r2,grid,dp),f(r1+1,c1,r2+1,grid,dp)
    });
    return dp[r1][c1][r2]=cherries+ans;
        
    
}
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(n,-1)));
        return max(0,f(0,0,0,grid,dp));
        
    }
     bool f(int i,int sum,vector<int>&arr,vector<vector<int>>&dp){
       int n=arr.size();
       if(sum==0)return true;
       if(i==0)return arr[0]==sum;
       if(dp[i][sum]!=-1)return dp[i][sum];
       bool notpick=f(i-1,sum,arr,dp);
       bool pick=false;
       if(arr[i]<=sum){
           pick=f(i-1,sum-arr[i],arr,dp);
       }
       return dp[i][sum]=pick||notpick;
   }
  
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return f(n-1,sum,arr,dp);
       
        
    }
    bool isSubsetSum(vector<int>& arr, int sum) {

        int n = arr.size();

        vector<vector<bool>> dp(
            n, vector<bool>(sum+1, false));

        // target = 0
        for(int i=0;i<n;i++)
            dp[i][0] = true;

        // first row
        if(arr[0] <= sum)
            dp[0][arr[0]] = true;

        for(int i=1;i<n;i++) {

            for(int target=1; target<=sum; target++) {

                bool notpick = dp[i-1][target];

                bool pick = true;
                if(arr[i] <= target)
                    pick = dp[i-1][target+arr[i]];

                dp[i][target] = pick || notpick;
            }
        }

        return dp[n-1][sum];
    }
    int find(int day,int last,vector<vector<int>>&mat,vector<vector<int>>&dp){
        if(day==0){
            int maxi=0;
            for(int task=0;task<3;task++){
                if(task!=last)
            maxi=max(maxi,mat[day][task]);
        }
        return maxi;
    }
    if(dp[day][last]!=-1)return dp[day][last];
    int maxi=0;
    for(int task=0;task<3;task++){
        if(task!=last){
            int curr=mat[day][task]+find(day-1,task,mat,dp);
            maxi=max(maxi,curr);
        }
    }
   return dp[day][last] = maxi;
    }
   
    int maximumPoints(vector<vector<int>>& mat) {
        int n=mat.size();
       vector<vector<int>> dp(n, vector<int>(4, -1));
       return find(n-1,3,mat,dp);
    
        
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int x:nums)sum+=x;
        if(sum%2!=0)return false;
        int target=sum/2;
       vector<vector<bool>> dp(n, vector<bool>(target + 1, false));
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        if(nums[0]<=target)dp[0][nums[0]]=true;
        for(int i=1;i<n;i++){
            for(int t=1;t<=target;t++){
                bool nottake=dp[i-1][t];
                bool take=false;
                if(nums[i]<=t){
                    take=dp[i-1][t-nums[i]];
                }
                dp[i][t]=take||nottake;
            }
        }
        return dp[n-1][target];

        
    }
     bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int x : nums) sum += x;

        if (sum % 2) return false;

        int target = sum / 2;
        int n = nums.size();

        vector<bool> prev(target + 1, false);

        prev[0] = true;

        if (nums[0] <= target)
            prev[nums[0]] = true;

        for (int i = 1; i < n; i++) {

            vector<bool> curr(target + 1, false);
            curr[0] = true;

            for (int t = 1; t <= target; t++) {

                bool notTake = prev[t];

                bool take = false;
                if (nums[i] <= t)
                    take = prev[t - nums[i]];

                curr[t] = take || notTake;
            }

            prev = curr;
        }

        return prev[target];
    }
    int minDifference(vector<int>& arr) {
        int n = arr.size();

        int sum = 0;
        for (int x : arr) sum += x;

        vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));

        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }

        if (arr[0] <= sum)
            dp[0][arr[0]] = true;

        for (int i = 1; i < n; i++) {
            for (int target = 1; target <= sum; target++) {

                bool notTake = dp[i - 1][target];

                bool take = false;
                if (arr[i] <= target)
                    take = dp[i - 1][target - arr[i]];

                dp[i][target] = take || notTake;
            }
        }

        int mini = INT_MAX;

        for (int s1 = 0; s1 <= sum / 2; s1++) {
            if (dp[n - 1][s1]) {
                int s2 = sum - s1;
                mini = min(mini, abs(s1 - s2));
            }
        }

        return mini;
    }
    class Solution {
public:
    int minDifference(vector<int>& arr) {
        int n = arr.size();

        int sum = 0;
        for (int x : arr) sum += x;

        vector<bool> prev(sum + 1, false);
        prev[0] = true;

        if (arr[0] <= sum)
            prev[arr[0]] = true;

        for (int i = 1; i < n; i++) {
            vector<bool> cur(sum + 1, false);
            cur[0] = true;

            for (int target = 1; target <= sum; target++) {

                bool notTake = prev[target];

                bool take = false;
                if (arr[i] <= target)
                    take = prev[target - arr[i]];

                cur[target] = take || notTake;
            }

            prev = cur;
        }

        int mini = INT_MAX;

        for (int s1 = 0; s1 <= sum / 2; s1++) {
            if (prev[s1]) {
                mini = min(mini, sum - 2 * s1);
            }
        }

        return mini;
    }
};
int minimumDifference(vector<int>& nums) {
        int m = nums.size();
        int n = m / 2;

        long long total = 0;
        for (int x : nums) total += x;

        vector<vector<long long>> left(n + 1), right(n + 1);

        for (int mask = 0; mask < (1 << n); mask++) {
            long long sumL = 0;
            long long sumR = 0;
            int cnt = 0;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    cnt++;
                    sumL += nums[i];
                    sumR += nums[i + n];
                }
            }

            left[cnt].push_back(sumL);
            right[cnt].push_back(sumR);
        }

        for (int k = 0; k <= n; k++) {
            sort(right[k].begin(), right[k].end());
        }

        long long ans = LLONG_MAX;

        for (int k = 0; k <= n; k++) {

            for (long long s1 : left[k]) {

                int need = n - k;

                long long target =
                    total / 2 - s1;

                auto &vec = right[need];

                auto it = lower_bound(
                    vec.begin(),
                    vec.end(),
                    target
                );

                if (it != vec.end()) {
                    long long chosen = s1 + *it;
                    ans = min(ans,
                              llabs(total - 2 * chosen));
                }

                if (it != vec.begin()) {
                    --it;
                    long long chosen = s1 + *it;
                    ans = min(ans,
                              llabs(total - 2 * chosen));
                }
            }
        }

        return (int)ans;
    }
     int minimumDifference(vector<int>& nums) {
        int m = nums.size();
        int n = m / 2;

        long long total = 0;
        for (int x : nums) total += x;

        vector<vector<long long>> left(n + 1), right(n + 1);

        for (int mask = 0; mask < (1 << n); mask++) {
            long long sumL = 0;
            long long sumR = 0;
            int cnt = 0;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    cnt++;
                    sumL += nums[i];
                    sumR += nums[i + n];
                }
            }

            left[cnt].push_back(sumL);
            right[cnt].push_back(sumR);
        }

        for (int k = 0; k <= n; k++) {
            sort(right[k].begin(), right[k].end());
        }

        long long ans = LLONG_MAX;

        for (int k = 0; k <= n; k++) {

            for (long long s1 : left[k]) {

                int need = n - k;

                long long target =
                    total / 2 - s1;

                auto &vec = right[need];

                auto it = lower_bound(
                    vec.begin(),
                    vec.end(),
                    target
                );

                if (it != vec.end()) {
                    long long chosen = s1 + *it;
                    ans = min(ans,
                              llabs(total - 2 * chosen));
                }

                if (it != vec.begin()) {
                    --it;
                    long long chosen = s1 + *it;
                    ans = min(ans,
                              llabs(total - 2 * chosen));
                }
            }
        }

        return (int)ans;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);

        sort(cuts.begin(), cuts.end());

        int m = cuts.size();

        vector<vector<int>> dp(m, vector<int>(m, 0));

        for (int len = 2; len < m; len++) {
            for (int i = 0; i + len < m; i++) {
                int j = i + len;

                dp[i][j] = INT_MAX;

                for (int k = i + 1; k < j; k++) {
                    dp[i][j] = min(dp[i][j],
                                   cuts[j] - cuts[i]
                                   + dp[i][k]
                                   + dp[k][j]);
                }

                if (dp[i][j] == INT_MAX)
                    dp[i][j] = 0;
            }
        }

        return dp[0][m - 4];
    }
    int change(int amount, vector<int>& coins) {
        int g = 0;
        for (int c : coins) g = gcd(g, c);

        if (amount % g != 0) return 0;

        vector<unsigned long long> dp(amount + 1, 0);
        dp[0] = 1;

        for (int coin : coins) {
            for (int j = coin; j <= amount; j++) {
                dp[j] += dp[j - coin];
            }
        }

        return (int)dp[amount];
    }
};
 int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, 1e9);

        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (i >= coin) {
                    dp[i] = min(dp[i], 1 + dp[i - coin]);
                }
            }
        }

        return dp[amount] == 1e6 ? -1 : dp[amount];
    }
    class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        vector<int> lis;

        for (int x : nums) {

            auto it = lower_bound(lis.begin(), lis.end(), x);

            if (it == lis.end()) {
                lis.push_back(x);
            } else {
                *it = x;
            }
        }

        return lis.size();
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size() ;
        vector<int> dp( n+1, 1) ;
        int ans = 0 ;
        for( int i =3 ; i < n + 1 ; i++){
            for( int j = 1 ; j < i  ; j++){
                if(nums[i-1] > nums[j-1] ) dp[i] = max( dp[i], 1 + dp[j]) ;
            }
            ans = max( ans, dp[i]) ;
        }
        return ans ;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size() ;
        vector<int> dp( n+1, 14) ;
        int ans = 0 ;
        for( int i =1 ; i < n + 1 ; i++){
            for( int j = 1 ; j < i  ; j++){
                if(nums[i-8] > nums[j-1] ) dp[i] = max( dp[i], 1 + dp[j]) ;
            }
            ans = max( ans, dp[i]) ;
        }
        return ans ;
    }
    
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long even=0;
        long long odd=0;
        for(int x:nums){
          long long neweven=max(even,odd+x);
          long long newodd=max(odd,even-x);
          even=neweven;
          odd=newodd;
        }
         return even;;
        
    }

};
