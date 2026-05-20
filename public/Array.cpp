#include <stdio.h>
#include <vector>
#include <unordered_map>
#include<unordered_set>
#include <algorithm>
using namespace std;

class Solution {


public:

vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int top=0,bottom=n-1,right=m-1,left=0;
        vector<int>arr;
        while(top<=bottom && left<=right){
        for(int i=left;i<=right;i++){
            arr.push_back(matrix[top][i]);
            
        }top++;
        for(int i=top;i<=bottom;i++){
            arr.push_back(matrix[i][right]);
            
        }right--;
        if(top<=bottom){
        for(int i=right;i>=left;i--){
            arr.push_back(matrix[bottom][i]);}
        }bottom--;
        if(left<=right){
        for(int i=bottom;i>=top;i--){
            arr.push_back(matrix[i][left]);}
        }left++;}
        return arr;
        
    }

 void rotate(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++){
            for(int j=i+1;j<matrix[i].size();j++){
                swap(matrix[i][j] , matrix[j][i]);
            }
        }
        for(int i=0;i<matrix.size();i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
        
    }

 int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        int n=nums.size();
        vector<int>pre(n);
        int count=0;
        pre[0]=nums[0];
        mp[pre[0]]++;
        mp[0]++;
        if (pre[0]==k)count++;
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+nums[i];
            if(mp.find(pre[i]-k)!=mp.end()){
                count+=mp[pre[i]-k];
                
            }mp[pre[i]]++;  
        }    
         return count;
        
    }
 void rotate(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++){
            for(int j=i+1;j<matrix[i].size();j++){
                swap(matrix[i][j] , matrix[j][i]);
            }
        }
        for(int i=0;i<matrix.size();i++){
            reverse(matrix[i].begin(),matrix[i].end());
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
// longest consequent subsequence
 int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        int longest=0;
        for(int x:st){
           if( st.find(x-1)==st.end()){
            int curr=x;
            int length=0;
            while(st.find(curr)!=st.end()){
                curr++;
                length++;
            }longest=max(length,longest);
        } }return longest;
        
        
    }
    // next permutation
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int idx=-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                idx=i;
                break;
            }
        }
        if(idx==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i=n-1;i>=idx;i--){
            if(nums[i]>nums[idx]){
                swap(nums[i],nums[idx]);
                break;
            }
        }
        reverse(nums.begin()+idx+1,nums.end());



        
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>row(n,0);
        vector<int>col(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
         if(matrix[i][j]==0){
            row[i]=1; col[j]=1;}

        }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if (row[i]==1|| col[j]==1){
                    matrix[i][j]=0;
                }
            }
        }

          
        
    }

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


     int maxSubArray(vector<int>& nums) {
         int currSum=nums[0];
         int maxSum=nums[0];
         for(int i=1;i<nums.size();i++){
            currSum=max(nums[i],nums[i]+currSum);
            maxSum=max(maxSum,currSum);
         }
     return maxSum;
         
        
    }
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

    // maxSubarray sum

   
    //sort colors

    

  



