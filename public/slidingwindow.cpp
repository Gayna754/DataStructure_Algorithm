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
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {

        vector<int> ans;

        // frequency array for -50 to 50
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

            // window size = k
            else {

                int count = 0;
                int beauty = 0;

                // check only negative numbers
                for (int num = -50; num <= -1; num++) {

                    count += freq[num + 50];

                    if (count >= x) {
                        beauty = num;
                        break;
                    }
                }

                ans.push_back(beauty);

                // remove left element
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



};