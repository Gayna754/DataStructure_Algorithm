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