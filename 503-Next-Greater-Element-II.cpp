#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i=0;i<n;i++){
            bool found=false;
            for(int index=i+1;index<i+n;index++){
                if(nums[index%n]>nums[i]){  ans[i]=nums[index%n];   found=true; break;  }
            }

            if(!found)  ans[i]=-1;
        }

        return ans;
    }
};

