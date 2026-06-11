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

        int prev2 = 4;
        int prev1 = 2;

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
};