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