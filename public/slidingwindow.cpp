#include <stdio.h>
#include <vector>
#include <unordered_map>
#include<unordered_set>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
    public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
       
        long long ans=0;
        int i=0,j=1;
        long long sum=0;
        while(j<nums.size()){
            sum+=nums[j];
            mp[nums[j]]++;
            if(j-i+1<k){
                j++;
            }else if(j-i+1==k){
                if(mp.size()==k){
                ans=max(ans,sum);}
            mp[nums[i]]--;
            if(mp[nums[i]]==0){
                mp.erase(nums[i]);
            }
            sum-=nums[i];
            i++;
            j++;}


        }return ans;
        
        
    }
    int search(string &pat, string &txt) {
        unordered_map<int,int>mp;
        for(char ch:pat){
            mp[ch]++;
        }
        int count=mp.size();
        int k=pat.size();
        int i=0,j=0;
        
        int ans=0;
        while(j<txt.size()){
            if(mp.find(txt[j])!=mp.end()){
                mp[txt[j]]--;
            
            if(mp[txt[j]]==0){
                count--;}
            }
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
                if(count==0){
                    ans++;
                }
                if(mp.find(txt[i])!=mp.end()){
                    if(mp[txt[i]]==0){
                        count++;
                    }
                
                mp[txt[i]]++;}
            
            i++;
            j++;}
        }return ans;
        
        
       
        
    }
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {

        vector<int> ans;

        vector<int> freq(101, 0);

        int i = 0;
        int j = 0;

        while (j < nums.size()) {

            // add current element
            freq[nums[j] + 50]++;

            // window not complete
            if (j - i + 1 < k) {
                j++;
            }

            // 
            else {

                int count = 0;
                int beauty = 0;

               
                for (int num = -50; num <= -1; num++) {

                    count += freq[num + 50];

                    if (count >= x) {
                        beauty = num;
                        break;
                    }
                }

                ans.push_back(beauty);

                
                freq[nums[i] + 50]--;

                i++;
                j++;
            }
        }

        return ans;
    }
    vector<int> firstNegInt(vector<int>& arr, int k) {
        int j=0;
        int i=0;
        queue<int>q;
        vector<int>temp;
       
        while(j<arr.size()){
            if(arr[j]<0){
            q.push(arr[j]);
            
        }
        
        if(j-i+1<k){
            j++;
        }else if(j-i+1==k){
            
        
       if (q.empty()){temp.push_back(0);}
       else{temp.push_back(q.front());}
        
        if(!q.empty()&&arr[i]==q.front()){
            q.pop();
            
        }
        i++;
        j++;
        }}
        return temp;
         
         
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



};