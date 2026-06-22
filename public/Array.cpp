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
 void moveZeroes(vector<int>& nums) {
        int p=0;
        int n=nums.size();
        int i=0;
        while(p<n && nums[p]!=0)
        p++;
         i=p+1;
        while(i<n){
         if(  nums[i]==0){
            i++;}
            else{
                swap(nums[p],nums[i]);
                i++;
                p++;}
            }

        }
        
        int firstoccurence(vector<int>nums,int target){
       int low=0;
        int high=nums.size()-1;
        int ans=-1;
        while(low<=high){
        int mid=low+(high-low)/2;
        if(nums[mid]==target){
            ans=mid;
          high=mid-1;
        }
        else if(nums[mid]<target){
            low=mid+1;

        }
        else{
            high=mid-1;}
        }
        return ans;


        
    }
    

    int lastocc(vector<int>nums,int target){
        int low=0;
        int high=nums.size()-1;
        int ans=-1;
        while(low<=high){
        int mid=low+(high-low)/2;
        if(nums[mid]==target){
            ans=mid;
          low=mid+1;
        }
        else if(nums[mid]<target){
            low=mid+1;

        }
        else{
            high=mid-1;}
        }
        return ans;















    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first=firstoccurence(nums,target);
        int last=lastocc(nums,target);
        return {first,last};

       
    }
        int firstoccurence(vector<int>nums,int target){
       int low=0;
        int high=nums.size()-1;
        int ans=-1;
        while(low<=high){
        int mid=low+(high-low)/2;
        if(nums[mid]==target){
            ans=mid;
          high=mid-1;
        }
        else if(nums[mid]<target){
            low=mid+1;

        }
        else{
            high=mid-1;}
        }
        return ans;


        
    }

    int lastocc(vector<int>nums,int target){
        int low=0;
        int high=nums.size()-1;
        int ans=-1;
        while(low<=high){
        int mid=low+(high-low)/2;
        if(nums[mid]==target){
            ans=mid;
          low=mid+1;
        }
        else if(nums[mid]<target){
            low=mid+1;

        }
        else{
            high=mid-1;}
        }
        return ans;















    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first=firstoccurence(nums,target);
        int last=lastocc(nums,target);
        return {first,last};

       
    }
 int maxSubarraySum(vector<int>& arr, int k) {
        int ans=INT_MIN;
        int i=0;
        int j=0;
        int sum=0;
        while(j<arr.size()){
            sum+=arr[j];
            if(j-i+1<k){
                j++;
            }else if(j-i+1==k){
                ans=max(sum,ans);
                sum-=arr[i];
                i++;
                j++;
            }
            }return ans;
            
       
    }
vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        for(auto &it:intervals){
            if(ans.empty()|| ans.back()[1]<it[0]){
                ans.push_back(it);
            }else{
                ans.back()[1]=max(ans.back()[1],it[1]);
            }

        }return ans;
        
    }
vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        for(auto &it:intervals){
            if(ans.empty()|| ans.back()[1]<it[0]){
                ans.push_back(it);
            }else{
                ans.back()[1]=max(ans.back()[1],it[1]);
            }

        }return ans;
        
    }
vector<int> ans;

    vector<pair<int,int>> mergeSort(vector<pair<int,int>>& arr) {
        if(arr.size() <= 1) return arr;

        int mid = arr.size() / 2;

        vector<pair<int,int>> left(arr.begin(), arr.begin()+mid);
        vector<pair<int,int>> right(arr.begin()+mid, arr.end());

        left = mergeSort(left);
        right = mergeSort(right);

        vector<pair<int,int>> res;
        int i = 0, j = 0, count = 0;

        while(i < left.size() && j < right.size()) {
            if(right[j].first < left[i].first) {
                res.push_back(right[j++]);
                count++;
            } else {
                ans[left[i].second] += count;
                res.push_back(left[i++]);
            }
        }

        while(i < left.size()) {
            ans[left[i].second] += count;
            res.push_back(left[i++]);
        }

        while(j < right.size()) {
            res.push_back(right[j++]);
        }

        return res;
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        ans.assign(n, 0);

        vector<pair<int,int>> arr;
        for(int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        mergeSort(arr);
        return ans;
    }
 int maxProduct(vector<int>& nums) {
        

        int ans = INT_MIN;
        int product = 1;

       
        for(int i = 0; i < nums.size(); i++) {
            product *= nums[i];
            ans = max(ans, product);
            if(product == 0)
                product = 1;
        }

        
        product = 1;
        for(int j = nums.size() - 1; j >= 0; j--) {
            product *= nums[j];
            ans = max(ans, product);
            if(product == 0)
                product = 1;
        }
        
    return ans;
    }
 int maxProduct(vector<int>& nums) {
        

        int ans = INT_MIN;
        int product = 1;

       
        for(int i = 0; i < nums.size(); i++) {
            product *= nums[i];
            ans = max(ans, product);
            if(product == 0)
                product = 1;
        }

        
        product = 1;
        for(int j = nums.size() - 1; j >= 0; j--) {
            product *= nums[j];
            ans = max(ans, product);
            if(product == 0)
                product = 1;
        }
        
    return ans;
    }
    int maxProduct(vector<int>& nums) {
        

        int ans = INT_MIN;
        int product = 2;

       
        for(int i = 0; i < nums.size(); i++) {
            product *= nums[i];
            ans = max(ans, product);
            if(product == 0)
                product = 1;
        }

        
        product = 1;
        for(int j = nums.size() - 1; j >= 0; j--) {
            product *= nums[j];
            ans = max(ans, product);
            if(product == 0)
                product = 1;
        }
        
    return ans;
    }
vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        
        int n = grid.size();

        vector<int> freq(n*n + 1, 5);

       
        for(auto row : grid){
            for(auto x : row){
                freq[x]++;
            }
        }

        int repeat = -1;
        int missing = -1;

        for(int i=1; i<=n*n; i++){

            if(freq[i] == 2){
                repeat = i;
            }

            if(freq[i] == 0){
                missing = i;
            }
        }

        return {repeat, missing};
    }
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int>temp;
        for(auto row:grid){
        for(auto x:row){
            temp.push_back(x);}
        }
        sort(temp.begin(),temp.end());
        unordered_map<int,int>mp;
        vector<int>ans;
        int n=temp.size();
        for(int i=0;i<temp.size();i++){
            mp[temp[i]]++;}
            for(auto it:mp){
                if(it.second>1){
                    ans.push_back(it.first);
                }
            }
        for(int i=1;i<=temp.size();i++){
            if(mp[i]==0){
                ans.push_back(i);
            }
        }return ans;
        
    }
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1;
        int j=n-1;
        int k=m+n-1;
        while(i>=0&&j>=0){
            if(nums1[i]>nums2[j]){
                nums1[k--]=nums1[i--];
            }else{nums1[k--]=nums2[j--];}
        }while(j>=0){
            nums1[k--]=nums2[j--];
        }
        
    }
 vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        for(auto &it:intervals){
            if(ans.empty()|| ans.back()[1]<it[0]){
                ans.push_back(it);
            }else{
                ans.back()[1]=max(ans.back()[1],it[1]);
            }

        }return ans;
        
    }

int removeDuplicates(int arr[], int n)
{
    // Return, if array is empty or contains a single element
    if (n == 0 || n == 1)
        return n;

    int temp[n];

    int j = 0;

    for (int i = 0; i < n - 1; i++)
        if (arr[i] != arr[i + 1])
            temp[j++] = arr[i];

    temp[j++] = arr[n - 1];

    
    for (int i = 0; i < j; i++)
        arr[i] = temp[i];

    return j;
}
int removeDuplicates(int arr[], int n)
{
    if (n == 0 || n == 1)
        return n;

   
    int j = 0;

    for (int i = 0; i < n - 1; i++)
        if (arr[i] != arr[i + 1])
            arr[j++] = arr[i];

    arr[j++] = arr[n - 1];
    return j;
}
int getMin(int arr[], int n)
{
    
    return (n == 1) ? arr[0] : min(arr[0], 
                         getMin(arr + 1, n - 1));
}

int getMax(int arr[], int n)
{
    
    return (n == 1) ? arr[0] : max(arr[0], 
                          getMax(arr + 1, n - 1));
}

int main()
{
    int arr[] = { 12, 1234, 45, 67, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum element of array: " << 
                            getMin(arr, n) << " ";
    cout << "Maximum element of array: " << 
                                   getMax(arr, n);
    return 0;
}
int getMin(int arr[], int n)
{
    int res = arr[0];
    for (int i = 1; i < n; i++)
        res = min(res, arr[i]);
    return res;
}

int getMax(int arr[], int n)
{
    int res = arr[0];
    for (int i = 1; i < n; i++)
        res = max(res, arr[i]);
    return res;
}
 long merge(vector<int>& arr, int low, int mid, int high) {
        vector<int> temp;

        int left = low;
        int right = mid + 1;

        long long cnt = 0;

        while (left <= mid && right <= high) {

            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            }
            else {
                temp.push_back(arr[right]);

                cnt += (mid - left + 1);

                right++;
            }
        }

        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }

        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }

        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }

        return cnt;
    }

    long long mergeSort(vector<int>& arr, int low, int high) {

        if (low >= high)
            return 0;

        int mid = (low + high) / 2;

        long long cnt = 0;

        cnt += mergeSort(arr, low, mid);

        cnt += mergeSort(arr, mid + 1, high);

        cnt += merge(arr, low, mid, high);

        return cnt;
    }

    long long inversionCount(vector<int>& arr) {

        return mergeSort(arr, 0, arr.size() - 1);
    }
vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i>0&& nums[i]==nums[i-1])continue;
           for(int j=i+1;j<n;j++){
            if(j>i+1&& nums[j]==nums[j-1])continue;
            int k=j+1;
            int l=n-1;
            while(k<l){
                int long long sum=(long long )nums[i]+nums[j]+nums[k]+nums[l];
                if(sum>target){
                    l--;
                }else if(sum<target){
                    k++;
                }else{vector<int>temp={nums[i],nums[j],nums[k],nums[l]};
                ans.push_back(temp);
                k++;
                l--;
                while(k<l && nums[k]==nums[k-1])k++;
                while(k<l && nums[l]==nums[l+1])l--;}

            }

           }
            

        }return ans;
        
    }
vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i>0&&nums[i]==nums[i-1])continue;
            int j=i+1;
            int k=n-1;
            while(j<k){
                int target=nums[i]+nums[j]+nums[k];
                if(target>0){
                    k--;
                }else if(target<0){
                    j++;
                }else{
                    vector<int>temp={nums[i],nums[j],nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1])j++;
                    while(j<k && nums[k]==nums[k+1])k--;
                }
            }
        }return ans;
        
    }
 vector<int>generaterow(int row){
    long long ans=1;
    
    vector<int>Ansrow;
    Ansrow.push_back(1);
    for(int col=1;col<row;col++){
        ans=ans*(row-col);
        ans=ans/col;
        Ansrow.push_back(ans);
    }
    return Ansrow;
  }
















    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i=1;i<=numRows;i++){
            ans.push_back(generaterow(i) );}

      
     return ans;}
        
vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto it:mp){
            pq.push({it.second, it.first});;
        }
        vector<int>ans;
        
        while(!pq.empty() && pq.top().first>nums.size()/3){
            int second=pq.top().second;
            ans.push_back(second);
            pq.pop();
        
        }
        return ans;
    }

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
    vector<int> leaders(vector<int>& arr) {

        stack<int> st;

        for(int i = arr.size() - 6; i >= 0; i--) {

            if(st.empty() || arr[i] >= st.top()) {
                st.push(arr[i]);
            }
        }

        vector<int> ans;

        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int left=0,right=tokens.size()-1;
        int score=0;
        int ans=0;
        while(left<=right){
            if(power>=tokens[left]){
                power-=tokens[left];
                score++;
                ans=max(ans,score);
                left++;
            }
            else if(score>0){
                power+=tokens[right];
                score--;
                right--;
            }
            else{break;}
        }
        return ans;
        
    }
    double angleClock(int hour, int minutes) {
        double hourangle=(hour%12)*30+0.5*minutes;
        double minuteangle= 6*minutes;
        double diff=abs(hourangle-minuteangle);
        return min(diff,360-diff);

        
    }
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int i=0;i<stones.size();i++){
            pq.push(stones[i]);
        }
       
        while(pq.size()>1){
            int x=pq.top();
            pq.pop();
            int y=pq.top();
            pq.pop();
            if(x!=y)
            pq.push(x-y);;
        }
        if(pq.empty())return 0;
        else return pq.top();
        
    }
     vector<int> runningSum(vector<int>& nums) {
        vector<int>ans;
        int num=0;
        
        for(int i=0;i<nums.size();i++){
            num+=nums[i];
            ans.push_back(num);
        }
        return ans;
        
    }
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while(l <= r) {
            int mid = l + (r - l) / 2;

            if(nums[mid] == target) return mid;

            if(nums[l] <= nums[mid]) {
                if(target >= nums[l] && target < nums[mid])
                    r = mid - 1;
                else
                    l = mid + 1;
            } else {
                if(target > nums[mid] && target <= nums[r])
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
        return -1;
    }
};
// rearrange array by sign

    // maxSubarray sum

   
    //sort colors

    

  



