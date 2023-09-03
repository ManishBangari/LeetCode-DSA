#include<iostream>
#include<vector>
#include<unordered_map>
#include<string.h>

using namespace std;

class Solution {
public:
    unordered_map<int, int> mark;
    int dp[2001][2001];

    bool solve(vector<int> stones, int n, int index, int prevJump){
        if(index==n-1)   return 1;

        if(dp[index][prevJump]!=-1) return dp[index][prevJump];

        int ans=false;
        for(int nextJump=prevJump-1;nextJump<=prevJump+1;nextJump++){
            if(nextJump>0 && mark.find(stones[index]+nextJump)!=mark.end()){
                ans=ans||solve(stones,n,mark[stones[index]+nextJump],nextJump);
            }
        }

        return dp[index][prevJump]=ans;
    }
    
    bool canCross(vector<int>& stones) {
        int n=stones.size();

        for(int i=0;i<n;i++)    mark[stones[i]]=i;
        
        memset(dp,-1,sizeof(dp));
        return solve(stones,n,0,0);
    }
};

 
    